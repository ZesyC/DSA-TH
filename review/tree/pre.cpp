#include <stdio.h>
#define max 100001

int a[max], n;

void preOder(int i){
    if(i < n && a[i] != -1){
        printf("%d ", a[i]);
        preOder(i * 2 + 1);
        preOder(i * 2 + 2);
    }
}

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    preOder(0);
    return 0;
}