#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100 // Maximum size of the queue

// Function to check if the queue is empty
int isEmpty(int front, int rear) {
    return front == -1;
}

// Function to check if the queue is full
int isFull(int rear, int max_size) {
    return rear == max_size - 1;
}

// Function to enqueue an element into the queue
void enqueue(int queue[], int *front, int *rear, int element) {
    if (isFull(*rear, MAX_SIZE)) {
        printf("Queue is full. Cannot enqueue more elements.\n");
        return;
    }
    if (*front == -1) {
        *front = 0; // Initialize front to 0 if it's the first element
    }
    queue[++(*rear)] = element;
    printf("Enqueued element: %d\n", element);
}

// Function to dequeue an element from the queue
int dequeue(int queue[], int *front, int *rear) {
    if (isEmpty(*front, *rear)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1; // Return a sentinel value to indicate an error
    }
    int element = queue[(*front)++];
    if (*front > *rear) {
        // Reset front and rear when the last element is dequeued
        *front = -1;
        *rear = -1;
    }
    printf("Dequeued element: %d\n", element);
    return element;
}

int main() {
    int queue[MAX_SIZE]; // Array to store the queue elements
    int front = -1, rear = -1; // Initialize both front and rear as -1
    int choice, element;

    do {
        // Display menu
        printf("\n--- Queue Operations Menu ---\n");
        printf("1. Enqueue (Insert an element)\n");
        printf("2. Dequeue (Remove an element)\n");
        printf("3. Check if the queue is empty\n");
        printf("4. Check if the queue is full\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to enqueue: ");
                scanf("%d", &element);
                enqueue(queue, &front, &rear, element);
                break;
            case 2:
                element = dequeue(queue, &front, &rear);
                if (element != -1) {
                    // Element dequeued and displayed in the dequeue function
                }
                break;
            case 3:
                if (isEmpty(front, rear)) {
                    printf("Queue is empty.\n");
                } else {
                    printf("Queue is not empty.\n");
                }
                break;
            case 4:
                if (isFull(rear, MAX_SIZE)) {
                    printf("Queue is full.\n");
                } else {
                    printf("Queue is not full.\n");
                }
                break;
            case 5:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 5);

    return 0;
}
