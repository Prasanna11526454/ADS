#include <stdio.h>
#include <stdlib.h>

struct List {
    int vertex;
    int weight;
    struct List *next;
};
struct List *arr[10];

void printAdjList(int ver){
    printf("Adjacency List:\n");
    for(int i=0;i<ver;i++){
        printf("Vertex %d: ",i);
        struct List* p= arr[i];
        while(p!=NULL){
            printf("(%d, %d) -> ",p->vertex,p->weight);
            p=p->next;   
        }
        printf("NULL\n");
    }
}


void DijaktrasList(int ver, int src) {
    int dist[10], visited[10];
    struct List *p;
    for (int i = 0; i < ver; i++) {
        dist[i] = 999;
        visited[i] = 0;
    }
    dist[src] = 0;

    for (int i = 0; i < ver - 1; i++) {
        int min = 999, min_index;
        for (int v = 0; v < ver; v++)
            if (visited[v] == 0 && dist[v] <= min)
                min = dist[v], min_index = v;
        visited[min_index] = 1;

        for (p = arr[min_index]; p != NULL; p = p->next) {
            int v = p->vertex;
            if (!visited[v] && dist[min_index] != 999 && dist[min_index] + p->weight < dist[v])
                dist[v] = dist[min_index] + p->weight;
        }
    }
    printf("\nShortest distances from source vertex %d:\n", src);
    for (int i = 0; i < ver; i++) {
        printf("Vertex %d: %d\n", i, dist[i]);
    }
}

int main(){
    int ver, u,v ,weight,i;
    int ch;
    struct List* newVer;
    printf("Enter no. of Vertices: ");
    scanf("%d",&ver);

    for(i=0;i<ver;i++){
        arr[i]=NULL;
    }
    do{
        printf("Enter Edge And Weight : ");
        scanf("%d %d %d",&u,&v,&weight);
    
    newVer=(struct List*)malloc(sizeof(struct List));
    newVer->vertex=v;
    newVer->weight=weight;
    newVer->next=arr[u];
    arr[u]=newVer;

    printf("Add More Edges (1 for Yes | 0 for No) ");
    scanf(" %d", &ch);
    } while(ch==1);
    printAdjList(ver);
    DijaktrasList(ver,0);
}

