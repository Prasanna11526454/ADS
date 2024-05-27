#include<stdio.h>
#include<stdlib.h>

struct node{
    int vertex;
    struct node* next;
};

struct node* A[10];

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

void DFS(struct node* A[], int ver){
 struct Stack *s=(struct Stack*)malloc(sizeof(struct Stack));
 s->top=-1;
 s->size=100;
 s->arr=(int*)malloc(s->size*sizeof(int));
 struct node* P;
 
 int visited[ver];
 for(int i=0;i<ver;i++){
    visited[i]=0;
 }
int st,u;
 printf("Enter Starting Vertex: ");
 scanf("%d",&st);

 printf("DFS Traversal: \n");
 push(s,st);
 printf("%d ",st);
 visited[st]=1;
 u=st;
 P=A[u];
do{
    P=A[u];
    while (P!=NULL)
    {
        if(!visited[P->vertex]){
            push(s,P->vertex);
            visited[P->vertex]=1;
            u=P->vertex;
            printf("%d ",u);
            break;
        }else{
            P=P->next;
        }

        if(P==NULL){
            pop(s);
            u=s->top;
        }
    }
    
}while(!isEmpty(s));
}

int main(){
    struct node* P;
    struct node* newV;
    int ver,i,u,v;
    char ch;

    printf("Enter No. of Vertex:");
    scanf("%d",&ver);

    for(i=0;i<ver;i++){
        A[i]=NULL;
    }
do{
    printf("Enter Edge (u,v): ");
    scanf("%d %d",&u,&v);

    newV=(struct node*)malloc(sizeof(struct node));
    newV->vertex=v;
    newV->next=NULL; 

    if(A[u]==NULL){
        A[u]=newV;
    }
    else{
        P=A[u];
        while(P->next!=NULL){
           P=P->next;
        }
        P->next=newV;
    }

    newV=(struct node*)malloc(sizeof(struct node));
    newV->vertex=u;
    newV->next=NULL;

    if(A[v]==NULL){
        A[v]=newV;
    }else{
        P=A[v];
        while(P->next!=NULL){
            P=P->next;
        }
        P->next=newV;
    }

    printf(" Add More Edges(y/n): ");
    scanf(" %c",&ch);
}while(ch=='y'||ch=='Y');

printAdjacencyList(ver);
DFS(A,ver);
}

void printAdjacencyList(int ver){
    printf("Adjacency List : \n");
    for(int i=0;i<ver;i++){
     printf("%d :",i);
     struct node* p = A[i];
        while (p != NULL) {
            printf("%d -> ", p->vertex);
            p = p->next;
        }
        printf("NULL\n");
    }
}
