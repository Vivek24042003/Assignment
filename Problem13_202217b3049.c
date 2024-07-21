#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the binary search tree
struct node {
    int data;
    struct node *left_child;
    struct node *right_child;
};

// Function to create a new node
struct node* new_node(int x) {
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = x;
    temp->left_child = NULL;
    temp->right_child = NULL;
    return temp;
}

// Function to insert a node into the binary search tree
struct node* insert(struct node *root, int x) {
    if (root == NULL) {
        return new_node(x);
    }
    if (x > root->data) {
        root->right_child = insert(root->right_child, x);
    } else {
        root->left_child = insert(root->left_child, x);
    }
    return root;
}

// Function to search for a node in the binary search tree
struct node* search(struct node *root, int x) {
    if (root == NULL || root->data == x) {
        return root;
    }
    if (x > root->data) {
        return search(root->right_child, x);
    } else {
        return search(root->left_child, x);
    }
}

// Function to find the minimum value node in a subtree
struct node* find_minimum(struct node *root) {
    if (root == NULL) {
        return NULL;
    }
    while (root->left_child != NULL) {
        root = root->left_child;
    }
    return root;
}

// Function to delete a node from the binary search tree
struct node* delete(struct node *root, int x) {
    if (root == NULL) {
        return NULL;
    }
    if (x > root->data) {
        root->right_child = delete(root->right_child, x);
    } else if (x < root->data) {
        root->left_child = delete(root->left_child, x);
    } else {
        if (root->left_child == NULL && root->right_child == NULL) {
            free(root);
            return NULL;
        } else if (root->left_child == NULL || root->right_child == NULL) {
            struct node *temp = root->left_child ? root->left_child : root->right_child;
            free(root);
            return temp;
        } else {
            struct node *temp = find_minimum(root->right_child);
            root->data = temp->data;
            root->right_child = delete(root->right_child, temp->data);
        }
    }
    return root;
}

// In-order traversal of the binary search tree
void inorder(struct node *root) {
    if (root != NULL) {
        inorder(root->left_child);
        printf(" %d ", root->data);
        inorder(root->right_child);
    }
}

// Main function to demonstrate BST operations
int main() {
    struct node *root = NULL;
    
    // Insert nodes into the binary search tree
    root = insert(root, 45);
    root = insert(root, 15);
    root = insert(root, 79);
    root = insert(root, 90);
    root = insert(root, 10);
    root = insert(root, 55);
    root = insert(root, 12);
    root = insert(root, 20);
    root = insert(root, 50);
    
    // Display the binary search tree
    printf("In-order traversal of the BST:\n");
    inorder(root);
    printf("\n");
    
    // Search for specific nodes
    struct node *search_result = search(root, 20);
    if (search_result) {
        printf("Node 20 found in the BST.\n");
    } else {
        printf("Node 20 not found in the BST.\n");
    }
    
    search_result = search(root, 100);
    if (search_result) {
        printf("Node 100 found in the BST.\n");
    } else {
        printf("Node 100 not found in the BST.\n");
    }
    
    // Delete nodes from the binary search tree
    printf("Deleting nodes 10, 55, and 45.\n");
    root = delete(root, 10);
    root = delete(root, 55);
    root = delete(root, 45);
    
    // Display the binary search tree after deletion
    printf("In-order traversal of the BST after deletions:\n");
    inorder(root);
    printf("\n");
    
    return 0;
}
