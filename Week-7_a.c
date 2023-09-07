#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100 // Maximum size of the stack

// Function to check if the stack is empty
int isEmpty(int top) {
    return top == -1;
}

// Function to check if the stack is full
int isFull(int top, int max_size) {
    return top == max_size - 1;
}

// Function to push an element onto the stack
void push(int stack[], int *top, int element) {
    if (isFull(*top, MAX_SIZE)) {
        printf("Stack is full. Cannot push more elements.\n");
        return;
    }
    stack[++(*top)] = element;
    printf("Pushed element: %d\n", element);
}

// Function to pop an element from the stack
int pop(int stack[], int *top) {
    if (isEmpty(*top)) {
        printf("Stack is empty. Cannot pop.\n");
        return -1; // Return a sentinel value to indicate an error
    }
    int element = stack[(*top)--];
    printf("Popped element: %d\n", element);
    return element;
}

int main() {
    int stack[MAX_SIZE]; // Array to store the stack elements
    int top = -1; // Initialize top as -1
    int choice, element;

    do {
        // Display menu
        printf("\n--- Stack Operations Menu ---\n");
        printf("1. Push (Insert an element)\n");
        printf("2. Pop (Remove an element)\n");
        printf("3. Check if the stack is empty\n");
        printf("4. Check if the stack is full\n");
        printf("5. Display the stack\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to push: ");
                scanf("%d", &element);
                push(stack, &top, element);
                break;
            case 2:
                element = pop(stack, &top);
                if (element != -1) {
                    printf("Popped element: %d\n", element); // Display the popped element
                    // You can perform additional operations with 'element' here
                } else {
                    printf("Stack is empty. Unable to pop.\n");
                }
                break;
            case 3:
                if (isEmpty(top)) {
                    printf("Stack is empty.\n");
                } else {
                    printf("Stack is not empty.\n");
                }
                break;
            case 4:
                if (isFull(top, MAX_SIZE)) {
                    printf("Stack is full.\n");
                } else {
                    printf("Stack is not full.\n");
                }
                break;
            case 5:
                printf("Stack Elements:\n");
                for (int i = top; i >= 0; i--) {
                    printf("%d\n", stack[i]);
                }
                break;
            case 6:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 6);

    return 0;
}
