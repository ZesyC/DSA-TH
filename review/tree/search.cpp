#include <stdio.h>

int search(int a[], int n, int x){
    int i = 0;
    while(i < n && a[i] != -1){
        if(a[i] == x) return 1;
        else if(a[i] > x){
            i = i * 2 + 1;
        }
        else{
            i = i * 2 + 2;
        }
    }
    return 0;
}