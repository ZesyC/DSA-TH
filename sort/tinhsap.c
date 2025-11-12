#include <stdio.h>

int kiemTraTangDan(int arr[], int n){
    for(int i = 0; i < n - 1; i++){
        if(arr[i] > arr[i+1]){
            return 0;
        }
    }
    return 1;
}

int kiemTraGiamDan(int arr[], int n){
    for(int i = 0; i < n - 1; i++){
        if(arr[i] < arr[i+1]){
            return 0;
        }
    }
    return 1;
}

int kiemTraTangChat(int arr[], int n){
    for(int i = 0; i < n - 1; i++){
        if(arr[i] >= arr[i+1]){
            return 0;
        }
    }
    return 1;
}

int kiemTraGiamChat(int arr[], int n){
    for(int i = 0; i < n - 1; i++){
        if(arr[i] <= arr[i+1]){
            return 0;
        }
    }
    return 1;
}

int kiemTraDaSapXep(int arr[], int n){
    if(kiemTraTangChat(arr, n)){
        return 2;
    }
    if(kiemTraTangDan(arr, n)){
        return 1;
    }
    if(kiemTraGiamChat(arr, n)){
        return -2;
    }
    if(kiemTraGiamDan(arr, n)){
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
