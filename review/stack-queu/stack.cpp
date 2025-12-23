#include <stdio.h>

int n = 0, stack[100001];

void push(int data){
    stack[n] = data;
    n++;
}

void pop(){
    if(n >= 1){
        n--;
    }
}

int top(){
    if(n >= 1){
        return stack[n-1];
    }
    return -1;
}

int main(){
    int m;
    printf("Nhap m: ");
    scanf("%d", &m);
    while(m--){
        int data;
        scanf("%d", &data);
        push(data);
    }
    for(int i = 0; i < n; i++){
        printf("%d ", stack[i]);
    }
    printf("\n");
    pop();
    for(int i = 0; i < n; i++){
        printf("%d ", stack[i]);
    }
    printf("\n");
    int a = top();
    printf("%d", a);
    return 0;
}



