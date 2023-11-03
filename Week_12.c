#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ORDER 3

// Structure for a B-Tree node
struct BTreeNode {
    int *keys;
    struct BTreeNode **children;
    bool isLeaf;
    int numKeys;
};

// Function to create a new B-Tree node
struct BTreeNode* createBTreeNode(bool isLeaf) {
    struct BTreeNode* newNode = (struct BTreeNode*)malloc(sizeof(struct BTreeNode));
    if (!newNode) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    newNode->keys = (int*)malloc((2 * ORDER - 1) * sizeof(int));
    if (!newNode->keys) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    newNode->children = (struct BTreeNode**)malloc(2 * ORDER * sizeof(struct BTreeNode*));
    if (!newNode->children) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    newNode->isLeaf = isLeaf;
    newNode->numKeys = 0;
    return newNode;
}

// Function to split a child node in the B-Tree
void splitChild(struct BTreeNode* parent, int index) {
    struct BTreeNode* child = parent->children[index];
    struct BTreeNode* newChild = createBTreeNode(child->isLeaf);
    parent->children[parent->numKeys + 1] = parent->children[parent->numKeys];
    for (int j = parent->numKeys; j > index; j--) {
        parent->keys[j] = parent->keys[j - 1];
        parent->children[j] = parent->children[j - 1];
    }
    parent->keys[index] = child->keys[ORDER - 1];
    parent->children[index + 1] = newChild;
    newChild->numKeys = ORDER - 1;
    child->numKeys = ORDER - 1;
    for (int j = 0; j < ORDER - 1; j++) {
        newChild->keys[j] = child->keys[j + ORDER];
    }
    if (!child->isLeaf) {
        for (int j = 0; j < ORDER; j++) {
            newChild->children[j] = child->children[j + ORDER];
        }
    }
    parent->numKeys++;
}

// Function to insert a key into the B-Tree
struct BTreeNode* insert(struct BTreeNode* root, int key) {
    if (root->numKeys == 2 * ORDER - 1) {
        struct BTreeNode* newRoot = createBTreeNode(false);
        newRoot->children[0] = root;
        splitChild(newRoot, 0);
        insertNonFull(newRoot, key);
        return newRoot;
    } else {
        insertNonFull(root, key);
        return root;
    }
}

// Function to insert a key into a non-full B-Tree node
void insertNonFull(struct BTreeNode* node, int key) {
    int i = node->numKeys - 1;
    if (node->isLeaf) {
        while (i >= 0 && key < node->keys[i]) {
            node->keys[i + 1] = node->keys[i];
            i--;
        }
        node->keys[i + 1] = key;
        node->numKeys++;
    } else {
        while (i >= 0 && key < node->keys[i]) {
            i--;
        }
        i++;
        if (node->children[i]->numKeys == 2 * ORDER - 1) {
            splitChild(node, i);
            if (key > node->keys[i]) {
                i++;
            }
        }
        insertNonFull(node->children[i], key);
    }
}

// Function to search for a key in the B-Tree
bool search(struct BTreeNode* root, int key) {
    int i = 0;
    while (i < root->numKeys && key > root->keys[i]) {
        i++;
    }
    if (i < root->numKeys && key == root->keys[i]) {
        return true;
    }
    if (root->isLeaf) {
        return false;
    }
    return search(root->children[i], key);
}

// Function to traverse and print the B-Tree (In-order traversal)
void inOrderTraversal(struct BTreeNode* root) {
    if (root) {
        int i;
        for (i = 0; i < root->numKeys; i++) {
            inOrderTraversal(root->children[i]);
            printf("%d ", root->keys[i]);
        }
        inOrderTraversal(root->children[i]);
    }
}

// Function to free memory used by the B-Tree nodes
void cleanupBTree(struct BTreeNode* root) {
    if (root) {
        int i;
        for (i = 0; i < root->numKeys + 1; i++) {
            cleanupBTree(root->children[i]);
        }
        free(root->keys);
        free(root->children);
        free(root);
    }
}

int main() {
    struct BTreeNode* root = createBTreeNode(true);

    // Example: Insert keys into the B-Tree
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 5);
    root = insert(root, 6);
    root = insert(root, 12);

    // Example: Search for a key in the B-Tree
    int keyToSearch = 20;
    if (search(root, keyToSearch)) {
        printf("Key %d found in the B-Tree.\n", keyToSearch);
    } else {
        printf("Key %d not found in the B-Tree.\n", keyToSearch);
    }

    // Example: Traverse and print the B-Tree (In-order)
    printf("B-Tree elements: ");
    inOrderTraversal(root);
    printf("\n");

    // Cleanup: Free allocated memory
    cleanupBTree(root);

    return 0;
}
