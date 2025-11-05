#include <bits/stdc++.h>
using namespace std;
#define MAX_SIZE 1000

struct Stack{
    char arr[MAX_SIZE];
    int top = -1;
};

bool isFull(const Stack &s){
    return s.top >= MAX_SIZE - 1;
}

void push(Stack &s, char value){
    if (isFull(s)){
        cout << "Stack day!" << endl;
        return;
    }
    s.arr[++s.top] = value;
}

void display(const Stack &s){
    if (s.top == -1){
        cout << "Stack rong!" << endl;
        return;
    }

    for(int i=s.top; i>=0; i--){
        cout << s.arr[i];
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