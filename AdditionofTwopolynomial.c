#include <stdio.h>
#include <stdlib.h>

struct poly{
    int coeff;
    int exp;
    struct poly *next;
};
struct poly* AcceptPoly(int n);
void printpoly(struct poly *p);
struct poly* add(struct poly *p1, struct poly *p2);

struct poly* add( struct poly *p1, struct poly *p2){
struct poly *p3=NULL;
struct poly * head3=NULL;
while(p1!=NULL && p2!=NULL){
    if(head3==NULL){
        head3=p3=(struct poly*)malloc(sizeof(struct poly));
        p3->next=NULL;
    
    }else{
        p3->next=(struct poly*)malloc(sizeof(struct poly));
        p3=p3->next;
        p3->next=NULL;
    }
    if(p1->exp==p2->exp){
        p3->coeff=p1->coeff+p2->coeff;
        p3->exp=p1->exp;
        p1=p1->next;
        p2=p2->next;
    }
    else if(p1->exp > p2->exp){
        p3->coeff=p1->coeff;
        p3->exp=p1->exp;
        p1=p1->next;
    }else{
        p3->coeff=p2->coeff;
        p3->exp=p2->exp;
        p2=p2->next;
    }
}
while(p1!=NULL){
    if(head3==NULL){
        head3=p3=(struct poly*)malloc(sizeof(struct poly));
        p3->next=NULL;
    
    }else{
        p3->next=(struct poly*)malloc(sizeof(struct poly));
        p3=p3->next;
        p3->next=NULL;
    }
   
    p3->coeff=p1->coeff;
    p3->exp=p1->exp;
    p1=p1->next;
}
while(p2!=NULL){
    if(head3==NULL){
        head3=p3=(struct poly*)malloc(sizeof(struct poly));
        p3->next=NULL;
    
    }else{
        p3->next=(struct poly*)malloc(sizeof(struct poly));
        p3=p3->next;
        p3->next=NULL;
    }
    
    p3->coeff=p2->coeff;
    p3->exp=p2->exp;
    p2=p2->next;
}
return head3;

}
int main(){
    struct poly *p1,*p2,*p3;
    int n1,n2;
    printf("Enter the number of terms in 1st of polynomial :");
    scanf("%d",&n1);
    p1=AcceptPoly(n1);
    printf("Enter the number of terms in 2nd of polynomial :");
    scanf("%d",&n2);
    p2=AcceptPoly(n2);
    printf("Polynomial 1 is : \n");
    printpoly(p1);
    printf("Polynomial 2 is : \n");
    printpoly(p2);
    p3=add(p1,p2);
    printf("Resultant polynomial is : ");
    printpoly(p3);
    return 0;

}
struct poly* AcceptPoly(int n){
    struct poly *head,*p;
    head=p=(struct poly*)malloc(sizeof(struct poly));
    p->next=NULL;
    printf("Enter the coefficient and exponents:\n");

    for(int i=0;i<n;i++){
    scanf("%d %d",&p->coeff,&p->exp);
    if(i<n-1){
     p->next=(struct poly*)malloc(sizeof(struct poly));
     p=p->next;
     p->next=NULL;
    }
    }
    return head;
     
}
void printpoly(struct poly *p){
    while ((p!=NULL))
    {
      printf("%d x^%d ",p->coeff,p->exp);
      p=p->next;
     if (p != NULL) {
            printf(" + ");
        }
      
    
}
printf("\n");
}