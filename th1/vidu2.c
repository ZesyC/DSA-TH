#include <stdio.h>
#include <string.h>

int main() {
    char S[100005];
    char X[105];
    
    fgets(S, sizeof(S), stdin);
    int lenS = strlen(S);
    if (S[lenS - 1] == '\n') S[lenS - 1] = '\0';
    
    fgets(X, sizeof(X), stdin);
    int lenX = strlen(X);
    if (X[lenX - 1] == '\n') X[lenX - 1] = '\0';
    
    int count = 0;
    int i = 0;
    int n = strlen(S);

    while (i < n) {
        while (i < n && S[i] == ' ') i++;
        if (i >= n) break;

        int j = 0;
        int k = i;

        while (S[k] != ' ' && S[k] != '\0' && X[j] != '\0' && S[k] == X[j]) {
            k++;
            j++;
        }

        if (X[j] == '\0' && (S[k] == ' ' || S[k] == '\0')) {
            count++;
        }

        while (k < n && S[k] != ' ') k++;
        i = k;
    }

    printf("%d\n", count);
    return 0;
}