#include <stdio.h>
#include<stdlib.h>

struct Stack{
    int top;
    int size;
    int *arr;

};

int isEmpty(struct Stack* s){
    return s->top==-1;
}

int isFull(struct Stack* s){
    return s->top==s->size-1;
}

void push(struct Stack* s,int val){
    if(isFull(s)) {
        printf("Stack Overflow");

    }else{
        s->top++;
        s->arr[s->top]=val;
    }
}

int pop(struct Stack* s){
    if(isEmpty(s)){
         printf("Stack Underflow");
         return -1;
    }else{
        int val=s->arr[s->top];
        s->top--;
        return val;
       
    }
   
}
void DFS(int G[10][10],int ver){
    struct Stack* s=(struct Stack*)malloc(sizeof(struct Stack));
    s->top=-1;
    s->size=100;
    s->arr=(int*)malloc(s->size*sizeof(int));

    int visited[ver];

    for(int i=0;i<ver;i++){
        visited[i]=0;
    }
    int st,i,u;
    printf("Enter Starting Vertex :");
    scanf("%d",&st);
    printf("DFS Traversal : \n");
    push(s,st);
    printf("%d ",st);
    visited[st]=1;
    u=st;
    while(!isEmpty(s)){
        int found=0;
     for(i=0;i<ver;i++){
       if(G[u][i]==1 && !visited[i]){
        push(s,i);
        visited[i]=1;
        printf("%d ",i);
        u=i;
        found=1;
        break;
       }
     }
     if (!found) {
            pop(s);
            if (!isEmpty(s)) {
                u = s->arr[s->top];
            }
        }
    }

}

int main(){
 int G[10][10],ver,edge, u,v,i,j;

 printf("Enter No. of Vertex :");
 scanf("%d",&ver);

 for(i=0;i<ver;i++){
    for(j=0;j<ver;j++){
        G[i][j]=0;
    }
 }

 printf("Enter No. of Edges :");
 scanf("%d",&edge);

 for(i=0;i<edge;i++){
    printf("Enter Edge (u v): ");
    scanf("%d %d",&u,&v);
    G[u][v]=G[v][u]=1;
 }

 printf("Adjacency Matrix : \n");

 for(i=0;i<ver;i++){
    for(j=0;j<ver;j++){
        printf("%d ",G[i][j]);
    }
    printf("\n");
 }
 DFS(G,ver);
}