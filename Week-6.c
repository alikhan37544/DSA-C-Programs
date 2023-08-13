#include <stdio.h>
#include <stdlib.h>

// Define the structure for a doubly linked list node
struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

// Function to display the elements of the doubly linked list
void displayList(struct Node *head) {
    struct Node *current = head;
    printf("Doubly Linked List Elements: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Function to insert an element at the beginning of the doubly linked list
struct Node* insertBeginning(struct Node *head, int element) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = element;
    newNode->prev = NULL;
    newNode->next = head;

    if (head != NULL) {
        head->prev = newNode;
    }

    return newNode;
}

// Function to insert an element at the end of the doubly linked list
struct Node* insertEnd(struct Node *head, int element) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = element;
    newNode->next = NULL;

    if (head == NULL) {
        newNode->prev = NULL;
        return newNode;
    }

    struct Node *current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    newNode->prev = current;

    return head;
}

// Function to delete an element from the doubly linked list
struct Node* deleteElement(struct Node *head, int element) {
    struct Node *current = head;
    while (current != NULL && current->data != element) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Element %d not found in the list.\n", element);
        return head;
    }

    if (current->prev != NULL) {
        current->prev->next = current->next;
    } else {
        head = current->next;
    }

    if (current->next != NULL) {
        current->next->prev = current->prev;
    }

    free(current);
    return head;
}

int main() {
    struct Node *head = NULL; // Pointer to the first node of the doubly linked list
    int choice, element;

    do {
        // Display menu
        printf("\n--- Doubly Linked List Operations ---\n");
        printf("1. Display Doubly Linked List\n");
        printf("2. Insert at Beginning\n");
        printf("3. Insert at End\n");
        printf("4. Delete Element\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayList(head);
                break;
            case 2:
                printf("Enter the element to insert at the beginning: ");
                scanf("%d", &element);
                head = insertBeginning(head, element);
                break;
            case 3:
                printf("Enter the element to insert at the end: ");
                scanf("%d", &element);
                head = insertEnd(head, element);
                break;
            case 4:
                printf("Enter the element to delete: ");
                scanf("%d", &element);
                head = deleteElement(head, element);
                break;
            case 5:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 5);

    // Free allocated memory
    struct Node *current = head;
    while (current != NULL) {
        struct Node *temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}
