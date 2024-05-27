#include <stdio.h>
#include <stdlib.h>

struct node {
    int vertex;
    struct node* next;
};

struct node* arr[10];

struct Queue {
    int rear, front;
    int size;
    int *arr;
};

int isFull(struct Queue* q) {
    return (q->rear == q->size - 1);
}

int isEmpty(struct Queue* q) {
    return (q->rear == q->front);
}

void enqueue(struct Queue* q, int val) {
    if (isFull(q)) {
        printf("Queue is Full not able to insert \n");
    } else {
        q->rear++;
        q->arr[q->rear] = val;
    }
}

int dequeue(struct Queue* q) {
    int a = -1;
    if (isEmpty(q)) {
        printf("Queue is Empty Not able to withdraw \n");
    } else {
        q->front++;
        a = q->arr[q->front];
    }
    return a;
}

void BFSList(struct node* A[], int v) {
    struct node* P;
    struct Queue *q = (struct Queue*)malloc(sizeof(struct Queue));
    q->size = 10;
    q->front = q->rear = -1;
    q->arr = (int*)malloc(q->size * sizeof(int));
    int visited[10];
    int i, st, u;
    for (i = 0; i < v; i++) {
        visited[i] = 0;
    }
    printf("Starting Vertex: ");
    scanf("%d", &st);
    visited[st] = 1;
    enqueue(q, st);
    printf("BFS Traversal : \n");
    while (!isEmpty(q)) {
        u = dequeue(q);
        printf("%d ", u);
        P = A[u];
        while (P != NULL) {
            if (visited[P->vertex] == 0) {
                enqueue(q, P->vertex);
                visited[P->vertex] = 1;
            }
            P = P->next;
        }
    }
    printf("\n");
    free(q->arr);
    free(q);
}

int main() {
    int ver, u, v, i;
    char ch;
    struct node *p, *newVer;

    printf("Enter number of nodes that you want to have in graph: ");
    scanf("%d", &ver);

    for (i = 0; i < ver; i++) {
        arr[i] = NULL;
    }

    do {
        printf("Enter Edge ( Enter 1st node and 2nd node ): ");
        scanf("%d %d", &u, &v);

        newVer = (struct node*)malloc(sizeof(struct node));
        newVer->vertex = v;
        newVer->next = NULL;
        p = arr[u];
        if (p == NULL) {
            arr[u] = newVer;
        } else {
            while (p->next != NULL) {
                p = p->next;
            }
            p->next = newVer;
        }

        newVer = (struct node*)malloc(sizeof(struct node));
        newVer->vertex = u;
        newVer->next = NULL;
        p = arr[v];
        if (p == NULL) {
            arr[v] = newVer;
        } else {
            while (p->next != NULL) {
                p = p->next;
            }
            p->next = newVer;
        }

        printf("Do you want to add More Edges (Y/N): ");
        scanf(" %c", &ch); 
    } while(ch == 'Y' || ch == 'y');

    BFSList(arr, ver);

    return 0;
}
