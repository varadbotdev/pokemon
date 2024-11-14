#include <stdio.h>
#include <stdlib.h>

// Structure for a binary tree node
struct TreeNode {
    int value;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to create a new tree node
struct TreeNode* createNode(int value) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to create a binary tree by user input (no queue used)
struct TreeNode* createTree() {
    int value;
    printf("Enter the value for the node (-1 to stop): ");
    scanf("%d", &value);
    
    // If the user enters -1, stop creating tree (indicating no node)
    if (value == -1) {
        return NULL;
    }
    
    // Create the root node
    struct TreeNode* root = createNode(value);
    
    // Recursively create left and right subtrees
    printf("Enter the value for the left child of %d (-1 for no child): ", value);
    root->left = createTree();
    
    printf("Enter the value for the right child of %d (-1 for no child): ", value);
    root->right = createTree();
    
    return root;
}

// Function to perform iterative postorder traversal
void postorderIterative(struct TreeNode* root) {
    if (root == NULL) {
        return;
    }

    struct TreeNode* stack1[100];  // First stack to store nodes
    struct TreeNode* stack2[100];  // Second stack to store postorder result
    int top1 = -1, top2 = -1;

    // Push the root to stack1
    stack1[++top1] = root;

    while (top1 >= 0) {
        // Pop from stack1
        struct TreeNode* current = stack1[top1--];
        
        // Push current node to stack2
        stack2[++top2] = current;

        // Push left and right children of the popped node to stack1
        if (current->left != NULL) {
            stack1[++top1] = current->left;
        }
        if (current->right != NULL) {
            stack1[++top1] = current->right;
        }
    }

    // Pop from stack2 to get the postorder
    while (top2 >= 0) {
        struct TreeNode* current = stack2[top2--];
        printf("%d ", current->value);
    }
}

int main() {
    struct TreeNode* root = createTree();  // Create binary tree based on user input

    printf("\nIterative Postorder Traversal: ");
    postorderIterative(root);  // Perform iterative postorder traversal
    printf("\n");

    return 0;
}
