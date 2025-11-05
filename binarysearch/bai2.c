#include <stdio.h>

int binarySearch(int arr[], int n, int value){
    int left = 0;
    int right = n;
    
    while(left < right){
        int mid = left + (right - left) / 2;
        if(arr[mid] < value){
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left;
}

void mergeWithBinarySearch(int X[], int nX, int Y[], int nY, int Z[]){
    int k = 0;
    
    for(int i = 0; i < nX; i++){
        Z[k++] = X[i];
    }
    
    for(int j = 0; j < nY; j++){
        int pos = binarySearch(Z, k, Y[j]);
        
        for(int i = k; i > pos; i--){
            Z[i] = Z[i-1];
        }
        Z[pos] = Y[j];
        k++;
    }
}

int main(){
    int nX, nY;
    
    scanf("%d", &nX);
    int X[nX];
    for(int i = 0; i < nX; i++){
        scanf("%d", &X[i]);
    }
    
    scanf("%d", &nY);
    int Y[nY];
    for(int i = 0; i < nY; i++){
        scanf("%d", &Y[i]);
    }
    
    int Z[nX + nY];
    mergeWithBinarySearch(X, nX, Y, nY, Z);
    
    for(int i = 0; i < nX + nY; i++){
        printf("%d ", Z[i]);
    }
    printf("\n");
    
    return 0;
}