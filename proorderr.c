#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

// Structure of a binary tree node
struct node {
  int data;
  struct node* left;
  struct node* right;
};

// Function to create a new node
struct node* newNode(int data) {
  struct node* temp = (struct node*)malloc(sizeof(struct node));
  temp->data = data;
  temp->left = temp->right = NULL;
  return temp;
}

// Iterative function for preorder traversal
void iterativePreorder(struct node* root) {
  // Create an empty stack
  struct node* stack[MAX_SIZE]; // Replace MAX_SIZE with a suitable value (e.g., 100)
  int top = -1;

  // Push the root node onto the stack
  if (root) {
    stack[++top] = root;
  }

  // Loop until the stack is empty
  while (top >= 0) {
    // Pop the top element from the stack
    struct node* current = stack[top--];

    // Print the data of the popped node
    printf("%d ", current->data);

    // Push right child first (preorder)
    if (current->right) {
      stack[++top] = current->right;
    }

    // Push left child next
    if (current->left) {
      stack[++top] = current->left;
    }
  }
}

int main() {
  // Create a sample binary tree
  struct node* root = newNode(10);
  root->left = newNode(8);
  root->right = newNode(2);
  root->left->left = newNode(3);
  root->left->right = newNode(5);
  root->right->left = newNode(2);

  // Perform preorder traversal
  printf("Preorder traversal: ");
  iterativePreorder(root);
  printf("\n");

  return 0;
}

