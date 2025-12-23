#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

Node* createNode(int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void printList(Node* head){
    Node* tmp = head;
    while(tmp != NULL){
        printf("%d ", tmp->data);
        tmp = tmp->next;
    }
}

void themDau(Node** head, int data){
    Node* newNode = createNode(data);
    if(*head == NULL) *head = newNode;
    else{
        newNode->next = *head;
        *head = newNode;
    }
}

void xoaGiua(Node** head, int flag){
    if(*head == NULL) return;
    else{
        Node* tmp = *head;
        while(tmp != NULL && tmp->data != flag) tmp = tmp->next;
        tmp->next = tmp->next->next;
    }
}

int main(){
    int n;
    scanf("%d", &n);
    Node* head = NULL;
    while(n--){
        int data;
        scanf("%d", &data);
        themDau(&head, data);
    }
    printList(head);
    xoaGiua(&head, 2);
    printf("\n");
    printList(head);
    return 0;
}