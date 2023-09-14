#include <stdio.h>
#include <stdlib.h>

// Define the structure for a linked list node
struct Node {
    int data;
    struct Node *next;
};

struct Node *front = NULL, *rear = NULL; // Initialize both front and rear as NULL

// Function to check if the queue is empty
int isEmpty() {
    return front == NULL;
}

// Function to enqueue an element into the queue
void enqueue(int element) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed. Cannot enqueue.\n");
        return;
    }
    newNode->data = element;
    newNode->next = NULL;
    if (rear == NULL) {
        // If the queue is empty, set both front and rear to the new node
        front = newNode;
        rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    printf("Enqueued element: %d\n", element);
}

// Function to dequeue an element from the queue
int dequeue() {
    if (isEmpty()) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1; // Return a sentinel value to indicate an error
    }
    struct Node *temp = front;
    int element = temp->data;
    front = front->next;
    free(temp);
    if (front == NULL) {
        // If the queue becomes empty after dequeue, reset rear to NULL
        rear = NULL;
    }
    printf("Dequeued element: %d\n", element);
    return element;
}

int main() {
    int choice, element;

    do {
        // Display menu
        printf("\n--- Queue Operations Menu ---\n");
        printf("1. Enqueue (Insert an element)\n");
        printf("2. Dequeue (Remove an element)\n");
        printf("3. Check if the queue is empty\n");
        printf("4. Display the queue\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to enqueue: ");
                scanf("%d", &element);
                enqueue(element);
                break;
            case 2:
                element = dequeue();
                if (element != -1) {
                    // Element dequeued and displayed in the dequeue function
                }
                break;
            case 3:
                if (isEmpty()) {
                    printf("Queue is empty.\n");
                } else {
                    printf("Queue is not empty.\n");
                }
                break;
            case 4:
                printf("Queue Elements:\n");
                struct Node *current = front;
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
    while (front != NULL) {
        dequeue();
    }

    return 0;
}
