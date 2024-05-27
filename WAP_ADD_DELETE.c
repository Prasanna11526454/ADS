#include <stdio.h>
#include <stdlib.h>

// Define the node structure
typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

// Define the queue structure
typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to create an empty queue
Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}

// Function to add an element to the queue
void add(Queue* q, int data) {
    Node* newNode = createNode(data);
    if (q->rear == NULL) {  // Queue is empty
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        newNode->prev = q->rear;
        q->rear = newNode;
    }
}

// Function to delete an element from the queue
int delete(Queue* q) {
    if (q->front == NULL) {  // Queue is empty
        printf("Queue is empty, cannot delete.\n");
        return -1;  // Return an error value or use another method to indicate an empty queue
    }

    Node* temp = q->front;
    int data = temp->data;
    q->front = q->front->next;

    if (q->front == NULL) {  // Queue becomes empty after deletion
        q->rear = NULL;
    } else {
        q->front->prev = NULL;
    }

    free(temp);
    return data;
}

// Example usage
int main() {
    Queue* q = createQueue();
    add(q, 10);
    add(q, 20);
    printf("Deleted: %d\n", delete(q));  // Output: Deleted: 10
    printf("Deleted: %d\n", delete(q));  // Output: Deleted: 20
    printf("Deleted: %d\n", delete(q));  // Output: Queue is empty, cannot delete. Deleted: -1

    return 0;
}
