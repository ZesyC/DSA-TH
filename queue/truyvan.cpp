#include <iostream>
using namespace std;

int myQueue[100001];
int front = 0, rear = -1;

void push(int n) {
    rear = rear + 1;
    myQueue[rear] = n;
}

void pop(){
    if(front > rear) return;
    front++;
}

void print(){
    if(front > rear){
        cout << "Empty!" << endl;
        return;
    }
    cout << myQueue[front];
    cout << endl;
}

int main(){
    int T;
    cin >> T;
    while(T--){
        int cmd;
        cin >> cmd;
        if(cmd == 1){
            int n;
            cin >> n;
            push(n);
        }
        else if(cmd == 2){
            pop();
        }
        else{
            print();
        }
    }
    return 0;
}