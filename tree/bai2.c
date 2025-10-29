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

void printInOrder(Node* root){
    if(root == NULL){
        return;
    }
    printInOrder(root->left);
    printf("%d ", root->data);
    printInOrder(root->right);
}

void freeTree(Node* root){
    if(root == NULL){
        return;
    }
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

void insert(Node** root, int data){
    if(*root == NULL){
        *root = createNode(data);
        return;
    }
    if(data < (*root)->data){
        insert(&(*root)->left, data);
    } else {
        insert(&(*root)->right, data);
    }
}

void deleteNode(Node** root, int data){
    if(*root == NULL){
        return;
    }
    if(data < (*root)->data){
        deleteNode(&(*root)->left, data);
    } else if(data > (*root)->data){
        deleteNode(&(*root)->right, data);
    } else {
        if((*root)->left == NULL){
            Node* temp = (*root)->right;
            free(*root);
            *root = temp;
        } else if((*root)->right == NULL){
            Node* temp = (*root)->left;
            free(*root);
            *root = temp;
        } else {
            Node* temp = (*root)->right;
            while(temp->left != NULL){
                temp = temp->left;
            }
            (*root)->data = temp->data;
            deleteNode(&(*root)->right, temp->data);
        }
    }
}

int main(){
    int n;
    scanf("%d", &n);
    Node* root = NULL;
    for(int i = 0; i < n; i++){
        int data;
        scanf("%d", &data);
        insert(&root, data);
    }
    int x;
    scanf("%d", &x);
    deleteNode(&root, x);
    printInOrder(root);
    freeTree(root);
    return 0;
}