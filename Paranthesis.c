#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SIZE 100

// Stack implementation
char stack[MAX_SIZE];
int top = -1;

// Push function
void push(char c) {
    if (top < MAX_SIZE - 1) {
        stack[++top] = c;
    }
}

// Pop function
char pop() {
    if (top >= 0) {
        return stack[top--];
    }
    return '\0';  // Return null character if stack is empty
}

// Check if the given character is a matching pair
bool isMatchingPair(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

// Function to check if parentheses are valid
bool isValidParentheses(const char *str) {
    for (int i = 0; i < strlen(str); i++) {
        char current = str[i];

        if (current == '(' || current == '{' || current == '[') {
            push(current);  // Push opening brackets onto the stack
        } else if (current == ')' || current == '}' || current == ']') {
            char lastOpen = pop();
            if (!isMatchingPair(lastOpen, current)) {
                return false;  // Mismatched pair found
            }
        }
    }
    return top == -1;  // Stack should be empty for a valid expression
}

int main() {
    char input[MAX_SIZE];

    printf("Enter a string of parentheses: ");
    scanf("%s", input);

    if (isValidParentheses(input)) {
        printf("The string of parentheses is valid.\n");
    } else {
        printf("The string of parentheses is invalid.\n");
    }

    return 0;
}
