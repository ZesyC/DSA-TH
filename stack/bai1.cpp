#include <iostream>
#include <cstdio>
using namespace std;
#define MAX 100

struct Stack {
    int arr[MAX];
    int top;
};

void khoiTao(Stack* s) {
    s->top = -1;
}

void push(Stack* s, int value) {
    if (s->top < MAX - 1) {
        s->arr[++(s->top)] = value;
    } else {
        printf("Stack day!\n");
    }
}

void pop(Stack* s, int k){
    cout << s->arr[k-1] << endl;
    cout << s->arr[s->top - k + 1] << endl;
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