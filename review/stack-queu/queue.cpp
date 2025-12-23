#include <stdio.h>
#define max 100001

int n = 0, queu[max];

void push(int data){
    if(n >= max) return;
    else{
        queu[n] = data;
        n++;
    }
}

void pop(){
    if(n >= 1){
        for(int i = 0; i < n; i++){
            queu[i] = queu[i+1];
        }
        n--;
    }
}

int top(){
    if(n > 0){
        return queu[0];
    }
    return -1;
}

int main(){
    int m;
    scanf("%d", &m);
    while(m--){
        int data;
        scanf("%d", &data);
        push(data);
    }
    for(int i = 0; i < n; i++){
        printf("%d ", queu[i]);
    }
    printf("\n");
    pop();
    for(int i = 0; i < n; i++){
        printf("%d ", queu[i]);
    }
    printf("\n");
    int a = top();
    printf("%d", a);
    return 0;
}