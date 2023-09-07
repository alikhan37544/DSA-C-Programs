#include <stdio.h>
#include <stdlib.h>

// Structure for a stack node
struct Node {
    int data;
    struct Node *next;
};

// Structure for the linked list-based stack
struct Stack {
    struct Node *top;
};

// Function to check if the stack is empty
int isEmpty(struct Stack *stack) {
    return stack->top == NULL;
}

// Function to push an element onto the stack
void push(struct Stack *stack, int element) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = element;
    newNode->next = stack->top;
    stack->top = newNode;
}

// Function to pop an element from the stack
int pop(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty. Cannot pop elements.\n");
        return -1; // Return a sentinel value
    }
    struct Node *temp = stack->top;
    int element = temp->data;
    stack->top = stack->top->next;
    free(temp);
    return element;
}

// Function to display the elements of the stack
void displayStack(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack Elements: ");
    struct Node *current = stack->top;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct Stack stack;
    stack.top = NULL; // Initialize the top of the stack

    int choice, element;

    do {
        // Display menu
        printf("\n--- Stack Operations (Linked List-based) ---\n");
        printf("1. Push Element\n");
        printf("2. Pop Element\n");
        printf("3. Display Stack\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to push: ");
                scanf("%d", &element);
                push(&stack, element);
                break;
            case 2:
                element = pop(&stack);
                if (element != -1) {
                    printf("Popped element: %d\n", element);
                }
                break;
            case 3:
                displayStack(&stack);
                break;
            case 4:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 4);

    // Free allocated memory (for Linked List-based stack)
    struct Node *current = stack.top;
    while (current != NULL) {
        struct Node *temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}
