#include <stdio.h>

int main() {
    long long a, b, c;
    scanf("%lld %lld %lld", &a, &b, &c);

    if (a + b > c && a + c > b && b + c > a) {
            printf("YES");
        } else {
            printf("NO");
        }

    return 0;
}
