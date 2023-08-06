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
    int num_students = 0; // Variable to keep track of the number of student records

    char add_more; // Variable to hold user input (y/n) for adding more student records

    do {
        // Input student details
        printf("Enter student name: ");
        fgets(students[num_students].name, sizeof(students[num_students].name), stdin);

        printf("Enter roll number: ");
        scanf("%d", &students[num_students].roll_number);

        printf("Enter age: ");
        scanf("%d", &students[num_students].age);

        printf("Enter marks: ");
        scanf("%f", &students[num_students].marks);

        num_students++; // Increment the count of student records

        // Check if the user wants to add more student records
        printf("Do you want to add more student records? (y/n): ");
        getchar(); // Consume the newline character left by scanf
        add_more = getchar();
    } while (add_more == 'y' || add_more == 'Y');

    // Output student details
    printf("\nStudent Details:\n");
    for (int i = 0; i < num_students; i++) {
        printf("Student %d:\n", i + 1);
        printf("Name: %s", students[i].name);
        printf("Roll Number: %d\n", students[i].roll_number);
        printf("Age: %d\n", students[i].age);
        printf("Marks: %.2f\n\n", students[i].marks);
    }

    return 0;
}
