// Application of stack 1 - Checking Balanced Parenthesis


#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Function to check if the given expression has balanced parentheses
bool isBalanced(char expression[]) {
    int len = strlen(expression);
    char stack[len];
    int top = -1;
    
    for (int i = 0; i < len; i++) {
        if (expression[i] == '(' || expression[i] == '[' || expression[i] == '{') {
            stack[++top] = expression[i];
        } else if (expression[i] == ')' || expression[i] == ']' || expression[i] == '}') {
            if (top == -1) {
                return false;
            }
            char open = stack[top--];
            if ((expression[i] == ')' && open != '(') ||
                (expression[i] == ']' && open != '[') ||
                (expression[i] == '}' && open != '{')) {
                return false;
            }
        }
    }
    return top == -1;
}

int main() {
    char expression[100];
    printf("Enter an expression: ");
    scanf("%s", expression);
    if (isBalanced(expression)) {
        printf("The expression has balanced parentheses.\n");
    } else {
        printf("The expression does not have balanced parentheses.\n");
    }
    return 0;
}
