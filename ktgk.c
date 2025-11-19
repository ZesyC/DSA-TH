#include <stdio.h>
#include <string.h>

#define MAX 100

typedef struct{
    char ma[20];
    char hoten[50];
    float d1, d2, d3, tong;
    char nganh[50];
}SinhVien;

void xoaEnter(char* str){
    size_t len = strlen(str);
    if(len > 0 && str[len - 1] == '\n'){
        str[len - 1] = '\0';
    }
}

void nhapSV(SinhVien* SV){
    fgets(SV->ma, sizeof(SV->ma), stdin);
    xoaEnter(SV->ma);
    fgets(SV->hoten, sizeof(SV->hoten), stdin);
    xoaEnter(SV->hoten);
    scanf("%f%f%f", &SV->d1, &SV->d2, &SV->d3);
    SV->tong = SV->d1 + SV->d2 + SV->d3;
    getchar();
    fgets(SV->nganh, sizeof(SV->nganh), stdin);
    xoaEnter(SV->nganh);
    SV->tong = SV->d1 + SV->d2 + SV->d3;
}

void nhapDS(SinhVien ds[], int n){
    for(int i = 0; i < n; i++){
        nhapSV(&ds[i]);
    }
}

void inSV(SinhVien *SV){
    printf("%-10s %-20s %6.2f %6.2f %6.2f %6.2f %-15s\n", SV->ma, SV->hoten, SV->d1, SV->d2, SV->d3, SV->tong, SV->nganh);
}

void inDS(SinhVien a[], int n){
    for(int i = 0; i < n; i++){
        inSV(&a[i]);
    }
}

void swap(SinhVien* a, SinhVien* b){
    SinhVien temp = *a;
    *a = *b;
    *b = temp;
}

int partition(SinhVien a[], int low, int high){
    float pivot = a[high].tong;
    int i = low - 1;
    
    for(int j = low; j < high; j++){
        if(a[j].tong >= pivot){
            i++;
            swap(&a[i], &a[j]);
        }
    }
    swap(&a[i + 1], &a[high]);
    return i + 1;
}

void quickSort(SinhVien a[], int low, int high){
    if(low < high){
        int pi = partition(a, low, high);
        quickSort(a, low, pi - 1);
        quickSort(a, pi + 1, high);
    }
}



int main(){
    int n;
    printf("Nhap so luong sinh vien: ");
    scanf("%d", &n);
    getchar();
    
    SinhVien ds[MAX];
    
    printf("\nNhap thong tin sinh vien:\n");
    nhapDS(ds, n);
    
    quickSort(ds, 0, n - 1);
    
    printf("\nDanh sach sau khi sap xep theo tong diem giam dan:\n");
    printf("%-10s %-20s %6s %6s %6s %6s %-15s\n", "Ma SV", "Ho ten", "Diem1", "Diem2", "Diem3", "Tong", "Nganh");
    inDS(ds, n);
    
    return 0;
}