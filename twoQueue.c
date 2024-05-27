#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int front1, rear1;
    int front2, rear2;
    int items[MAX];
} DoubleQueue;

void initialize(DoubleQueue *dq) {
    dq->front1 = -1;
    dq->rear1 = -1;
    dq->front2 = MAX;
    dq->rear2 = MAX;
}

// Check if queue 1 is full
int isFull1(DoubleQueue *dq) {
    return dq->rear1 + 1 == dq->rear2;
}

// Check if queue 2 is full
int isFull2(DoubleQueue *dq) {
    return dq->rear2 - 1 == dq->rear1;
}

// Check if queue 1 is empty
int isEmpty1(DoubleQueue *dq) {
    return dq->front1 == -1 || dq->front1 > dq->rear1;
}

// Check if queue 2 is empty
int isEmpty2(DoubleQueue *dq) {
    return dq->front2 == MAX || dq->front2 < dq->rear2;
}

// Add to queue 1
void addq1(DoubleQueue *dq, int value) {
    if (isFull1(dq)) {
        printf("Queue 1 is full\n");
        return;
    }
    if (dq->front1 == -1) {
        dq->front1 = 0;
    }
    dq->items[++(dq->rear1)] = value;
}

// Add to queue 2
void addq2(DoubleQueue *dq, int value) {
    if (isFull2(dq)) {
        printf("Queue 2 is full\n");
        return;
    }
    if (dq->front2 == MAX) {
        dq->front2 = MAX - 1;
    }
    dq->items[--(dq->rear2)] = value;
}

// Delete from queue 1
int delq1(DoubleQueue *dq) {
    if (isEmpty1(dq)) {
        printf("Queue 1 is empty\n");
        return -1;
    }
    int value = dq->items[dq->front1++];
    if (dq->front1 > dq->rear1) {
        dq->front1 = dq->rear1 = -1;
    }
    return value;
}

// Delete from queue 2
int delq2(DoubleQueue *dq) {
    if (isEmpty2(dq)) {
        printf("Queue 2 is empty\n");
        return -1;
    }
    int value = dq->items[dq->front2--];
    if (dq->front2 < dq->rear2) {
        dq->front2 = dq->rear2 = MAX;
    }
    return value;
}

// Display queue 1
void displayQueue1(DoubleQueue *dq) {
    if (isEmpty1(dq)) {
        printf("Queue 1 is empty\n");
        return;
    }
    printf("Queue 1: ");
    for (int i = dq->front1; i <= dq->rear1; i++) {
        printf("%d ", dq->items[i]);
    }
    printf("\n");
}

// Display queue 2
void displayQueue2(DoubleQueue *dq) {
    if (isEmpty2(dq)) {
        printf("Queue 2 is empty\n");
        return;
    }
    printf("Queue 2: ");
    for (int i = dq->front2; i >= dq->rear2; i--) {
        printf("%d ", dq->items[i]);
    }
    printf("\n");
}

int main() {
    DoubleQueue dq;
    initialize(&dq);

    // Example operations
    addq1(&dq, 10);
    addq1(&dq, 20);
    addq1(&dq, 30);

    addq2(&dq, 40);
    addq2(&dq, 50);
    addq2(&dq, 60);

    printf("Initial Queues:\n");
    displayQueue1(&dq);
    displayQueue2(&dq);

    printf("Dequeue from Queue 1: %d\n", delq1(&dq));
    printf("Dequeue from Queue 2: %d\n", delq2(&dq));

    printf("Queues after Dequeue operations:\n");
    displayQueue1(&dq);
    displayQueue2(&dq);

    return 0;
}
