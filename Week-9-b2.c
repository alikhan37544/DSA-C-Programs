// Implementing a print spooler


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

int queue[MAX_SIZE];
int front = -1, rear = -1;

void enqueue(int job) {
    if (rear == MAX_SIZE - 1) {
        printf("Print spooler is full. Cannot enqueue more print jobs.\n");
    } else {
        if (front == -1) {
            front = 0;
        }
        queue[++rear] = job;
        printf("Print job %d enqueued.\n", job);
    }
}

void dequeue() {
    if (front == -1) {
        printf("Print spooler is empty. No print job to dequeue.\n");
    } else {
        int job = queue[front++];
        printf("Print job %d dequeued and printed.\n", job);
        if (front > rear) {
            front = rear = -1;
        }
    }
}

int main() {
    int choice, job;
    while (true) {
        printf("--- Print Spooler Menu ---\n");
        printf("1. Enqueue Print Job\n");
        printf("2. Dequeue and Print Job\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the print job number: ");
                scanf("%d", &job);
                enqueue(job);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                printf("Exiting the print spooler.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
