#include <stdio.h>
#include <stdlib.h>

struct node {
    int vertex;
    int weight;
    struct node* next;
};

struct node* arr[10];

struct DisjointSet {
    int parent;
    int rank;
};

int find(struct DisjointSet subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

void Union(struct DisjointSet subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

void printAdjacencyList(int ver) {
    printf("Adjacency List:\n");
    for (int i = 0; i < ver; i++) {
        printf("Vertex %d: ", i);
        struct node* p = arr[i];
        while (p != NULL) {
            printf("(%d, %d) -> ", p->vertex, p->weight);
            p = p->next;
        }
        printf("NULL\n");
    }
}

void KruskalsMST(int ver) {
    struct DisjointSet* subsets = (struct DisjointSet*)malloc(ver * sizeof(struct DisjointSet));

    for (int v = 0; v < ver; v++) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }
    int edges = 0;
    int totalWeight = 0;
    struct node* p;
    printf("\nEdges in the Minimum Spanning Tree:\n");
    while (edges < ver - 1) {
        int min_weight = 999;
        int min_u = -1, min_v = -1;

        for (int u = 0; u < ver; u++) {
            for (p = arr[u]; p != NULL; p = p->next) {
                int v = p->vertex;
                int weight = p->weight;
                int x = find(subsets, u);
                int y = find(subsets, v);

                if (x != y && weight < min_weight) {
                    min_weight = weight;
                    min_u = u;
                    min_v = v;
                }
            }
        }

        totalWeight += min_weight;
        Union(subsets, min_u, min_v);
        printf("(%d, %d) -> %d\n", min_u, min_v, min_weight);
        edges++;
    }
    printf("\nTotal weight of the minimum spanning tree: %d\n", totalWeight);
    free(subsets);
}


int main() {
    int ver, u, v, weight, i;
    char ch;
    struct node* newVer;

    printf("Enter no. of Nodes: ");
    scanf("%d", &ver);

    for (i = 0; i < ver; i++) {
        arr[i] = NULL;
    }

    do {
        printf("Enter Node (u,v) and Weight: ");
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

        printf("Add More Edges (1 for Yes || 0 for No): ");
        scanf(" %d", &ch);
    } while (ch == 1);

    printAdjacencyList(ver);
    KruskalsMST(ver);

    return 0;
}

