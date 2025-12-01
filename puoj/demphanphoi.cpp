#include <stdio.h>

int main() {
    int n, a;
    int cnt[100] = {0};

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a);
        cnt[a]++;
    }

    for (int i = 0; i < 100; i++) {
        printf("%d ", cnt[i]);
    }

    return 0;
}
