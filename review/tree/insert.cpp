#include <stdio.h>
#define max 100001

int val[max];
int l[max];
int r[max];
int count = 0;

int create(int x){
    count++;
    val[count] = x;
    l[count] = 0;
    r[count] = 0;
    return count;
}

int insert(int root, int x){
    if(root == 0) return create(x);
    if(x < val[root]) l[root] = insert(l[root], x);
    else if(x > val[root]) r[root] = insert(r[root], x);
    else return;
    return root;
}

void preOder(int root){
    if(root == 0) return;
    printf("%d ", val[root]);
    preOder(l[root]);
    preOder(r[root]);
}

int main(){
    int n;
    scanf("%d", &n);
    int root = 0;
    for(int i = 0; i < n; i++){
        int x;
        scanf("%d", &x);
        root = insert(root, x);
    }
    preOder(root);
    return 0;
}