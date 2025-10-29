#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int tree[MAX_SIZE];
int size = 0;

void initTree(){
    for(int i = 0; i < MAX_SIZE; i++){
        tree[i] = -1;
    }
}

void insert(int data, int index){
    if(tree[index] == -1){
        tree[index] = data;
        size++;
        return;
    }
    if(data < tree[index]){
        insert(data, 2*index + 1);
    } else {
        insert(data, 2*index + 2);
    }
}

void inOrder(int index){
    if(index >= MAX_SIZE || tree[index] == -1){
        return;
    }
    inOrder(2*index + 1);
    printf("%d ", tree[index]);
    inOrder(2*index + 2);
}

void preOrder(int index){
    if(index >= MAX_SIZE || tree[index] == -1){
        return;
    }
    printf("%d ", tree[index]);
    preOrder(2*index + 1);
    preOrder(2*index + 2);
}

void postOrder(int index){
    if(index >= MAX_SIZE || tree[index] == -1){
        return;
    }
    postOrder(2*index + 1);
    postOrder(2*index + 2);
    printf("%d ", tree[index]);
}

int main(){
    int n;
    scanf("%d", &n);
    
    initTree();
    
    for(int i = 0; i < n; i++){
        int data;
        scanf("%d", &data);
        insert(data, 0);
    }
    
    printf("In-order: ");
    inOrder(0);
    printf("\n");
    
    printf("Pre-order: ");
    preOrder(0);
    printf("\n");
    
    printf("Post-order: ");
    postOrder(0);
    printf("\n");
    
    return 0;
}