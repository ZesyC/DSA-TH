#include <stdio.h>
#define max 100000

int n = 0, a[max];

void push(int x){
    a[n] = x;
    n++;
}

void top(){
    if(n >= 1){
        printf("%d", a[0]);
    }
}

void pop(){
    for(int i = 0; i < n; i++){
        a[i] = a[i+1];
    }
    n--;
}

int main(){
    int k;
    scanf("%d", &k);
    for(int i = 0; i < k; i++){
        int m;
        scanf("%d", &m);
        push(m);
    }
    for(int i = 0; i < n; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
    printf("Phan tu dau tien la: ");
    top();
    printf("\nQueue sau khi pop: ");
    pop();
    for(int i = 0; i < n; i++){
        printf("%d ", a[i]);
    }
    return 0;
}
