#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Node {
    char data;
    struct Node* next;
    struct Node* prev;
} Node;

Node* taoNode(char data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void themCuoi(Node** head, char data) {
    Node* newNode = taoNode(data);
    
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    
    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    
    temp->next = newNode;
    newNode->prev = temp;
}

Node* taoDanhSachTuChuoi(char* str) {
    Node* head = NULL;
    int len = strlen(str);
    
    for (int i = 0; i < len; i++) {
        themCuoi(&head, str[i]);
    }
    
    return head;
}

void inDanhSach(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%c", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int kiemTraDoiXung(Node* head) {
    if (head == NULL) return 1; // Chuỗi rỗng coi như đối xứng
    
    Node* dau = head;
    Node* cuoi = timNodeCuoi(head);
    
    // So sánh từ hai đầu vào giữa
    while (dau != cuoi && dau->prev != cuoi) {
        if (dau->data != cuoi->data) {
            return 0;
        }
        dau = dau->next;
        cuoi = cuoi->prev;
    }
    
    return 1;
}

int main() {
    char str[100];
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = 0;
    Node* danhSach = taoDanhSachTuChuoi(str);
    inDanhSach(danhSach);
    if (kiemTraDoiXung(danhSach)) {
        printf("Chuoi doi xung\n");
    } else {
        printf("Chuoi khong doi xung\n");
    }
    return 0;
}
