#include <stdio.h>

// Tìm vị trí phần tử trong mảng
int timViTri(int a[], int n, int k) {
    for (int i = 0; i < n; i++) {
        if (a[i] == k) return i;
    }
    return -1;
}

// Tìm phần tử trái nhất trong cây con phải
int timTraiNhat(int a[], int n, int viTri) {
    int viTriPhai = 2 * viTri + 2;
    if (viTriPhai >= n) return -1;
    
    // Đi xuống trái nhất có thể
    while (2 * viTriPhai + 1 < n) {
        viTriPhai = 2 * viTriPhai + 1;
    }
    return viTriPhai;
}

// Xoá phần tử tại vị trí pos
void xoaPhanTu(int a[], int *n, int pos) {
    // Tìm nút thay thế (trái nhất của cây con phải)
    int viTriThayThe = timTraiNhat(a, *n, pos);
    
    if (viTriThayThe != -1) {
        // Thay thế giá trị
        a[pos] = a[viTriThayThe];
        // Xoá nút đã dùng để thay thế
        xoaPhanTu(a, n, viTriThayThe);
    } else {
        // Không có con phải, kiểm tra con trái
        int viTriTrai = 2 * pos + 1;
        if (viTriTrai < *n) {
            // Có con trái, thay thế bằng con trái
            a[pos] = a[viTriTrai];
            xoaPhanTu(a, n, viTriTrai);
        } else {
            // Là lá, xoá trực tiếp
            for (int i = pos; i < *n - 1; i++) {
                a[i] = a[i + 1];
            }
            (*n)--;
        }
    }
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    
    int a[100000];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    
    // Tìm và xoá phần tử k
    int viTri = timViTri(a, n, k);
    if (viTri != -1) {
        xoaPhanTu(a, &n, viTri);
    }
    
    // In kết quả
    for (int i = 0; i < n; i++) {
        printf("%d", a[i]);
        if (i < n - 1) printf(" ");
    }
    printf("\n");
    
    return 0;
}