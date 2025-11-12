#include <stdio.h>

int n;
int a[100000];

int search(int val){
    int i = 0;
    while(i < n && a[i] != -1){
        if(a[i] == val){
            return 1;
        }
        else if( val < a[i]){
            i = 2 * i + 1;
        }
        else{
            i = 2 * i + 2;
        }
    }
    return 0;
}

int main(){
    int k;
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    if(search(k)){
        printf("1");
    }
    else{
        printf("0");
    }
    return 0;
}