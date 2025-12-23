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

void themGiua(Node** head, int data, int flag){
    Node* newNode = createNode(data);
    if(*head == NULL) *head = newNode;
    else{
        Node* tmp = *head;
        while(tmp != NULL && tmp->data != flag) tmp = tmp->next;
        if(tmp == NULL){
            newNode->next = *head;
            *head = newNode;
        }
        else{
            newNode->next = tmp->next;
            tmp->next = newNode;
        }
    }
}

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    Node* head = NULL;
    while(n--){
        int data;
        scanf("%d", &data);
        themGiua(&head, data, m);
    }
    printList(head);
    return 0;
}
