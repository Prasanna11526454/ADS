#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Employee structure
typedef struct Employee {
    int emp_id;
    char name[50];
} Employee;

// TreeNode structure
typedef struct TreeNode {
    Employee employee;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// Function prototypes
TreeNode* insert(TreeNode* root, Employee employee);
TreeNode* search(TreeNode* root, int emp_id);
void in_order_traversal(TreeNode* root);
TreeNode* create_node(Employee employee);

int main() {
    TreeNode* root = NULL;

    // Insert employees
    root = insert(root, (Employee){1001, "Alice"});
    root = insert(root, (Employee){1003, "Bob"});
    root = insert(root, (Employee){1002, "Charlie"});
    root = insert(root, (Employee){1005, "Diana"});
    root = insert(root, (Employee){1004, "Eve"});

    // Search for an employee by emp_id
    int emp_id_to_search = 1003;
    TreeNode* result = search(root, emp_id_to_search);
    if (result != NULL) {
        printf("Employee found: ID: %d, Name: %s\n", result->employee.emp_id, result->employee.name);
    } else {
        printf("Employee with ID %d not found\n", emp_id_to_search);
    }

    // Get sorted list of employees
    printf("Employees sorted by emp_id:\n");
    in_order_traversal(root);

    return 0;
}

// Create a new TreeNode
TreeNode* create_node(Employee employee) {
    TreeNode* new_node = (TreeNode*)malloc(sizeof(TreeNode));
    new_node->employee = employee;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

// Insert a new employee into the BST
TreeNode* insert(TreeNode* root, Employee employee) {
    if (root == NULL) {
        return create_node(employee);
    }
    if (employee.emp_id < root->employee.emp_id) {
        root->left = insert(root->left, employee);
    } else {
        root->right = insert(root->right, employee);
    }
    return root;
}

// Search for an employee by emp_id
TreeNode* search(TreeNode* root, int emp_id) {
    if (root == NULL || root->employee.emp_id == emp_id) {
        return root;
    }
    if (emp_id < root->employee.emp_id) {
        return search(root->left, emp_id);
    } else {
        return search(root->right, emp_id);
    }
}

// In-order traversal to get employees sorted by emp_id
void in_order_traversal(TreeNode* root) {
    if (root != NULL) {
        in_order_traversal(root->left);
        printf("Employee ID: %d, Name: %s\n", root->employee.emp_id, root->employee.name);
        in_order_traversal(root->right);
    }
}
