#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* left;
    struct Node* right;
}Node;

Node* createNode(int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void insertNode(Node** treeN, Node* newNode){
    if(*treeN == NULL){
        *treeN = newNode;
    }
    else if(newNode->data < (*treeN)->data){
        insertNode(&(*treeN)->left, newNode);
    }
    else{
        insertNode(&(*treeN)->right, newNode);
    }
}

void inOrder(Node* treeN){
    if(treeN != NULL){
        inOrder(treeN->left);
        printf("%d ", treeN->data);
        inOrder(treeN->right);
    }
}

void preOrder(Node* treeN){
    if(treeN != NULL){
        printf("%d ", treeN->data);
        preOrder(treeN->left);
        preOrder(treeN->right);
    }
}

void postOrder(Node* treeN){
    if(treeN != NULL){
        postOrder(treeN->left);
        postOrder(treeN->right);
        printf("%d ", treeN->data);
    }
}

void freeTree(Node* treeN){
    if(treeN != NULL){
        freeTree(treeN->left);
        freeTree(treeN->right);
        free(treeN);
    }
}

int main(){
    int n;
    scanf("%d", &n);
    Node* treeN = NULL;
    for(int i = 0; i < n; i++){
        int data;
        scanf("%d", &data);
        Node* newNode = createNode(data);
        insertNode(&treeN, newNode);
    }
    printf("In-order: ");
    inOrder(treeN);
    printf("\n");
    printf("Pre-order: ");
    preOrder(treeN);
    printf("\n");
    printf("Post-order: ");
    postOrder(treeN);
    printf("\n");
    freeTree(treeN);
    return 0;
}