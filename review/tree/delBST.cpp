#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int val;
    struct Node* left;
    struct Node* right;
}Node;

Node* createNode(int val){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, int v){
    if(root == NULL) root = createNode(v);
    if(root->val == v) return root;
    else if(root->val > v) root->left = insert(root->left, v);
    else root->right = insert(root->right, v);
    return root;
}

void preOrder(Node* root){
    if(root != NULL){
        printf("%d ", root->val);
        preOrder(root->left);
        preOrder(root->right);
    }
}

Node* deleteNode(Node* root, int v){
    if(root == NULL) return NULL;
    if(v < root->val){
        root->left = deleteNode(root->left, v);
        return root;
    }
    if(v > root->val){
        root->right = deleteNode(root->right, v);
        return root;
    }
    if(root->left == NULL){
        Node* tmp = root->right;
        free(root);
        return tmp;
    }
    else if(root->right == NULL){
        Node* tmp = root->left;
        free(root);
        return tmp;
    }
    else{
        Node* tmp = root->right;
        while(tmp->left != NULL){
            tmp = tmp->left;
        }
        root->val = tmp->val;
        root->right = deleteNode(root->right, tmp->val);
        return root;
    }

}

int main(){
    int n, k, a;
    Node* root = NULL;
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; i++){
        scanf("%d", &a);
        root = insert(root, a);
    }
    root = deleteNode(root, k);
    preOrder(root);
    return 0;
}