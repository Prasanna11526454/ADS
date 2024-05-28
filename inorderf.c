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

// Iterative function for inorder traversal
void iterativeInorder(struct node* root) {
  // Create an empty stack
  struct node* stack[MAX_SIZE]; // Replace MAX_SIZE with a suitable value (e.g., 100)
  int top = -1;

  // Initialize current node as the root
  struct node* current = root;

  // Loop while there are nodes to process
  while (current != NULL || top != -1) {
    // Reach the leftmost node of the current node
    if (current != NULL) {
      // Push the current node onto the stack and move to the left child
      stack[++top] = current;
      current = current->left;
    } else {
      // Pop the top node from the stack and print its data (inorder)
      current = stack[top--];
      printf("%d ", current->data);

      // Move to the right child of the popped node
      current = current->right;
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

  // Perform inorder traversal
  printf("Inorder traversal: ");
  iterativeInorder(root);
  printf("\n");

  return 0;
}

