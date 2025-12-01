#include <stdio.h>

void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void heapify(int a[], int n, int i){
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    
    if(left < n && a[left] > a[largest]){
        largest = left;
    }
    
    if(right < n && a[right] > a[largest]){
        largest = right;
    }
    
    if(largest != i){
        swap(&a[i], &a[largest]);
        heapify(a, n, largest);
    }
}

void heapSort(int a[], int n){
    for(int i = n / 2 - 1; i >= 0; i--){
        heapify(a, n, i);
    }
    
    for(int i = n - 1; i > 0; i--){
        swap(&a[0], &a[i]);
        heapify(a, i, 0);
    }
}

int main(){
    int n;
    scanf("%d", &n);
    int arr[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    heapSort(arr, n);
    if(n < 3){
        for(int i = 0; i < n; i++){
            printf("%d ", arr[i]);
        }
    } else {
        for(int i = n - 1; i >= n - 3; i--){
            printf("%d ", arr[i]);
        }
    }

    return 0;
}
