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

void deleteAt(Node **head, int pos1based){
    if (*head == NULL || pos1based <= 0) return;

    if (pos1based == 1) {
        Node* tmp = *head;
        *head = (*head)->next;
        free(tmp);
        return;
    }

    Node* prev = *head;
    for (int i = 1; i < pos1based - 1 && prev != NULL; i++) {
        prev = prev->next;
    }
    if (prev == NULL || prev->next == NULL) return; 

    Node* del = prev->next;
    prev->next = del->next;
    free(del);
}

void printList(Node* head) {
    for (Node* p = head; p != NULL; p = p->next) {
        printf("%d", p->data);
        if (p->next) printf(" ");
    }
    printf("\n"); 
}

void freeList(Node* head){
    while (head){
        Node* tmp = head;
        head = head->next;
        free(tmp);
    }
}

int main(){
    int n, v;
    if (scanf("%d %d", &n, &v) != 2) return 0;

    Node* head = NULL;
    Node* tail = NULL;

    for (int i = 0; i < n; i++){
        int val; 
        scanf("%d", &val);
        Node* newNode = createNode(val);
        if (head == NULL){
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    deleteAt(&head, v); 
    printList(head);
    freeList(head);
    return 0;
}
