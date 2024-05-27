#include <stdio.h>
#include <stdlib.h>

struct TBTNode {
    int data;
    struct TBTNode* left;
    struct TBTNode* right;
    int lbit;
    int rbit;
};

struct TBTNode *head = NULL;
struct TBTNode *root = NULL;

// Function prototypes
struct TBTNode* createNode(int data);
void create();
void insert(struct TBTNode *root, struct TBTNode *temp);
void inorder(struct TBTNode *head);
void preorder(struct TBTNode* head);

int main() {
    int n, v;
    printf("Enter number of elements to insert: \n");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Value of %d is: ", i);
        create();
    }

    printf("\nIn-order Traversal: ");
    inorder(head);

    printf("\nPre-order Traversal: ");
    preorder(head);

    return 0;
}

struct TBTNode* createNode(int data) {
    struct TBTNode* newnode = (struct TBTNode*)malloc(sizeof(struct TBTNode));
    newnode->data = data;
    newnode->left = newnode->right = NULL;
    newnode->lbit = newnode->rbit = 0;
    return newnode;
}

void create() {
    struct TBTNode* temp;
    int data;
    scanf("%d", &data);
    temp = createNode(data);
        
    if (root == NULL) {
        root = temp;
        head = createNode(999);
        head->right = head;
        head->left = root;
        head->lbit = head->rbit = 1;
        root->left = root->right = head;
    } else {
        insert(root, temp);
    }
}

void insert(struct TBTNode* root, struct TBTNode* temp) {
    struct TBTNode* current = root;
    struct TBTNode* parent = NULL;

    while (1) {
        if (temp->data < current->data) {
            if (current->lbit==0) {
                temp->left = current->left;
                temp->right = current;
                current->left = temp;
                current->lbit = 1;
                return;
            } else {
                current = current->left;
            }
        } else {
            if (current->rbit==0) {
                temp->right = current->right;
                temp->left = current;
                current->right = temp;
                current->rbit = 1;
                return;
            } else {
                current = current->right;
            }
        }
    }
}

void inorder(struct TBTNode* head) {
    struct TBTNode* temp = head->left;
    while (temp != head) {
        while (temp->lbit == 1) {
            temp = temp->left;
        }
        printf("%d ", temp->data);

        while (temp->rbit == 0) {
            temp = temp->right;
            if (temp == head) return;
            printf("%d ", temp->data);
        }
        temp = temp->right;
    }
}

void preorder(struct TBTNode* head){
    struct TBTNode* temp=head->left;

    while(temp!=head){
        while(temp->lbit==1){
            printf("%d ",temp->data);
            temp=temp->left;
        }
         printf("%d ",temp->data);
        while(temp->rbit==0){
            temp=temp->right;
            if(temp==head)return;
        }
        temp=temp->right;
    }
}
