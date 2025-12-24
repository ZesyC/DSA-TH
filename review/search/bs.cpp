#include <stdio.h>

int bS(int a[], int l, int r, int x){
    while(l <= r){
        int mid = (l + r)/2;
        if(a[mid] == x) return 1;
        else if(a[mid] > x) r = mid - 1;
        else l = mid + 1;
    }
    return 0;
}

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    int a[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    int s = bS(a, 0, n - 1, m);
    if(s == 1) printf("Co");
    else printf("Khong");
    return 0;
}