#include <stdio.h>

int part(int a[], int l, int r){
    int pivot = a[r];
    int i = l - 1;
    for(int j = l; j < r; j++){
        if(a[j] < pivot){
            i++;
            int tmp = a[i];
            a[i] = a[j];
            a[j] = tmp;
        }
    }
    int tmp = a[i + 1];
    a[i + 1]= a[r];
    a[r] = tmp;
    return i + 1;
}

void quick(int a[], int l, int r){
    if(l < r){
        int pi = part(a, l, r);
        quick(a, l, pi - 1);
        quick(a, pi + 1, r);
    }
}

int main(){
    int n;
    scanf("%d", &n);
    int a[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    quick(a, 0, n - 1);
    for(int i = 0; i < n; i++){
        printf("%d ", a[i]);
    }
    return 0;
}