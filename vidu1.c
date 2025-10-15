#include <stdio.h>
#include <string.h>

int main()
{
    char S[10005];
    char X[105];

    fgets(S, sizeof(S), stdin);
    int lenS = strlen(S);
    if (S[lenS - 1] == '\n')
        S[lenS - 1] = '\0';

    fgets(X, sizeof(X), stdin);
    int lenX = strlen(X);
    if (X[lenX - 1] == '\n')
        X[lenX - 1] = '0';

    int count = 0;
    int i = 0;
    int n = strlen(S);

    while (i < n)
    {
        while (i < n && S[i] == ' ')
            i++;
        if (i >= n)
            break;

        int j = 0;
        int k = 0;

        while (i < n && S[i] != ' ' && j < lenX && S[i] == X[j])
        {
            j++;
            k++;
        }

        if (X[j] == '0' && (S[i] == ' ' || S[i] == '\0'))
        {
            count++;
        }

        while (k < n && S[k] != ' ')
        {
            k++;
        }
        i = k;
    }
}