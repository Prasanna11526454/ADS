
#include<stdio.h>
#include<stdlib.h>

struct queue {
    int size;
    int f;
    int r;
    int* arr;
};

int isEmpty(struct queue *q) {
    return q->r == q->f;
}

int isFull(struct queue *q) {
    return q->r == q->size - 1;
}

void enqueue(struct queue *q, int val) {
    if (isFull(q)) {
        printf("This Queue is full\n");
    } else {
        q->r++;
        q->arr[q->r] = val;
    }
}

int dequeue(struct queue *q) {
    int a = -1;
    if (isEmpty(q)) {
        printf("This Queue is empty\n");
    } else {
        q->f++;
        a = q->arr[q->f];
    }
    return a;
}

void bfs(int startNode, int graph[7][7], int numNodes) {
    struct queue q;
    q.size = 400;
    q.f = q.r = 0;
    q.arr = (int*) malloc(q.size * sizeof(int));
    
    int visited[7] = {0};
    
    printf("%d ", startNode);
    enqueue(&q, startNode);
    visited[startNode] = 1; // Mark the starting node as visited
    
    while (!isEmpty(&q)) {
        int node = dequeue(&q); // Remove from queue
        
        for (int j = 0; j < numNodes; j++) {
            if (graph[node][j] == 1 && visited[j] == 0) {
                printf("%d ", j); // Add to the BFS
                visited[j] = 1; // Mark visited
                enqueue(&q, j); // Add neighbors to the queue
            }
        }
    }
    
    free(q.arr); // Free allocated memory
}

int main() {
    int graph[7][7] = {
        {0, 1, 1, 0, 0, 0, 0},
        {1, 0, 0, 1, 1, 0, 0},
        {1, 0, 0, 0, 0, 1, 1},
        {0, 1, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0, 0}
    };
    
    bfs(0, graph, 7); // Start BFS from node 0
    
    return 0;
}
