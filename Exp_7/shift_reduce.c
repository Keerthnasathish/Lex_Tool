#include <stdio.h>
#include <string.h>

char stack[50], input[50];
int top = -1;

void push(char c) {
    stack[++top] = c;
    stack[top + 1] = '\0';
}

void pop(int n) {
    top -= n;
    stack[top + 1] = '\0';
}

void check() {
    // Reduce id to E
    if (strstr(stack, "id")) {
        stack[top - 1] = 'E';
        stack[top] = '\0';
        top--;
        printf("Reduce: E -> id\n");
    }

    // Reduce E+E to E
    if (strstr(stack, "E+E")) {
        pop(3);
        push('E');
        printf("Reduce: E -> E+E\n");
    }

    // Reduce E*E to E
    if (strstr(stack, "E*E")) {
        pop(3);
        push('E');
        printf("Reduce: E -> E*E\n");
    }

    // Reduce (E) to E
    if (strstr(stack, "(E)")) {
        pop(3);
        push('E');
        printf("Reduce: E -> (E)\n");
    }
}

int main() {
    int i = 0;
    printf("Enter input string: ");
    scanf("%s", input);

    printf("\nStack\tInput\tAction\n");

    while (i < strlen(input)) {
        push(input[i]);
        printf("%s\t%s\tShift\n", stack, input + i + 1);
        check();
        i++;
    }

    check();

    if (strcmp(stack, "E") == 0)
        printf("\nString Accepted\n");
    else
        printf("\nString Rejected\n");

    return 0;
}