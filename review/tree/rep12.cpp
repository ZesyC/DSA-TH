#include <stdio.h>
#define max 100005

int val[max];
int l[max];
int r[max];
int count;

int create(int x){
    count++;
    val[count] = x;
    l[count] = 0;
    r[count] = 0;
    return count;
}

int insert(int root, int x){
    if(root == 0) return create(x);
    if(x < val[root]){
        l[root] = insert(l[root], x);
    }
    else if(x > val[root]){
        r[root] = insert(r[root], x);
    }
    return root;
}

int timTraiNhat(int root){
    int pre = root;
    while(l[pre] != 0){
        pre = l[pre];
    }
    return pre;
}

int xoa(int root, int x){
    if(root == 0) return 0;
    if(x < val[root]) l[root] = xoa(l[root], x);
    else if(x > val[root]) r[root] = xoa(r[root], x);
    else{
        if(l[root] == 0) return r[root];
        else if(r[root] == 0) return l[root];
        else{
            int k = timTraiNhat(r[root]);
            val[root] = val[k];
            r[root] = xoa(r[root], val[k]);
        }
    }
    return root;
}

void preOder(int root){
    if(root == 0) return;
    printf("%d ", val[root]);
    preOder(l[root]);
    preOder(r[root]);
}

int main(){
    int n, k;
    int root = 0;
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; i++){
        int x;
        scanf("%d", &x);
        root = insert(root, x);
    }
    root = xoa(root, k);
    preOder(root);
    return 0;
}