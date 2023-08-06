#include <stdio.h>
#include <string.h>

// Define the structure
struct Student {
    char name[50];
    int roll_number;
    int age;
    float marks;
};

int main() {
    struct Student students[100]; // Array to store multiple student records
    struct Student *ptr_student; // Pointer to a structure
    int num_students = 0; // Variable to keep track of the number of student records

    char add_more; // Variable to hold user input (y/n) for adding more student records

    do {
        ptr_student = &students[num_students]; // Point the pointer to the current structure variable

        // Input student details using pointers
        printf("Enter student name: ");
        fgets(ptr_student->name, sizeof(ptr_student->name), stdin);

        printf("Enter roll number: ");
        scanf("%d", &ptr_student->roll_number);

        printf("Enter age: ");
        scanf("%d", &ptr_student->age);

        printf("Enter marks: ");
        scanf("%f", &ptr_student->marks);

        num_students++; // Increment the count of student records

        // Check if the user wants to add more student records
        printf("Do you want to add more student records? (y/n): ");
        getchar(); // Consume the newline character left by scanf
        add_more = getchar();
    } while (add_more == 'y' || add_more == 'Y');

    // Output student details using pointers
    printf("\nStudent Details:\n");
    for (int i = 0; i < num_students; i++) {
        ptr_student = &students[i]; // Point the pointer to the current structure variable

        printf("Student %d:\n", i + 1);
        printf("Name: %s", ptr_student->name);
        printf("Roll Number: %d\n", ptr_student->roll_number);
        printf("Age: %d\n", ptr_student->age);
        printf("Marks: %.2f\n\n", ptr_student->marks);
    }

    return 0;
}
