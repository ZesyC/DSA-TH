#include <stdio.h>

int part(int a[], int low, int high){
    int pivot = a[high];
    int i = low - 1;
    for(int j = low; j < high; j++){
        if(a[j] < pivot){
            i++;
            int tmp = a[i];
            a[i] = a[j];
            a[j] = tmp;
        }
    }
    int tmp = a[i + 1];
    a[i + 1] = a[high];
    a[high] = tmp;
    return i + 1;
}

void qsort(int a[], int low, int high){
    if(low < high){
        int pi = part(a, low, high);
        qsort(a, low, pi - 1);
        qsort(a, pi + 1, high);
    }
}

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    int a[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    int sum = 0, c = 0;
    for(int i = 0; i < n; i++){
        sum += a[i];
        c++;
        if(sum > m){
            c--;
        }
    }
    printf("%d", c);
    return 0;
}