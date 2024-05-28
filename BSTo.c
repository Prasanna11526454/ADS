#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

struct node* insert(struct node*, int data);
struct node* deleteNode(struct node*, int val);
struct node* inOrderPredecessor(struct node*);

void preorder(struct node* root){
    if(root != NULL){
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(struct node* root){
    if(root != NULL){
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void postorder(struct node* root){
    if(root != NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

void MirrorTree(struct node* root){
    if(root == NULL)
        return;
    else{
        struct node* temp;
        MirrorTree(root->left);
        MirrorTree(root->right);
        temp = root->left;
        root->left = root->right;
        root->right = temp;
    }
}

int findmin(struct node* root){
    if(root == NULL)
        return -1; // Return an error value indicating no minimum value found

    struct node* temp = root;
    while(temp->left != NULL){//Non Recursive
        temp = temp->left;
    }
    return temp->data;
}

int findmax(struct node* root){
    if(root == NULL)
        return -1; // Return an error value indicating no maximum value found

    struct node* temp = root;
    while(temp->right != NULL){//Non Recursive
        temp = temp->right;
    }
    return temp->data;
}

int Heightoftree(struct node* root){
    if(root == NULL)
        return 0;

    int leftHeight, rightHeight;
    leftHeight = Heightoftree(root->left);
    rightHeight = Heightoftree(root->right);

    if(leftHeight > rightHeight)
       return (leftHeight + 1);
    else
       return (rightHeight + 1);
}

void CurrentLevel(struct node* root, int level){
    if(root == NULL)
        return;

    if(level == 1){
        printf("%d ", root->data);
    } else if(level > 1){
        CurrentLevel(root->left, level - 1);
        CurrentLevel(root->right, level - 1);
    }
}

void Levelorder(struct node* root){
    int h = Heightoftree(root);

    for(int i = 1; i <= h; i++){
        printf("Level %d is :", i);
        CurrentLevel(root, i);
        printf("\n");
    }
}

void LeafNode(struct node* root){
    if(root == NULL)
        return;

    if(!root->left && !root->right){
        printf("%d ", root->data);
    }

    if(root->left){
        LeafNode(root->left);
    }
    if(root->right){
        LeafNode(root->right);
    }
}

struct node* search(struct node* root ,int val){
    if(root==NULL){
        return NULL;
    }
    if(root==val){
        return val;
    }
    else if(val<root->data){
        search(root->left,val);
    }
    else if(val>root->data){
        search(root->right,val);
    }

}

struct node* deleteNode(struct node* root, int val){
    if(root == NULL){
        return root;
    }

    if(val < root->data){
        root->left = deleteNode(root->left, val);
    } else if(val > root->data){
        root->right = deleteNode(root->right, val);
    } else{
        if(root->left == NULL && root->right == NULL){ // Case 1: Node to be deleted is a leaf node
            free(root);
            root = NULL;
        }
        else if(root->left == NULL){ // Case 2: Node to be deleted has only right child
            struct node* temp = root;
            root = root->right;
            free(temp);
        } else if(root->right == NULL){ // Case 3: Node to be deleted has only left child
            struct node* temp = root;
            root = root->left;
            free(temp);
        } else{ // Case 4: Node to be deleted has both left and right children
            struct node* temp = inOrderPredecessor(root->right); // Find the inorder successor
            root->data = temp->data; // Copy the data of the successor to this node
            root->right = deleteNode(root->right, temp->data); // Delete the successor from the right subtree
        }
    }
    return root;
}

struct node* inOrderPredecessor(struct node* root){
    root = root->left;
    while(root->right != NULL){
        root = root->right;
    }
    return root;
}




int main() {
    struct node* root = NULL;
    int n ;
    printf("ENter the Size of bst : ");
    scanf("%d",&n);

    int val;
    printf(" Enter the Tree : ");
    for(int i = 0; i <= n; i++){
        scanf("%d", &val);
        root = insert(root, val);
    }

    printf("Preorder Traversal : ");
    preorder(root);
    printf("\n");
    printf("Inorder Traversal : ");
    inorder(root);
    printf("\n");
    printf("Postorder Traversal : ");
    postorder(root);
    printf("\n");

    printf("Minimum Value in Tree: ");
    int min = findmin(root);
    printf("%d\n", min);

    printf("Maximum Value in Tree: ");
    int max = findmax(root);
    printf("%d\n", max);

    printf("Height of tree : ");
    int height = Heightoftree(root);
    printf("%d\n", height);

    printf("Level Order traversal of binary tree is : \n");
    Levelorder(root);
    printf("\n");

    printf("Leaf nodes : ");
    LeafNode(root);
    printf("\n");

    int search_val;
    printf("Enter Element to search in BST :");
    scanf("%d",&search_val);
    printf("\n");
    struct node* result=search(root,search_val);

    if(result==NULL){
        printf(" Element Not present in BST");
        printf("\n");
    }else{
       printf("Element present in BST");
       printf("\n");
    }



    //printf("\n\nDelete a Leaf Node: \n");
   // root = deleteNode(root, 1);
   // printf("Modified BST tree after deleting Leaf Node:\n");
   // inorder(root);

    //printf("\n\nDelete Node with single child: \n");
   // root = deleteNode(root, 21);
    //printf("Modified BST tree after deleting single child Node:\n");
   // inorder(root);

    //printf("\n\nDelete Node with both child: \n");
    root = deleteNode(root,5 );
    printf("Modified BST tree after deleting Node:\n");
    inorder(root);

    return 0;
}

struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct node* insert(struct node* root, int data) {
    if (root == NULL)
        return createNode(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);

    return root;
}

