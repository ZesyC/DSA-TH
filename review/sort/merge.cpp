#include <stdio.h>

void merge(int a[], int left,int mid, int right){
    int l = left;
    int m = mid + 1;
    int i = left;
    int c[right + 1];
    while (l <= mid && m <= right){
        if(a[l] < a[m]){
            c[i] = a[l];
            l++;
        }
        else{
            c[i] = a[m];
            m++;
        }
        i++;
    }
    while(l <= mid){
        c[i] = a[l];
        i++;
        l++;
    }
    while(m <= right){
        c[i] = a[m];
        i++;
        m++;
    }
    for(int j = left; j <= right; j++){
        a[j] = c[j];
    }
}

void mergeSort(int a[], int left, int right){
    if(left < right){
        int mid = (right + left) / 2;
        mergeSort(a, left, mid);
        mergeSort(a, mid + 1, right);
        merge(a, left, mid, right);
    }
}

int main(){
    int n;
    scanf("%d", &n);
    int a[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    mergeSort(a, 0, n - 1);
    for(int i = 0; i < n; i++){
        printf("%d ", a[i]);
    }
}