#include <stdio.h>
#include <stdlib.h>

// Define the Node structure
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to insert a node in the binary tree
struct Node* insertNode(struct Node* root, int data) {
    if (root == NULL) {
        return newNode(data);  // If the tree is empty, create and return the new node
    }

    // We perform a recursive insertion
    if (data <= root->data) {
        root->left = insertNode(root->left, data);  // Insert data in the left subtree if less than or equal to current node
    } else {
        root->right = insertNode(root->right, data);  // Insert data in the right subtree if greater than current node
    }

    return root;
}

// Function for iterative inorder traversal of the binary tree
void inorderTraversal(struct Node* root) {
    if (root == NULL)
        return;

    struct Node* stack[100];  // Stack for traversal (can be dynamic in more complex scenarios)
    int top = -1;  // Stack pointer (initially empty)
    struct Node* current = root;

    while (current != NULL || top >= 0) {
        // Reach the leftmost node of the current node
        while (current != NULL) {
            stack[++top] = current;  // Push current node to stack
            current = current->left;  // Move to the left child
        }

        // Pop the top node from the stack and process it
        current = stack[top--];
        printf("%d ", current->data);  // Visit the node

        // Now, we need to process the right subtree
        current = current->right;
    }
}

int main() {
    struct Node* root = NULL;
    int n, data;

    // Get the number of nodes from the user
    printf("Enter the number of nodes in the binary tree: ");
    scanf("%d", &n);

    // Insert each node into the tree
    printf("Enter the values of the nodes:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        root = insertNode(root, data);  // Insert node into the tree
    }

    // Perform and print inorder traversal of the tree
    printf("Inorder Traversal: ");
    inorderTraversal(root);
    printf("\n");

    return 0;
}
