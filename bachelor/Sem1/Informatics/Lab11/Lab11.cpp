#include <iostream>
#include <fstream>
#include <windows.h>

using namespace std;

struct Node {
    int key;
    Node* prev;
    Node* next;
};

Node* createList(int n) {
    Node* first = NULL;
    for (int i = n; i >= 1; i--) {
        Node* p = new Node{i, NULL, first};
        if (first != NULL) first->prev = p;
        first = p;
    }
    return first;
}

void printList(Node* first) {
    if (first == NULL) {
        cout << "Список пустой" << endl;
        return;
    }
    for (Node* p = first; p != NULL; p = p->next)
        cout << p->key << " ";
    cout << endl;
}

void deleteAfter(Node* first, int pos) {
    Node* p = first;
    for (int i = 1; i < pos && p != NULL; i++)
        p = p->next;
    if (p == NULL || p->next == NULL) return;
    Node* del = p->next;
    p->next = del->next;
    if (del->next != NULL) del->next->prev = p;
    delete del;
}

Node* addFrontK(Node* first, int k) {
    for (int i = 0; i < k; i++) {
        int val;
        cout << "Введите элемент: ";
        cin >> val;
        Node* p = new Node{val, NULL, first};
        if (first != NULL) first->prev = p;
        first = p;
    }
    return first;
}

void saveToFile(Node* first, const char* fname) {
    ofstream f(fname);
    for (Node* p = first; p != NULL; p = p->next)
        f << p->key << " ";
    f.close();
}

Node* clearList(Node* first) {
    while (first != NULL) {
        Node* temp = first;
        first = first->next;
        delete temp;
    }
    return NULL;
}

Node* loadFromFile(const char* fname) {
    ifstream f(fname);
    Node *first = NULL, *last = NULL;
    int val;
    while (f >> val) {
        Node* p = new Node{val, last, NULL};
        if (first == NULL) first = p;
        else last->next = p;
        last = p;
    }
    f.close();
    return first;
}

int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    Node* list = createList(5);
    cout << "Исходный список: ";
    printList(list);

    int pos;
    cout << "Удалить элемент после номера: ";
    cin >> pos;
    deleteAfter(list, pos);
    cout << "После удаления: ";
    printList(list);

    int k;
    cout << "Сколько элементов добавить в начало (K): ";
    cin >> k;
    list = addFrontK(list, k);
    cout << "После добавления: ";
    printList(list);

    saveToFile(list, "list.txt");
    list = clearList(list);
    cout << "После очистки: ";
    printList(list);

    list = loadFromFile("list.txt");
    cout << "Восстановленный список: ";
    printList(list);

    list = clearList(list);
    return 0;
}