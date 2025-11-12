#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int arr[], int n){
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int kiemTraTangChat(int arr[], int temp[], int n){
    for(int i = 0; i < n; i++){
        if(arr[i] != temp[i]){
            return 0;
        }
    }
    for(int i = 0; i < n - 1; i++){
        if(arr[i] == arr[i+1]){
            return 0;
        }
    }
    return 1;
}

int kiemTraGiamChat(int arr[], int temp[], int n){
    for(int i = 0; i < n; i++){
        if(arr[i] != temp[n-1-i]){
            return 0;
        }
    }
    for(int i = 0; i < n - 1; i++){
        if(arr[i] == arr[i+1]){
            return 0;
        }
    }
    return 1;
}

int kiemTraTangDan(int arr[], int temp[], int n){
    for(int i = 0; i < n; i++){
        if(arr[i] != temp[i]){
            return 0;
        }
    }
    return 1;
}

int kiemTraGiamDan(int arr[], int temp[], int n){
    for(int i = 0; i < n; i++){
        if(arr[i] != temp[n-1-i]){
            return 0;
        }
    }
    return 1;
}

int kiemTraDaSapXep(int arr[], int n){
    int temp[n];
    for(int i = 0; i < n; i++){
        temp[i] = arr[i];
    }
    
    bubbleSort(temp, n);
    
    if(kiemTraTangChat(arr, temp, n)){
        return 2;
    }
    if(kiemTraTangDan(arr, temp, n)){
        return 1;
    }
    if(kiemTraGiamChat(arr, temp, n)){
        return -2;
    }
    if(kiemTraGiamDan(arr, temp, n)){
        return -1;
    }
    return 0;
}

int main(){
    int n;
    scanf("%d", &n);
    
    int arr[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    
    int result = kiemTraDaSapXep(arr, n);
    
    if(result == 2){
        printf("Tang chat\n");
    } else if(result == 1){
        printf("Tang dan\n");
    } else if(result == -1){
        printf("Giam dan\n");
    } else if(result == -2){
        printf("Giam chat\n");
    } else {
        printf("Chua sap xep\n");
    }
    
    return 0;
}
