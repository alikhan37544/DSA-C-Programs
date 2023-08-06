#include <stdio.h>

#define MAX_SIZE 100 // Maximum size of the list

// Function to display the elements of the list
void displayList(int list[], int size) {
    printf("List Elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", list[i]);
    }
    printf("\n");
}

// Function to add an element to the list
void addElement(int list[], int *size, int element) {
    if (*size >= MAX_SIZE) {
        printf("List is full. Cannot add more elements.\n");
        return;
    }

    list[*size] = element;
    (*size)++;
}

// Function to remove an element from the list
void removeElement(int list[], int *size, int element) {
    int found = 0;
    for (int i = 0; i < *size; i++) {
        if (list[i] == element) {
            found = 1;
            // Move elements to the left to overwrite the removed element
            for (int j = i; j < *size - 1; j++) {
                list[j] = list[j + 1];
            }
            (*size)--;
            break;
        }
    }
    if (!found) {
        printf("Element %d not found in the list.\n", element);
    }
}

int main() {
    int list[MAX_SIZE]; // Array to store the list elements
    int size = 0; // Variable to keep track of the number of elements in the list
    int choice, element;

    do {
        // Display menu
        printf("\n--- List Operations ---\n");
        printf("1. Display List\n");
        printf("2. Add Element to List\n");
        printf("3. Remove Element from List\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayList(list, size);
                break;
            case 2:
                printf("Enter the element to add: ");
                scanf("%d", &element);
                addElement(list, &size, element);
                break;
            case 3:
                printf("Enter the element to remove: ");
                scanf("%d", &element);
                removeElement(list, &size, element);
                break;
            case 4:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 4);

    return 0;
}
