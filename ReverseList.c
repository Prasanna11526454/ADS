#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* insertAtBeginning(struct Node* head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = head;
    head = newNode;
    return head;
}

struct Node* reverse(struct Node* head) {
    struct Node* temp = NULL;
    struct Node* temp2= NULL;

    while (head!= NULL) {
       temp2 = head->next;  // Store next node
        head->next = temp;  // Reverse current node's pointer
        temp = head;        // Move pointers one position ahead
        head = temp2;
    }
    head = temp;
    return head;
}

void printList(struct Node* head) {
    struct Node* temp = head;

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;

    head = insertAtBeginning(head, 5);
    head = insertAtBeginning(head, 4);
    head = insertAtBeginning(head, 3);
    head = insertAtBeginning(head, 2);
    head = insertAtBeginning(head, 1);

    printf("Original list:\n");
    printList(head);

    head = reverse(head);
    printf("Reversed list:\n");
    printList(head);

    return 0;
}
