#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the binary tree
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

// Function for in-order traversal (Left - Root - Right)
void inorder(struct node *root) {
    if (root != NULL) {
        inorder(root->left_child);
        printf("%d ", root->data);
        inorder(root->right_child);
    }
}

// Function for pre-order traversal (Root - Left - Right)
void preorder(struct node *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left_child);
        preorder(root->right_child);
    }
}

// Function for post-order traversal (Left - Right - Root)
void postorder(struct node *root) {
    if (root != NULL) {
        postorder(root->left_child);
        postorder(root->right_child);
        printf("%d ", root->data);
    }
}

// Main function to demonstrate the traversals
int main() {
    // Create nodes
    struct node *root = new_node(10);
    root->left_child = new_node(5);
    root->right_child = new_node(15);
    root->left_child->left_child = new_node(2);
    root->left_child->right_child = new_node(7);
    root->right_child->left_child = new_node(12);
    root->right_child->right_child = new_node(20);

    // Print traversals
    printf("In-order traversal: ");
    inorder(root);
    printf("\n");

    printf("Pre-order traversal: ");
    preorder(root);
    printf("\n");

    printf("Post-order traversal: ");
    postorder(root);
    printf("\n");

    return 0;
}
