#include <iostream>
#include <cstdio>
using namespace std;

struct Node{
    int data;
    Node* next;
};

struct Stack {
    Node* top;
};

void khoiTao(Stack* s) {
    s->top = nullptr;
}

void push(Stack* s, int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = s->top;
    s->top = newNode;
}

void pop(Stack* s, int k){
    Node* current = s->top;
    for (int i = 1; i < k && current != nullptr; i++) {
        current = current->next;
    }
    if (current != nullptr) {
        cout << current->data << endl;
    }
    current = s->top;
    while(current != nullptr && k > 0) {
        current = current->next;
    }
    if (current != nullptr) {
        cout << current->data << endl;
    }
}

int main(){
    Stack s; khoiTao(&s);
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        push(&s, x);
    }
    int k; cin >> k;
    pop(&s, k);

    return 0;
}