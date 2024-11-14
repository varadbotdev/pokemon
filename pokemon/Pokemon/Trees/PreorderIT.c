#include <stdio.h>
#include <stdlib.h>

// Define the Node structure
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    if (!node) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to insert a node in the binary tree
struct Node* insertNode(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);  // Create a new node if the root is NULL
    }

    // Insert data recursively based on value
    if (data <= root->data) {
        root->left = insertNode(root->left, data);  // Insert in left subtree if data is less than or equal to the root
    } else {
        root->right = insertNode(root->right, data);  // Insert in right subtree if data is greater than root
    }
    return root;
}

// Function for iterative preorder traversal of the binary tree
void iterativePreorderTraversal(struct Node* root) {
    if (root == NULL) return;

    struct Node* stack[100];  // Stack for traversal (can be dynamic in more complex scenarios)
    int top = -1;  // Stack pointer (initially empty)
    stack[++top] = root;  // Push the root to start traversal

    while (top >= 0) {
        struct Node* currentNode = stack[top--];  // Pop a node from the stack
        printf("%d ", currentNode->data);  // Visit and print the node

        // Push right child first so that left child is processed first
        if (currentNode->right) {
            stack[++top] = currentNode->right;
        }
        if (currentNode->left) {
            stack[++top] = currentNode->left;
        }
    }
}

int main() {
    struct Node* root = NULL;
    int n, data;

    // Prompt the user for the number of nodes
    printf("Enter the number of nodes in the binary tree: ");
    scanf("%d", &n);

    // Insert each node into the tree
    printf("Enter the values of the nodes:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        root = insertNode(root, data);  // Insert node in the tree
    }

    // Perform and print preorder traversal of the tree
    printf("Preorder Traversal: ");
    iterativePreorderTraversal(root);
    printf("\n");

    return 0;
}





























// #include <stdio.h>
// #include <stdlib.h>

// // Structure for a binary tree node
// struct TreeNode {
//     int value;
//     struct TreeNode* left;
//     struct TreeNode* right;
// };

// // Function to create a new tree node
// struct TreeNode* createNode(int value) {
//     struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
//     if (!newNode) {
//         printf("Memory allocation failed!\n");
//         return NULL;
//     }
//     newNode->value = value;
//     newNode->left = NULL;
//     newNode->right = NULL;
//     return newNode;
// }

// // Function to perform iterative preorder traversal
// void preorderIterative(struct TreeNode* root) {
//     if (root == NULL) {
//         return;
//     }
    
//     // Stack to store nodes during traversal
//     struct TreeNode* stack[100];  // Static stack for simplicity (size 100 for example)
//     int top = -1;  // Stack pointer
    
//     // Push root to the stack
//     stack[++top] = root;
    
//     while (top >= 0) {
//         // Pop the node from the stack
//         struct TreeNode* current = stack[top--];
        
//         // Print the current node's value
//         printf("%d ", current->value);
        
//         // Push right child first (so left child is processed first)
//         if (current->right != NULL) {
//             stack[++top] = current->right;
//         }
        
//         // Push left child to the stack
//         if (current->left != NULL) {
//             stack[++top] = current->left;
//         }
//     }
// }

// // Function to create a binary tree by user input
// struct TreeNode* createTree() {
//     int value;
//     printf("Enter the value for the root node: ");
//     scanf("%d", &value);
//     struct TreeNode* root = createNode(value);

//     // Queue to store nodes for level-wise insertion
//     struct TreeNode* queue[100];
//     int front = 0, rear = 0;

//     // Enqueue the root
//     queue[rear++] = root;

//     while (front < rear) {
//         struct TreeNode* current = queue[front++];

//         // Input left child
//         printf("Enter the value for the left child of %d (enter -1 for no child): ", current->value);
//         scanf("%d", &value);
//         if (value != -1) {
//             current->left = createNode(value);
//             queue[rear++] = current->left;
//         }

//         // Input right child
//         printf("Enter the value for the right child of %d (enter -1 for no child): ", current->value);
//         scanf("%d", &value);
//         if (value != -1) {
//             current->right = createNode(value);
//             queue[rear++] = current->right;
//         }
//     }

//     return root;
// }

// int main() {
//     struct TreeNode* root = createTree();  // Create binary tree based on user input

//     printf("\nIterative Preorder Traversal: ");
//     preorderIterative(root);  // Perform iterative preorder traversal
//     printf("\n");

//     return 0;
// }
