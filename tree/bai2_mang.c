#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int tree[MAX_SIZE];

void initTree(){
    for(int i = 0; i < MAX_SIZE; i++){
        tree[i] = -1;
    }
}

void insert(int data, int index){
    if(tree[index] == -1){
        tree[index] = data;
        return;
    }
    if(data < tree[index]){
        insert(data, 2*index + 1);
    } else {
        insert(data, 2*index + 2);
    }
}

int findMin(int index){
    if(index >= MAX_SIZE || tree[index] == -1){
        return -1;
    }
    int leftChild = 2*index + 1;
    if(leftChild < MAX_SIZE && tree[leftChild] != -1){
        return findMin(leftChild);
    }
    return index;
}

void deleteNode(int data, int index){
    if(index >= MAX_SIZE || tree[index] == -1){
        return;
    }
    
    if(data < tree[index]){
        deleteNode(data, 2*index + 1);
    } else if(data > tree[index]){
        deleteNode(data, 2*index + 2);
    } else {
        int leftChild = 2*index + 1;
        int rightChild = 2*index + 2;
        
        if(leftChild >= MAX_SIZE || tree[leftChild] == -1){
            if(rightChild < MAX_SIZE && tree[rightChild] != -1){
                tree[index] = tree[rightChild];
                tree[rightChild] = -1;
            } else {
                tree[index] = -1;
            }
        } else if(rightChild >= MAX_SIZE || tree[rightChild] == -1){
            tree[index] = tree[leftChild];
            tree[leftChild] = -1;
        } else {
            int minIndex = findMin(rightChild);
            tree[index] = tree[minIndex];
            deleteNode(tree[minIndex], rightChild);
        }
    }
}

void printInOrder(int index){
    if(index >= MAX_SIZE || tree[index] == -1){
        return;
    }
    printInOrder(2*index + 1);
    printf("%d ", tree[index]);
    printInOrder(2*index + 2);
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
    
    int x;
    scanf("%d", &x);
    deleteNode(x, 0);
    printInOrder(0);
    
    return 0;
}
