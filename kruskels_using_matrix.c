#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10

int parent[MAX_VERTICES];

int findparent(int i) {
    while (parent[i] != i) {
        i = parent[i];
    }
    return i;
}

void union1(int i, int j) {
    int a = findparent(i);
    int b = findparent(j);
    parent[a] = b;
}

void KruskalsMatrix(int G[][MAX_VERTICES], int ver) {
    int min = 999, ne = 1, a, b;
    int minweight = 0;

    for (int i = 0; i < ver; i++) {
        parent[i] = i;
    }

    while (ne < ver ) { 
        min = 999;
        for (int i = 0; i < ver; i++) {
            for (int j = 0; j < ver; j++) {
                if (G[i][j] < min && findparent(i) != findparent(j)) {
                    a = i;
                    b = j;
                    min = G[i][j];
                }
            }
        }

        union1(a, b);
        printf("EdgeNo: %d \t Node ( u , v ): %d %d \t Weight: %d\n", ne, a, b, min);
        minweight = minweight + min;
        ne++;
    }
     printf("Weight of MST: %d\n", minweight);
}

int main() {
     int G[10][10], i, j, u, v, ver, edge;

    printf("Enter No of vertices: ");
    scanf("%d", &ver);

    for (i = 0; i < ver; i++) {
        for (j = 0; j < ver; j++) {
            G[i][j] = 999;
        }
    }

    printf("Enter No of Nodes: ");
    scanf("%d", &edge);

    for (i = 0; i < edge; i++) {
        printf("Enter Edge: ");
        scanf("%d %d", &u, &v);
        printf("Enter Weight: ");
        scanf("%d", &G[u][v]);
        G[v][u] = G[u][v];
    }

    printf("Adjacency Matrix:\n");
    for (i = 0; i < ver; i++) {
        for (j = 0; j < ver; j++) {
            printf("    %d      ", G[i][j]);
        }
        printf("\n");
    }

    KruskalsMatrix(G, ver);

    return 0;
}