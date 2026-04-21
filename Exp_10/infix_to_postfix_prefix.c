#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

// Stack for operators
char stack[MAX];
int top = -1;

// Temporary variable counter for TAC
int tempCount = 1;

// Push & Pop functions
void push(char c) {
    if(top < MAX-1) stack[++top] = c;
}

char pop() {
    if(top >= 0) return stack[top--];
    return '\0';
}

char peek() {
    if(top >= 0) return stack[top];
    return '\0';
}

// Precedence function
int precedence(char op) {
    if(op == '+' || op == '-') return 1;
    if(op == '*' || op == '/') return 2;
    return 0;
}

// Check if operator
int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Infix to Postfix
void infixToPostfix(char infix[], char postfix[]) {
    int k = 0;
    for(int i = 0; i < strlen(infix); i++) {
        char c = infix[i];
        if(isalnum(c)) {
            postfix[k++] = c;
        } else if(c == '(') {
            push(c);
        } else if(c == ')') {
            while(top != -1 && peek() != '(') {
                postfix[k++] = pop();
            }
            pop(); // Remove '('
        } else if(isOperator(c)) {
            while(top != -1 && precedence(peek()) >= precedence(c)) {
                postfix[k++] = pop();
            }
            push(c);
        }
    }
    while(top != -1) {
        postfix[k++] = pop();
    }
    postfix[k] = '\0';
}

// Reverse string
void reverse(char str[]) {
    int n = strlen(str);
    for(int i = 0; i < n/2; i++) {
        char temp = str[i];
        str[i] = str[n-i-1];
        str[n-i-1] = temp;
    }
}

// Swap brackets for prefix conversion
void swapBrackets(char str[]) {
    for(int i = 0; str[i]; i++) {
        if(str[i] == '(') str[i] = ')';
        else if(str[i] == ')') str[i] = '(';
    }
}

// Infix to Prefix
void infixToPrefix(char infix[], char prefix[]) {
    reverse(infix);
    swapBrackets(infix);
    char temp[MAX];
    top = -1; // reset stack
    infixToPostfix(infix, temp);
    reverse(temp);
    strcpy(prefix, temp);
}

// Generate Three-Address Code from Postfix
void generateTAC(char postfix[]) {
    char stackTAC[MAX][MAX];
    int topTAC = -1;
    for(int i = 0; i < strlen(postfix); i++) {
        char c = postfix[i];
        if(isalnum(c)) {
            char operand[2] = {c, '\0'};
            strcpy(stackTAC[++topTAC], operand);
        } else if(isOperator(c)) {
            char op2[MAX], op1[MAX];
            strcpy(op2, stackTAC[topTAC--]);
            strcpy(op1, stackTAC[topTAC--]);
            char tempVar[10];
            sprintf(tempVar, "t%d", tempCount++);
            printf("%s = %s %c %s\n", tempVar, op1, c, op2);
            strcpy(stackTAC[++topTAC], tempVar);
        }
    }
}

int main() {
    char infix[MAX], postfix[MAX], prefix[MAX];

    printf("Enter Infix Expression: ");
    scanf("%s", infix);

    top = -1;
    infixToPostfix(infix, postfix);
    printf("Postfix: %s\n", postfix);

    top = -1;
    infixToPrefix(infix, prefix);
    printf("Prefix: %s\n", prefix);

    printf("Three-Address Code:\n");
    tempCount = 1;
    generateTAC(postfix);

    return 0;
}