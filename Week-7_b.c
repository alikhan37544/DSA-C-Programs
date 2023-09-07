#include <stdio.h>
#include <stdlib.h>

// Define the structure for a linked list node
struct Node {
    int data;
    struct Node *next;
};

struct Node *top = NULL; // Initialize top as NULL

// Function to check if the stack is empty
int isEmpty() {
    return top == NULL;
}

// Function to push an element onto the stack
void push(int element) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed. Cannot push.\n");
        return;
    }
    newNode->data = element;
    newNode->next = top;
    top = newNode;
    printf("Pushed element: %d\n", element);
}

// Function to pop an element from the stack
int pop() {
    if (isEmpty()) {
        printf("Stack is empty. Cannot pop.\n");
        return -1; // Return a sentinel value to indicate an error
    }
    struct Node *temp = top;
    int element = temp->data;
    top = top->next;
    free(temp);
    printf("Popped element: %d\n", element);
    return element;
}

int main() {
    int choice, element;

    do {
        // Display menu
        printf("\n--- Stack Operations Menu ---\n");
        printf("1. Push (Insert an element)\n");
        printf("2. Pop (Remove an element)\n");
        printf("3. Check if the stack is empty\n");
        printf("4. Display the stack\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to push: ");
                scanf("%d", &element);
                push(element);
                break;
            case 2:
                element = pop();
                if (element != -1) {
                    // Element popped and displayed in the pop function
                }
                break;
            case 3:
                if (isEmpty()) {
                    printf("Stack is empty.\n");
                } else {
                    printf("Stack is not empty.\n");
                }
                break;
            case 4:
                printf("Stack Elements:\n");
                struct Node *current = top;
                while (current != NULL) {
                    printf("%d\n", current->data);
                    current = current->next;
                }
                break;
            case 5:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 5);

    // Free allocated memory (if any)
    while (!isEmpty()) {
        pop();
    }

    return 0;
}
