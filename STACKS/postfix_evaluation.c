#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Stack structure for integers
struct Stack {
    int top;
    int arr[100];
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
void push(struct Stack* stack, int value) {
    stack->arr[++stack->top] = value;
}

// Function to pop an element from the stack
int pop(struct Stack* stack) {
    return stack->arr[stack->top--];
}

// Function to evaluate a postfix expression
int evaluatePostfix(char* postfix) {
    struct Stack stack;
    initStack(&stack);

    for (int i = 0; postfix[i] != '\0'; i++) {
        char current = postfix[i];

        if (isdigit(current)) {
            push(&stack, current - '0');  // Convert char to integer and push
        } else {
            int operand2 = pop(&stack);
            int operand1 = pop(&stack);

            switch (current) {
                case '+': push(&stack, operand1 + operand2); break;
                case '-': push(&stack, operand1 - operand2); break;
                case '*': push(&stack, operand1 * operand2); break;
                case '/': push(&stack, operand1 / operand2); break;
            }
        }
    }

    return pop(&stack);  // The result is the only value left in the stack
}

int main() {
    char postfix[100];
    
    printf("Enter postfix expression: ");
    scanf("%s", postfix);

    int result = evaluatePostfix(postfix);
    
    printf("Result: %d\n", result);

    // Example
    // Input: 23*54*+9-
    // Output: 17
    
    return 0;
}
