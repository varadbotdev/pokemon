#include <stdio.h>
#include <stdlib.h>

// Structure for the tree node
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a node into the binary tree
struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data); // If tree is empty, create a new node
    }

    if (data < root->data) {
        root->left = insert(root->left, data); // Insert in left subtree
    } else {
        root->right = insert(root->right, data); // Insert in right subtree
    }
    return root;
}

// Preorder Traversal (Root -> Left -> Right)
void preorder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data); // Visit root
        preorder(root->left); // Traverse left subtree
        preorder(root->right); // Traverse right subtree
    }
}

// Inorder Traversal (Left -> Root -> Right)
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left); // Traverse left subtree
        printf("%d ", root->data); // Visit root
        inorder(root->right); // Traverse right subtree
    }
}

// Postorder Traversal (Left -> Right -> Root)
void postorder(struct Node* root) {
    if (root != NULL) {
        postorder(root->left); // Traverse left subtree
        postorder(root->right); // Traverse right subtree
        printf("%d ", root->data); // Visit root
    }
}

int main() {
    struct Node* root = NULL;
    int choice, value;

    while(1) {
        // Display menu
        printf("\nBinary Tree Operations Menu:\n");
        printf("1. Insert\n");
        printf("2. Preorder Traversal\n");
        printf("3. Inorder Traversal\n");
        printf("4. Postorder Traversal\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                // Insert a node
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                break;

            case 2:
                // Preorder traversal
                printf("Preorder Traversal: ");
                preorder(root);
                printf("\n");
                break;

            case 3:
                // Inorder traversal
                printf("Inorder Traversal: ");
                inorder(root);
                printf("\n");
                break;

            case 4:
                // Postorder traversal
                printf("Postorder Traversal: ");
                postorder(root);
                printf("\n");
                break;

            case 5:
                // Exit the program
                printf("Exiting the program.\n");
                exit(0);

            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}
