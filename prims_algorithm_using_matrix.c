#include <stdio.h>
#include <stdlib.h>

int findmindistance(int distance[10],int visited[10],int ver){
    int i,index=-1,min=999;
    for(int i=0;i<ver;i++){
     if(visited[i]==0 && distance[i]<min){
        min=distance[i];
        index=i;
     }
    }
    return index;
}

void printMst(int parent[], int G[][10], int ver) {
    printf("\nMinimum Spanning Tree:\n");
    printf("Edge \tWeight\n");
    for (int i = 1; i < ver; i++) {
        printf("%d - %d \t%d \n", parent[i], i, G[i][parent[i]]);
    }
}

void MinimumSpanningTree(int G[][10], int ver) {
    int visited[10], parent[10], distance[10], i, u, j;
    for (i = 0; i < ver; i++) {
        visited[i] = 0;
        parent[i] = -1;
        distance[i] = 999;
    }
    distance[0] = 0;
    for (i = 0; i < ver - 1; i++) {
        u = findmindistance(distance, visited,ver);
        visited[u] = 1;
        for (j = 0; j < ver; j++) {
            if (G[u][j] && visited[j] == 0 && distance[j] > G[u][j]) {
                parent[j] = u;
                distance[j] = G[u][j];
            }
        }
    }
    printMst(parent,G,ver);
}

int main() {
    int G[10][10], ver, v, u, edge, i, j;

    printf("No. of nodes in graph: ");
    scanf("%d", &ver);

    for (i = 0; i < ver; i++) {
        for (j = 0; j < ver; j++) {
            G[i][j] = 0;
        }
    }

    printf("No. of Edges in graph: ");
    scanf("%d", &edge);

    for (i = 0; i <edge; i++) {
        printf("Enter Edge: ");
        scanf("%d %d", &u, &v);
        printf("Enter Weight: ");
        scanf("%d",&G[u][v]);
        G[v][u] = G[u][v] ;
    }

    printf("Adjacency Matrix:\n");
    for (i = 0; i < ver; i++) {
        for (j = 0; j < ver; j++) {
            printf("%d ", G[i][j]);
        }
        printf("\n");
    }
    MinimumSpanningTree(G,ver);
    return 0;
}