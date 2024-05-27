#include <stdio.h>
#include <stdlib.h>

struct node {
    int vertex;
    int weight; 
    struct node* next;
}; 

struct node* arr[10];

void printAdjacencyList(int ver) {
    printf("Adjacency List:\n");
    for (int i = 0; i < ver; i++) {
        printf("Vertex %d: ", i);
        struct node* p = arr[i];
        while (p != NULL) {
            printf("(%d, %d) -> ", p->vertex, p->weight); // Print vertex and weight
            p = p->next;
        }
        printf("NULL\n");
    }
}

int findmindistance(int distance[10], int visited[10], int ver) {
    int min = 999, index = -1;
    for (int i = 0; i < ver; i++) {
        if (visited[i] == 0 && distance[i] < min) {
            min = distance[i];
            index = i;
        }
    }
    return index;
}

void MinimumSpanningTree(struct node *arr[], int ver) {
    int visited[10], parent[10], distance[10], i, u, j;
    for (i = 0; i < ver; i++) {
        visited[i] = 0;
        parent[i] = -1;
        distance[i] = 999;
    }
    distance[0] = 0;
    for (i = 0; i < ver - 1; i++) {
        u = findmindistance(distance, visited, ver);
        visited[u] = 1;

        struct node* p = arr[u];
        while (p != NULL) {
            int v = p->vertex;
            if (!visited[v] && p->weight < distance[v]) {
                distance[v] = p->weight;
                parent[v] = u;
            }
            p = p->next;
        }
    }
     printf("\nMinimum Spanning Tree:\n");
    printf("Edge \tWeight\n");
    for (int i = 1; i < ver; i++) {
        printf("%d - %d \t%d\n", parent[i], i, distance[i]);
    }
}



int main() {
    int ver, u, v, weight, i;
    char ch;
    struct node *p, *newVer;

    printf("Enter no. of vertices: ");
    scanf("%d", &ver);

    for (i = 0; i < ver; i++) {
        arr[i] = NULL;
    }

    do {
        printf("Enter Edge and Weight: ");
        scanf("%d %d %d", &u, &v, &weight);
  
        newVer = (struct node*)malloc(sizeof(struct node));
        newVer->vertex = v;
        newVer->weight = weight;
        newVer->next = arr[u];
        arr[u] = newVer;

        newVer = (struct node*)malloc(sizeof(struct node));
        newVer->vertex = u;
        newVer->weight = weight;
        newVer->next = arr[v];
        arr[v] = newVer;

        printf("Add More Edges (Y/N): ");
        scanf(" %c", &ch); 
    } while(ch == 'Y' || ch == 'y');

    printAdjacencyList(ver);
    MinimumSpanningTree(arr, ver);

    return 0;
}