#include <stdio.h>
#include <stdlib.h>

// Define a structure for the tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function for inorder traversal (left, root, right)
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);  // Traverse left subtree
        printf("%d ", root->data);     // Visit root
        inorderTraversal(root->right); // Traverse right subtree
    }
}

int main() {
    // Creating a binary tree
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    // Perform Inorder Traversal
    printf("Inorder Traversal of Binary Tree: ");
    inorderTraversal(root);
    printf("\n");

    return 0;
}
