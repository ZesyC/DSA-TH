#include <stdio.h>

int part(int a[], int low, int high){
    int pivot = a[high];
    int i = low - 1;
    for(int j = low; j < high; j++){
        i++;
        int tmp = a[i];
        a[i] = a[j];
        a[j] = tmp;
    }
    int tmp = a[i+1];
    a[i+1] = a[high];
    a[high]= tmp;
    return i + 1;
}

void qsort(int a[], int low, int high){
    if(low < high){
        int pi = part(a, low, high);
        qsort(a, low, pi - 1);
        qsort(a, pi + 1, high);
    }
}

int main() {
    int n, m;
    int a[1000], b[1000], c[2000];
    int i, j, k;

    scanf("%d", &n);
    for (i = 0; i < n; i++) scanf("%d", &a[i]);

    scanf("%d", &m);
    for (i = 0; i < m; i++) scanf("%d", &b[i]);

    qsort(a, 0, n -1);
    qsort(b, 0, m -1);

    i = 0;
    j = 0;
    k = 0;

    while (i < n && j < m) {

        if (a[i] <= b[j]) {
            c[k] = a[i]; 
            i++;
        } else {
            c[k] = b[j]; 
            j++;
        }

        k++;
    }

    while (i < n) {
        c[k] = a[i];
        i++;
        k++;
    }

    while (j < m) {
        c[k] = b[j];
        j++;
        k++;
    }
    for (i = 0; i < n + m; i++) {
        printf("%d", c[i]);
        if (i < n + m - 1) printf(" ");
    }

    return 0;
}
