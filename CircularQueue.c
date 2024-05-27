#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int items[MAX];
    int front, rear;
} Deque;


void initialize(Deque *dq) {
    dq->front = -1;
    dq->rear = -1;
}


int isFull(Deque *dq) {
    return ((dq->front == 0 && dq->rear == MAX-1) || (dq->front == dq->rear + 1));
}

int isEmpty(Deque *dq) {
    return (dq->front == -1);
}

void addFront(Deque *dq, int value) {
    if (isFull(dq)) {
        printf("Deque is full\n");
        return;
    }
    if (dq->front == -1) {
        dq->front = 0;
        dq->rear = 0;
    } else if (dq->front == 0) {
        dq->front = MAX - 1;
    } else {
        dq->front--;
    }
    dq->items[dq->front] = value;
}


void addRear(Deque *dq, int value) {
    if (isFull(dq)) {
        printf("Deque is full\n");
        return;
    }
    if (dq->rear == -1) {
        dq->rear = 0;
        dq->front = 0;
    } else if (dq->rear == MAX - 1) {
        dq->rear = 0;
    } else {
        dq->rear++;
    }
    dq->items[dq->rear] = value;
}


int delFront(Deque *dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty\n");
        return -1;
    }
    int value = dq->items[dq->front];
    if (dq->front == dq->rear) {
        dq->front = -1;
        dq->rear = -1;
    } else if (dq->front == MAX - 1) {
        dq->front = 0;
    } else {
        dq->front++;
    }
    return value;
}


int delRear(Deque *dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty\n");
        return -1;
    }
    int value = dq->items[dq->rear];
    if (dq->front == dq->rear) {
        dq->front = -1;
        dq->rear = -1;
    } else if (dq->rear == 0) {
        dq->rear = MAX - 1;
    } else {
        dq->rear--;
    }
    return value;
}


void displayDeque(Deque *dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty\n");
        return;
    }
    printf("Deque elements: ");
    int i = dq->front;
    while (1) {
        printf("%d ", dq->items[i]);
        if (i == dq->rear) {
            break;
        }
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    Deque dq;
    initialize(&dq);

    // Example operations
    addRear(&dq, 10);
    addRear(&dq, 20);
    addFront(&dq, 5);
    addFront(&dq, 3);

    printf("Deque after adding elements: \n");
    displayDeque(&dq);

    printf("Removed from front: %d\n", delFront(&dq));
    printf("Removed from rear: %d\n", delRear(&dq));

    printf("Deque after removing elements: \n");
    displayDeque(&dq);

    return 0;
}
