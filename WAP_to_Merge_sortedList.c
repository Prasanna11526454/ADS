#include<stdio.h>
#include<stdlib.h>

struct node
{
    struct node * prev;
    int data;
    struct node * next;
};

struct node* addToEmpty(struct node * head,int data)
{
    struct node * temp = (struct node *)malloc(sizeof(struct node));
    temp->prev=NULL;
    temp->data=data;
    temp->next=NULL;
    head=temp;
    
    return head;
}

struct node * addToEnd(struct node * head, int data)
{
    if(head==NULL)
    {
        head=addToEmpty(head,data);
        return head;
    }
    struct node * temp =(struct node *)malloc(sizeof(struct node));
    temp->prev=NULL;
    temp->data=data;
    temp->next=NULL;

    struct node * ptr = head;

    while(ptr->next!=NULL)
    {
        ptr=ptr->next;
    }

    ptr->next=temp;
    temp->prev=ptr;

    

    return head;

}

struct node * createlist(struct node * head)
{
    int n, i,data ;
    printf("\nEnter Number of Nodes: \n");
    scanf("%d",&n);

    printf("Enter Node 1: \n");
    scanf("%d",&data);
    head=addToEmpty(head,data);

    for(i=1;i<n;i++)
    {
        printf("Enter Node %d: \n",i+1);
        scanf("%d",&data);
        head=addToEnd(head,data);
    }

    return head;

}

struct node * sortlist(struct node * head)
{
    struct node * i , *j;

    for(i=head;i->next!=NULL;i=i->next)
    {
        
        for(j=head;j->next!=NULL;j=j->next)
        {
            if(j->data > j->next->data)
            {
                int temp=j->data;
                j->data=j->next->data;
                j->next->data=temp;
            }
        }

        
    }
    printf("\nList Sorted Successfully");

    return head;
}

struct node * merge(struct node * head1, struct node * head2)
{
    struct node * temp1=head1;
    while(temp1->next!=NULL)
    {
        temp1=temp1->next;
    }

    temp1->next=head2;
    head2->prev=temp1;

    return head1;


}

void display(struct node * head)
{
    if(head==NULL)
    {
        printf("\n List is Empty");
        return ;
    }
    struct node * temp=head;
    printf("\n");
    while(temp!=NULL)
    {
        printf("%d<--->",temp->data);
        temp=temp->next;
    }
    

}

int main()
{
    struct node * head1=NULL;
    struct node * head2=NULL;

    printf("\nEnter First List: ");
    head1=createlist(head1);
    head1=sortlist(head1);
    
    

    printf("\nEnter Second List: ");
    head2=createlist(head2);
    head2=sortlist(head2);
    

    printf("\nBoth lists: \n\n");
    display(head1);
    display(head2);

    printf("\n List After merging: ");
    head1=merge(head1,head2);
    display(head1);





    

    

    

}