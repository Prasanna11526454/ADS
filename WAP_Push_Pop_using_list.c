#include<stdio.h>
#include<stdlib.h>

struct node{
    struct node * prev;
    int data;
    struct node * next;
};

struct node * addToEmpty(struct node * head , int data)
{
    struct node * temp = (struct node * )malloc(sizeof(struct node));
    temp->prev=NULL;
    temp->data=data;
    temp->next=NULL;

    head=temp;

    printf("\nNode inserted successfully}");
    return head;
}

struct node * addAtBeg(struct node* head,int data)
{
    if(head==NULL)
    {
        head=addToEmpty(head, data);
        return head;
    }
    struct node * temp=(struct node *)malloc(sizeof(struct node));
    temp->prev=NULL;
    temp->data=data;
    temp->next=NULL;

    temp->next=head;
    head->prev=temp;
    head=temp;

    printf("\nNode inserted successfully");

    return head;
}

struct node * display(struct node * head)
{
    if(head==NULL)
    {
        printf("\nStack is empty");
        return head;
    }
    struct node * ptr= head;
    printf("\n");
    while(ptr!=NULL)
    {
        printf("\n| %d |",ptr->data);
        printf("\n_____");
        ptr=ptr->next;
    }

    return head;

}

struct node * push(struct node * head, int data)
{
    head=addAtBeg(head,data);
    return head;
}

struct node * delAtFirst(struct node * head)
{
    int val;
    if(head==NULL)
    {
        printf("\nStack is Empty Nothing to delete");
    }
    struct node * temp=head;
    val=temp->data;
    head=head->next;
    free(head->prev);
    temp->next=NULL;
    temp=NULL;
    printf("\n %d deleted successfully",val);

    return head;
}

struct node * pop(struct node * head)
{
    head=delAtFirst(head);
    
    return head;
}

int main()
{
    int choice,data;
    struct node * head=NULL;
    
    printf("\nProgram Implementing Push and POP operations on stack using doubly linked list ");

    

    do
    {
        printf("\n\nMenu:");
        printf("\n1.Push");
        printf("\n2.Pop");
        printf("\n3.display stack");
        printf("\n4.Exit");

        printf("\nEnter Your choice: ");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1:
            printf("\nEnter data to Push: \n");
            scanf("%d",&data);
            head=push(head,data);
            break;
        case 2:
            head=pop(head);
            break;
        
        case 3:
            head=display(head);
            break;
        case 4:
            printf("Exiting Program....");
            break;

        default:
            printf("\nInvalid choice enter again from menu");
        }



    } while (choice!=4);
    


}