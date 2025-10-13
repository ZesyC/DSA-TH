#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node; 

Node* createNode(int val){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

void printList(Node* head) {
    Node* tmp = head;
    while (tmp != NULL) {
        printf("%d ", tmp->data);
        tmp = tmp->next;
    }
}

void xoaGiua(Node **head, int flag){
    if(*head == NULL){
        return;
    }
    
    Node* tmp = *head;
    while(tmp != NULL && tmp->data != flag){
        tmp = tmp->next;
    }
    
    if(tmp != NULL && tmp->next != NULL){
        tmp->next = tmp->next->next;
    }
}

int main(){
    int n,m;
    scanf("%d %d", &n,&m);
    Node* head = NULL;
    
    // Thêm vào ĐẦU danh sách
    for (int i = 0; i < n; i++){
        int val;
        scanf("%d", &val);
        Node* newNode = createNode(val);
        newNode->next = head;
        head = newNode;
    }
    
    for(int i = 0; i < m; i++){
        int flag;
        scanf("%d", &flag);
        xoaGiua(&head, flag);
    }
    printList(head);
    return 0;
}