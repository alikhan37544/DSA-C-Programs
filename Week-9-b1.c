#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

int queue[MAX_SIZE];
int front = -1, rear = -1;

// Function to check if the queue is empty
bool isEmpty() {
    return front == -1;
}

// Function to check if the queue is full
bool isFull() {
    return rear == MAX_SIZE - 1;
}

// Function to enqueue a customer into the queue
void enqueue(int customer) {
    if (isFull()) {
        printf("Queue is full. Cannot enqueue more customers.\n");
    } else {
        if (front == -1) {
            front = 0;
        }
        queue[++rear] = customer;
        printf("Customer %d joined the queue.\n", customer);
    }
}

// Function to dequeue a customer from the queue
void dequeue() {
    if (isEmpty()) {
        printf("Queue is empty. No customer to dequeue.\n");
    } else {
        int customer = queue[front++];
        printf("Customer %d checked out and left the queue.\n", customer);
        if (front > rear) {
            front = rear = -1;
        }
    }
}

int main() {
    int choice, customer;

    while (true) {
        printf("--- Supermarket Checkout System Menu ---\n");
        printf("1. Enqueue Customer\n");
        printf("2. Dequeue Customer\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter customer number: ");
                scanf("%d", &customer);
                enqueue(customer);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                printf("Exiting the supermarket checkout system.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
