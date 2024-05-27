#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct StackNode {
    struct TreeNode* node;
    int depth;
    struct StackNode* next;
};

void postorderIterative(struct TreeNode* root) {
    if (root == NULL)
        return;

    struct StackNode* top = NULL;
    struct TreeNode* current = root;
    struct TreeNode* lastVisited = NULL;

    while (current != NULL || top != NULL) {
        while (current != NULL) {
            struct StackNode* newNode = (struct StackNode*)malloc(sizeof(struct StackNode));
            newNode->node = current;
            newNode->next = top;
            top = newNode;
            current = current->left;
        }

        struct TreeNode* topNode = top->node;
        if (topNode->right != NULL && lastVisited != topNode->right) {
            current = topNode->right;
        } else {
            printf("%d ", topNode->data);
            lastVisited = topNode;
            struct StackNode* temp = top;
            top = top->next;
            free(temp);
        }
    }
}

// Helper functions to create a new tree node and insert nodes in the tree
struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct TreeNode* insert(struct TreeNode* root, int data) {
    if (root == NULL)
        return createNode(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);

    return root;
}

void preorderIterative(struct TreeNode* root) {
    if (root == NULL)
        return;

    struct StackNode* top = NULL;
    struct TreeNode* current = root;
    while (current != NULL || top != NULL) {
        while (current != NULL) {
            printf("%d ", current->data);
            struct StackNode* newNode = (struct StackNode*)malloc(sizeof(struct StackNode));
            newNode->node = current;
            newNode->next = top;
            top = newNode;
            current = current->left;
        }
        current = top->node;
        top = top->next;
        current = current->right;
    }
}

void inorderIterative(struct TreeNode* root) {
    if (root == NULL)
        return;

    struct StackNode* top = NULL;
    struct TreeNode* current = root;

    while (current != NULL || top != NULL) {
        // Reach the leftmost node of the current node
        while (current != NULL) {
            struct StackNode* newNode = (struct StackNode*)malloc(sizeof(struct StackNode));
            newNode->node = current;
            newNode->next = top;
            top = newNode;
            current = current->left;
        }

        // Current must be NULL at this point
        current = top->node;
        top = top->next;
        printf("%d ", current->data);

        // Visit the right subtree
        current = current->right;
    }
}

int findHeight(struct TreeNode* root) {
    if (root == NULL)
        return 0;

    struct StackNode* top = NULL;
    struct TreeNode* current = root;
    int maxHeight = 0;

    // Push the root node onto the stack with initial depth 1
    struct StackNode* newNode = (struct StackNode*)malloc(sizeof(struct StackNode));
    newNode->node = root;
    newNode->depth = 1;
    newNode->next = top;
    top = newNode;

    while (top != NULL) {
        // Pop the node from the stack
        current = top->node;
        int currentDepth = top->depth;
        top = top->next;

        // Update the maximum height
        if (currentDepth > maxHeight) {
            maxHeight = currentDepth;
        }

        // Push the right child onto the stack with updated depth
        if (current->right != NULL) {
            newNode = (struct StackNode*)malloc(sizeof(struct StackNode));
            newNode->node = current->right;
            newNode->depth = currentDepth + 1;
            newNode->next = top;
            top = newNode;
        }

        // Push the left child onto the stack with updated depth
        if (current->left != NULL) {
            newNode = (struct StackNode*)malloc(sizeof(struct StackNode));
            newNode->node = current->left;
            newNode->depth = currentDepth + 1;
            newNode->next = top;
            top = newNode;
        }
    }

    return maxHeight;
}

int countTotalNodes(struct TreeNode* root) {
    if (root == NULL)
        return 0;

    struct StackNode* top = NULL;
    struct TreeNode* current = root;
    int count = 0;

    while (current != NULL || top != NULL) {
        while (current != NULL) {
            // Push current node onto the stack
            struct StackNode* newNode = (struct StackNode*)malloc(sizeof(struct StackNode));
            newNode->node = current;
            newNode->next = top;
            top = newNode;
            current = current->left;
        }

        // Pop node from stack
        current = top->node;
        top = top->next;

        // Increment count
        count++;

        // Move to the right subtree
        current = current->right;
    }

    return count;
}

void displayLeafNodes(struct TreeNode* root) {
    if (root == NULL)
        return;

    struct StackNode* top = NULL;
    struct TreeNode* current = root;

    while (current != NULL || top != NULL) {
        while (current != NULL) {
            // Push current node onto the stack
            struct StackNode* newNode = (struct StackNode*)malloc(sizeof(struct StackNode));
            newNode->node = current;
            newNode->next = top;
            top = newNode;
            current = current->left;
        }

        // Pop node from stack
        current = top->node;
        top = top->next;

        // Check if it's a leaf node
        if (current->left == NULL && current->right == NULL) {
            printf("%d ", current->data);
        }

        // Move to the right subtree
        current = current->right;
    }
}


struct QueueNode {
    struct TreeNode* node;
    struct QueueNode* next;
};

struct Queue {
    struct QueueNode* front;
    struct QueueNode* rear;
};

struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    if (queue == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    queue->front = queue->rear = NULL;
    return queue;
}

void enqueue(struct Queue* queue, struct TreeNode* node) {
    struct QueueNode* newNode = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->node = node;
    newNode->next = NULL;
    if (queue->rear == NULL) {
        queue->front = queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

struct TreeNode* dequeue(struct Queue* queue) {
    if (queue->front == NULL)
        return NULL;

    struct QueueNode* temp = queue->front;
    struct TreeNode* node = temp->node;
    queue->front = queue->front->next;
    if (queue->front == NULL)
        queue->rear = NULL;
    free(temp);
    return node;
}

void levelOrderTraversal(struct TreeNode* root) {
    if (root == NULL)
        return;

    struct Queue* queue = createQueue();
    enqueue(queue, root);

    while (queue->front != NULL) {
        struct TreeNode* current = dequeue(queue);
        printf("%d ", current->data);

        if (current->left != NULL)
            enqueue(queue, current->left);
        if (current->right != NULL)
            enqueue(queue, current->right);
    }
    printf("\n");
}

struct TreeNode* minValueNode(struct TreeNode* node) {
    struct TreeNode* current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

struct TreeNode* deleteNode(struct TreeNode* root, int key) {
    if (root == NULL)
        return root;

    // Traverse the tree to find the node to be deleted
    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        // Node with only one child or no child
        if (root->left == NULL) {
            struct TreeNode* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct TreeNode* temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children: Get the inorder successor (smallest in the right subtree)
        struct TreeNode* temp = minValueNode(root->right);

        // Copy the inorder successor's content to this node
        root->data = temp->data;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}
// Main function to demonstrate the postorder iterative traversal
int main() {
    struct TreeNode* root = NULL;

    // Example tree
    root = insert(root, 4);
    insert(root, 2);
    insert(root, 6);
    insert(root, 1);
    insert(root, 3);
    insert(root, 5);
    insert(root, 7);

    // printf("Postorder Traversal (Iterative): ");
    // printf("\n");
    // preorderIterative(root);
    // printf("\n");
    // postorderIterative(root);
    // printf("\n");
    // inorderIterative(root);
    // printf("\n");

    printf("Original tree (Inorder traversal): ");
    inorderIterative(root);
    printf("\n");

    // Deleting a node
    root = deleteNode(root, 4);

    printf("Tree after deleting node 4 (Inorder traversal): ");
    inorderIterative(root);
    printf("\n");

    return 0;
}