#include <stdio.h>

#define MAX_SIZE 100

int tree[MAX_SIZE];

// Function to insert a node in the binary tree
void insert(int value, int index) {
    if (tree[index] == -1) {
        tree[index] = value;
    } else {
        if (value < tree[index]) {
            insert(value, 2 * index + 1); // Go to left child
        } else {
            insert(value, 2 * index + 2); // Go to right child
        }
    }
}

// Function to print the binary tree using in-order traversal
void inorderTraversal(int index) {
    if (tree[index] != -1) {
        inorderTraversal(2 * index + 1); // Print left subtree
        printf("%d ", tree[index]); // Print root
        inorderTraversal(2 * index + 2); // Print right subtree
    }
}

int main() {
    for (int i = 0; i < MAX_SIZE; i++) {
        tree[i] = -1; // Initialize tree nodes as -1 (indicating empty nodes)
    }

    int n;
    printf("Enter the number of elements in the tree: ");
    scanf("%d", &n);

    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        int value;
        scanf("%d", &value);
        insert(value, 0); // Start insertion from the root (index 0)
    }

    printf("In-order traversal of the tree: ");
    inorderTraversal(0); // Start traversal from the root (index 0)
    printf("\n");

    return 0;
}
