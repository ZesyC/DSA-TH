#include <stdio.h>

int max(int a, int b){
    return (a > b) ? a : b;
}

void printLCS(int x[], int y[], int n, int m, int dp[][m+1]){
    int i = n, j = m;
    int lcs[100];
    int index = dp[n][m];
    
    while(i > 0 && j > 0){
        if(x[i-1] == y[j-1]){
            lcs[index-1] = x[i-1];
            i--;
            j--;
            index--;
        } else if(dp[i-1][j] > dp[i][j-1]){
            i--;
        } else {
            j--;
        }
    }
    
    for(int k = 0; k < dp[n][m]; k++){
        printf("%d ", lcs[k]);
    }
    printf("\n");
}

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    
    int x[n], y[m];
    
    for(int i = 0; i < n; i++){
        scanf("%d", &x[i]);
    }
    
    for(int j = 0; j < m; j++){
        scanf("%d", &y[j]);
    }
    
    int dp[n+1][m+1];
    
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++){
            if(i == 0 || j == 0){
                dp[i][j] = 0;
            } else if(x[i-1] == y[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    
    printf("Length: %d\n", dp[n][m]);
    printf("LCS: ");
    printLCS(x, y, n, m, dp);
    
    return 0;
}