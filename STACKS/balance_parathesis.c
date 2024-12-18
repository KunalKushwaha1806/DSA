#include <stdio.h>
#include <stdlib.h>

// Stack structure
struct Stack {
    int top;
    char arr[100];
};

// Function to initialize the stack
void initStack(struct Stack* stack) {
    stack->top = -1;
}

// Function to check if the stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Function to push an element onto the stack
void push(struct Stack* stack, char value) {
    stack->arr[++stack->top] = value;
}

// Function to pop an element from the stack
char pop(struct Stack* stack) {
    return stack->arr[stack->top--];
}

// Function to check if parentheses are balanced
int areParenthesesBalanced(char* expression) {
    struct Stack stack;
    initStack(&stack);

    for (int i = 0; expression[i] != '\0'; i++) {
        char current = expression[i];

        if (current == '(') {
            push(&stack, current);
        } else if (current == ')') {
            if (isEmpty(&stack)) {
                return 0;  // Unmatched closing parenthesis
            }
            pop(&stack);
        }
    }

    return isEmpty(&stack);  // If the stack is empty, parentheses are balanced
}

int main() {
    char expression[100];
    
    printf("Enter an expression: ");
    scanf("%s", expression);

    if (areParenthesesBalanced(expression)) {
        printf("Parentheses are balanced.\n");
    } else {
        printf("Parentheses are not balanced.\n");
    }

    // Example
    // Input: (A+B)*(C+D)
    // Output: Parentheses are balanced.
    
    return 0;
}
