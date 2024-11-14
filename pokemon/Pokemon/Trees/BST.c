#include <stdio.h>
#include <stdlib.h>

struct tree {
    int data;
    struct tree* left;
    struct tree* right;
};

// Function to create a new node
struct tree* create(int data) {
    struct tree* newNode = (struct tree*)malloc(sizeof(struct tree));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a node into the tree
struct tree* insert(struct tree* root, int value) {
    if (root == NULL) {
        return create(value);
    }
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    } else {
        printf("Cannot insert, the value %d already exists\n", value);
    }
    return root;
}

// In-order traversal (left, root, right)
void inOrder(struct tree* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

// Pre-order traversal (root, left, right)
void preOrder(struct tree* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

// Post-order traversal (left, right, root)
void postOrder(struct tree* root) {
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}

// Function to search for a value in the tree
struct tree* search(struct tree* root, int value) {
    if (root == NULL || root->data == value) {
        return root;
    }
    if (value < root->data) {
        return search(root->left, value);
    } else {
        return search(root->right, value);
    }
}

// Function to find the node with the minimum value
struct tree* minValueNode(struct tree* node) {
    struct tree* current = node;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

// Function to delete a node from the tree
struct tree* deleteNode(struct tree* root, int value) {
    if (root == NULL) return root;
    
    // Search for the node to delete
    if (value < root->data) {
        root->left = deleteNode(root->left, value);
    } else if (value > root->data) {
        root->right = deleteNode(root->right, value);
    } else {
        // Node to be deleted is found

        // Node with only one child or no child
        if (root->left == NULL) {
            struct tree* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct tree* temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children: Get the inorder successor (smallest in the right subtree)
        struct tree* temp = minValueNode(root->right);

        // Copy the inorder successor's content to this node
        root->data = temp->data;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

int main() {
    struct tree* root = NULL;
    int choice, value;
    
    while (1) {
        // Menu for operations
        printf("\nBinary Search Tree Operations Menu:\n");
        printf("1. Insert\n");
        printf("2. Search\n");
        printf("3. Delete\n");
        printf("4. In-Order Traversal\n");
        printf("5. Pre-Order Traversal\n");
        printf("6. Post-Order Traversal\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 7) {
            printf("Exiting the program.\n");
            break;
        }

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                break;
            case 2:
                printf("Enter value to search: ");
                scanf("%d", &value);
                if (search(root, value) != NULL) {
                    printf("Value %d found in the tree.\n", value);
                } else {
                    printf("Value %d not found in the tree.\n", value);
                }
                break;
            case 3:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                root = deleteNode(root, value);
                printf("Value %d deleted (if it existed).\n", value);
                break;
            case 4:
                printf("In-Order Traversal: ");
                inOrder(root);
                printf("\n");
                break;
            case 5:
                printf("Pre-Order Traversal: ");
                preOrder(root);
                printf("\n");
                break;
            case 6:
                printf("Post-Order Traversal: ");
                postOrder(root);
                printf("\n");
                break;
            default:
                printf("Invalid choice! Please enter a number between 1 and 7.\n");
                break;
        }
    }

    return 0;
}
