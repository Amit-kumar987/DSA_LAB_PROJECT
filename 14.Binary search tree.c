#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *left, *right;
} Node;

Node* newNode(int x) {
    Node* t = (Node*)malloc(sizeof(Node));
    t->data = x;
    t->left = t->right = NULL;
    return t;
}

Node* insert(Node* root, int x) {
    if (root == NULL) return newNode(x);
    if (x < root->data) root->left = insert(root->left, x);
    else root->right = insert(root->right, x);
    return root;
}

Node* minValue(Node* root) {
    while (root->left != NULL) root = root->left;
    return root;
}

Node* delete(Node* root, int x) {
    if (root == NULL) return root;

    if (x < root->data)
        root->left = delete(root->left, x);
    else if (x > root->data)
        root->right = delete(root->right, x);
    else {
        if (root->left == NULL) {
            Node* t = root->right;
            free(root);
            return t;
        }
        else if (root->right == NULL) {
            Node* t = root->left;
            free(root);
            return t;
        }
        Node* t = minValue(root->right);
        root->data = t->data;
        root->right = delete(root->right, t->data);
    }
    return root;
}

void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main() {
    Node* root = NULL;

    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    printf("First BST: ");
    inorder(root);
    printf("\n");

    root = insert(root, 55);
    printf("After insertion (55): ");
    inorder(root);
    printf("\n");

    root = delete(root, 30);
    printf("After deletion (30): ");
    inorder(root);
    printf("\n");

    return 0;
}
