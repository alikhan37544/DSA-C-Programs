#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Structure for a node in the binary search tree
struct BSTNode {
    int key;
    struct Node* list; // Pointer to the linked list
    struct BSTNode* left;
    struct BSTNode* right;
};

// Function to create a new linked list node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to create a new BST node
struct BSTNode* createBSTNode(int key, int data) {
    struct BSTNode* newNode = (struct BSTNode*)malloc(sizeof(struct BSTNode));
    if (newNode == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    newNode->key = key;
    newNode->list = createNode(data);
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a new element into the linked list
void insertLinkedList(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to insert a new node into the binary search tree
struct BSTNode* insertBST(struct BSTNode* root, int key, int data) {
    if (root == NULL) {
        return createBSTNode(key, data);
    }

    if (key < root->key) {
        root->left = insertBST(root->left, key, data);
    } else if (key > root->key) {
        root->right = insertBST(root->right, key, data);
    } else {
        // Key already exists, insert into the linked list
        insertLinkedList(&(root->list), data);
    }

    return root;
}

// Function to print the linked list at a BST node
void printLinkedList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to print the BST using in-order traversal
void inOrderTraversal(struct BSTNode* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("Key: %d, Linked List: ", root->key);
        printLinkedList(root->list);
        inOrderTraversal(root->right);
    }
}

// Function to cleanup the linked lists
void cleanupLinkedLists(struct BSTNode* root) {
    if (root != NULL) {
        cleanupLinkedLists(root->left);
        cleanupLinkedLists(root->right);
        struct Node* current = root->list;
        while (current != NULL) {
            struct Node* temp = current;
            current = current->next;
            free(temp);
        }
    }
}

// Function to cleanup the BST nodes
void cleanupBST(struct BSTNode* root) {
    cleanupLinkedLists(root);
    free(root);
}

int main() {
    struct BSTNode* root = NULL;

    // Insert elements into the BST with linked lists
    root = insertBST(root, 50, 5);
    root = insertBST(root, 30, 3);
    root = insertBST(root, 70, 7);
    root = insertBST(root, 50, 8); // Adding to the same key

    // Print the BST with linked lists
    printf("Binary Search Tree with Linked Lists:\n");
    inOrderTraversal(root);

    // Clean up: free the memory used by the linked lists and BST nodes
    cleanupBST(root);

    return 0;
}
