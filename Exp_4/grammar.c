#include <stdio.h>
#include <string.h>

int main() {
    int choice;

    printf("GRAMMAR TRANSFORMATION PROGRAM\n");
    printf("1. Eliminate Left Recursion\n");
    printf("2. Left Factoring\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if(choice == 1) {
        char A[10], alpha[10], beta[10];

        printf("\nEnter Non-Terminal (A): ");
        scanf("%s", A);

        printf("Enter alpha (after left recursive part): ");
        scanf("%s", alpha);

        printf("Enter beta (non left recursive part): ");
        scanf("%s", beta);

        printf("\nGrammar after removing Left Recursion:\n");
        printf("%s -> %s%s'\n", A, beta, A);
        printf("%s' -> %s%s' | e\n", A, alpha, A);
    }

    else if(choice == 2) {
        char A[10], prefix[10], beta1[10], beta2[10];

        printf("\nEnter Non-Terminal (A): ");
        scanf("%s", A);

        printf("Enter common prefix: ");
        scanf("%s", prefix);

        printf("Enter remaining part of first production: ");
        scanf("%s", beta1);

        printf("Enter remaining part of second production: ");
        scanf("%s", beta2);

        printf("\nGrammar after Left Factoring:\n");
        printf("%s -> %s%s'\n", A, prefix, A);
        printf("%s' -> %s | %s\n", A, beta1, beta2);
    }

    else {
        printf("Invalid choice!\n");
    }

    return 0;
}
