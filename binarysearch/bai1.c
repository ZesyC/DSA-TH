#include <stdio.h>
#include <string.h>

int checkMatch(char* P, char* Q, int pos, int lenQ){
    for(int i = 0; i < lenQ; i++){
        if(P[pos + i] != Q[i]){
            return 0;
        }
    }
    return 1;
}

int binarySearch(char* P, char* Q, int lenP, int lenQ){
    int left = 0;
    int right = lenP - lenQ;
    int result = -1;
    
    while(left <= right){
        int mid = left + (right - left) / 2;
        
        if(checkMatch(P, Q, mid, lenQ)){
            result = mid;
            right = mid - 1;
        } else {
            int found = 0;
            for(int i = left; i <= mid; i++){
                if(checkMatch(P, Q, i, lenQ)){
                    result = i;
                    found = 1;
                    break;
                }
            }
            if(found){
                right = result - 1;
            } else {
                left = mid + 1;
            }
        }
    }
    return result;
}

int main(){
    char P[10000];
    char Q[10000];
    
    fgets(P, sizeof(P), stdin);
    fgets(Q, sizeof(Q), stdin);
    
    int lenP = strlen(P);
    int lenQ = strlen(Q);
    
    if(P[lenP-1] == '\n') lenP--;
    if(Q[lenQ-1] == '\n') lenQ--;
    
    if(lenQ > lenP){
        printf("-1\n");
        return 0;
    }
    
    int result = binarySearch(P, Q, lenP, lenQ);
    
    if(result != -1){
        printf("%d\n", result);
    } else {
        printf("-1\n");
    }
    
    return 0;
}