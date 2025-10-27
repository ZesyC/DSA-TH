#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void themDau(Node** head, int data) {
    Node* newNode = createNode(data);
    
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    
    newNode->next = *head;
    (*head)->prev = newNode;
    *head = newNode;
}

void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        if (temp->data < 10) {
            printf("%d", temp->data);
        } else {
            printf("%c", 'A' + (temp->data - 10));
        }
        temp = temp->next;
    }
    printf("\n");
}

Node* chuyenHeCoSo(int soHeThap, int Q) {
    Node* head = NULL;
    
    if (Q < 2 || Q > 36) {
        printf("Loi: He co so phai trong khoang [2, 36]\n");
        return NULL;
    }
    
    if (soHeThap == 0) {
        themDau(&head, 0);
        return head;
    }
    
    int n = soHeThap;
    while (n > 0) {
        int soDu = n % Q;
        themDau(&head, soDu);
        n = n / Q;
    }
    
    return head;
}


int main() {
    int soHeThap, heCoSo;
        
    printf("Nhap so he 10: ");
    scanf("%d", &soHeThap);
    
    printf("Nhap he co so muon chuyen: ");
    scanf("%d", &heCoSo);
    
    Node* ketQua = chuyenHeCoSo(soHeThap, heCoSo);
    
    if (ketQua != NULL) {
        printf("\nKet qua: %d (he 10) = ", soHeThap);
        printList(ketQua);
        printf("(he %d)\n", heCoSo);
    }

    return 0;
}
