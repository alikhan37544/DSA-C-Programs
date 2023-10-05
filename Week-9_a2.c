// Reversing a string using a stack


#include <stdio.h>
#include <string.h>

// Function to reverse a string using a stack
void reverseString(char str[]) {
    int len = strlen(str);
    char stack[len];
    int top = -1;

    // Push characters onto the stack
    for (int i = 0; i < len; i++) {
        stack[++top] = str[i];
    }

    // Pop characters and overwrite the original string
    for (int i = 0; i < len; i++) {
        str[i] = stack[top--];
    }
}

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);
    reverseString(str);
    printf("Reversed string: %s\n", str);
    return 0;
}
