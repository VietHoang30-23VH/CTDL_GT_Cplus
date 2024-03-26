#include <iostream>
#include <string.h>


using namespace std;

// Cấu trúc của một node
struct node {
    int info;
    node* next;
};

// Cấu trúc của một Stack
struct Stack {
    node* head;
    node* tail;
};

void CreateEmptyStack(Stack& l) {
    l.head = NULL;
    l.tail = NULL;
}

node* CreateNode(int x) {
    node* p = new node();
    if (p == NULL)
        exit(1);
    p->info = x;
    p->next = NULL;
    return p;
}
bool checkTrung(Stack a, int x) {
    node* p = a.head;
    while (p != NULL) {
        if (p->info == x)
            return true;
        p = p->next;
    }
    return false;
}

void AddHead(Stack& L, node* p) {
    if (L.head == NULL)
        L.head = L.tail = p;
    else {
        p->next = L.head;
        L.head = p;
    }
}

void PrintStack(Stack L) {
    if (L.head == NULL)
        cout << "NO SNT" << endl;
    else {
        Stack a;
        CreateEmptyStack(a);
        while (L.head != NULL) {
            if (!checkTrung(a, L.head->info)) {
                AddHead(a, CreateNode(L.head->info));
                cout << L.head->info << " ";
            }
            L.head = L.head->next;
        }
    }
}
int main() {
   
    Stack L;
    CreateEmptyStack(L);
    CreateStack(L);
    PrintStack(L);

    return 0;
}