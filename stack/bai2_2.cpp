#include <bits/stdc++.h>
using namespace std;

struct Node{
    char data;
    Node* next;
};

Node* createNode(char val){
    Node* newNode = new Node();
    newNode->data = val;
    newNode->next = nullptr;
    return newNode;
}

struct Stack{
    Node* top = nullptr;
};

bool isEmpty(const Stack &s){
    return s.top == nullptr;
}

void push(Stack &s, char value){
    Node* newNode = createNode(value);
    newNode->next = s.top;
    s.top = newNode;
}

void display(const Stack &s){
    if (isEmpty(s)){
        cout << "Stack rong!" << endl;
        return;
    }

    Node* cur = s.top;
    while (cur != nullptr){
        cout << cur->data;
        cur = cur->next;
    }
}

int main(){
    int n, q;
    cout << "Nhap n va he co so q: ";
    cin >> n >> q;
    Stack s;
    while (n != 0){
        int phanDu = n % q;
        char k;
        if (phanDu < 10)
            k = '0' + phanDu;
        else
            k = 'A' + (phanDu - 10);
        push(s, k);
        n /= q;
    }
    display(s);
    return 0;
}