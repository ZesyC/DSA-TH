#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define KICH_THUOC 20

void hoanDoi(int *a, int *b) {
    int tam = *a;
    *a = *b;
    *b = tam;
}

void heapify(int mang[], int n, int i) {
    int lonNhat = i;
    int trai = 2 * i + 1;
    int phai = 2 * i + 2;
    
    if (trai < n && mang[trai] > mang[lonNhat])
        lonNhat = trai;
    
    if (phai < n && mang[phai] > mang[lonNhat])
        lonNhat = phai;
    
    if (lonNhat != i) {
        hoanDoi(&mang[i], &mang[lonNhat]);
        heapify(mang, n, lonNhat);
    }
}

void heapSort(int mang[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(mang, n, i);
    
    for (int i = n - 1; i > 0; i--) {
        hoanDoi(&mang[0], &mang[i]);
        heapify(mang, i, 0);
    }
}

void inMang(int mang[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", mang[i]);
    printf("\n");
}

void sinhMangNgauNhien(int mang[], int n) {
    for (int i = 0; i < n; i++) {
        mang[i] = rand() % 100;
    }
}

int main() {
    int mang[KICH_THUOC];
    
    srand(time(NULL));
    
    sinhMangNgauNhien(mang, KICH_THUOC);
    
    printf("Mảng trước khi sắp xếp:\n");
    inMang(mang, KICH_THUOC);
    
    heapSort(mang, KICH_THUOC);
    
    printf("\nMảng sau khi sắp xếp (Heapsort):\n");
    inMang(mang, KICH_THUOC);
    
    return 0;
}
