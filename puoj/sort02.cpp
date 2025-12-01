#include <stdio.h>

void swapp(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int part(int a[], int low, int high){
    int pivot = a[high];
    int i = low - 1;
    for(int j = low; j < high; j++){
        if(a[j] < pivot){
            i++;
            swapp(&a[j], &a[i]);
        }
    }
    swapp(&a[i+1], &a[high]);
    return i + 1;
}

void qsort(int a[], int low , int high){
    if(low < high){
        int pi = part(a, low, high);
        qsort(a, low, pi - 1);
        qsort(a, pi + 1, high);
    }
}

int main(){
    int n;
    scanf("%d", &n);
    int a[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    qsort(a, 0, n - 1);
    for(int i = 0; i < n; i++){
        printf("%d ", a[i]);
    }
    return 0;
}