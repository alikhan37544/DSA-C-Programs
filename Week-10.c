#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int tree[MAX_SIZE];

// Initialize the tree with -1 indicating empty nodes
void initializeTree() {
    for (int i = 0; i < MAX_SIZE; i++) {
        tree[i] = -1;
    }
}

// Function to add a node to the tree
void addNode(int value, int index) {
    if (tree[index] == -1) {
        tree[index] = value;
    } else {
        if (value < tree[index]) {
            addNode(value, 2 * index + 1); // Go to left child
        } else {
            addNode(value, 2 * index + 2); // Go to right child
        }
    }
}

// Function to find the minimum value node in a subtree
int findMinValueIndex(int index) {
    if (tree[index * 2 + 1] == -1) {
        return index;
    }
    return findMinValueIndex(index * 2 + 1);
}

// Function to delete a node from the tree
void deleteNode(int value, int index) {
    if (tree[index] == -1) {
        printf("Node not found in the tree.\n");
    } else if (value < tree[index]) {
        deleteNode(value, index * 2 + 1); // Go to left child
    } else if (value > tree[index]) {
        deleteNode(value, index * 2 + 2); // Go to right child
    } else {
        // Node found, perform deletion
        if (tree[index * 2 + 1] == -1 && tree[index * 2 + 2] == -1) {
            // Case 1: Node has no children
            tree[index] = -1;
        } else if (tree[index * 2 + 1] == -1) {
            // Case 2: Node has one child (right child)
            tree[index] = tree[index * 2 + 2];
            deleteNode(tree[index * 2 + 2], index * 2 + 2);
        } else if (tree[index * 2 + 2] == -1) {
            // Case 2: Node has one child (left child)
            tree[index] = tree[index * 2 + 1];
            deleteNode(tree[index * 2 + 1], index * 2 + 1);
        } else {
            // Case 3: Node has two children
            int minValueIndex = findMinValueIndex(index * 2 + 2);
            tree[index] = tree[minValueIndex];
            deleteNode(tree[minValueIndex], minValueIndex);
        }
    }
}

// Function to perform left rotation
void leftRotate(int index) {
    int temp = tree[index * 2 + 2];
    tree[index * 2 + 2] = tree[temp * 2 + 1];
    tree[temp * 2 + 1] = tree[index];
    tree[index] = temp;
}

// Function to perform right rotation
void rightRotate(int index) {
    int temp = tree[index * 2 + 1];
    tree[index * 2 + 1] = tree[temp * 2 + 2];
    tree[temp * 2 + 2] = tree[index];
    tree[index] = temp;
}

int main() {
    initializeTree();
    // Example usage of tree operations
    addNode(50, 0);
    addNode(30, 0);
    addNode(70, 0);
    addNode(20, 0);
    addNode(40, 0);
    addNode(60, 0);
    addNode(80, 0);

    // Print the tree before operations
    printf("Tree before operations:\n");
    for (int i = 0; i < MAX_SIZE; i++) {
        if (tree[i] != -1) {
            printf("%d ", tree[i]);
        }
    }
    printf("\n");

    // Example deletion
    deleteNode(70, 0);

    // Example left rotation
    leftRotate(0);

    // Example right rotation
    rightRotate(0);

    // Print the tree after operations
    printf("Tree after operations:\n");
    for (int i = 0; i < MAX_SIZE; i++) {
        if (tree[i] != -1) {
            printf("%d ", tree[i]);
        }
    }
    printf("\n");

    return 0;
}
