#include <stdio.h>
#include <string.h>
#include <ctype.h>

char prod[10][10];
int n;

void closure() {
    printf("\nClosure of given grammar:\n");

    for (int i = 0; i < n; i++) {
        printf("%c -> .%s\n", prod[i][0], prod[i] + 2);

        if (isupper(prod[i][2])) {
            for (int j = 0; j < n; j++) {
                if (prod[i][2] == prod[j][0]) {
                    printf("%c -> .%s\n", prod[j][0], prod[j] + 2);
                }
            }
        }
    }
}

int main() {
    printf("Enter number of productions: ");
    scanf("%d", &n);

    printf("Enter productions (S=CC):\n");
    for (int i = 0; i < n; i++) {
        scanf("%s", prod[i]);
    }

    printf("\nAugmented Grammar:\n");
    printf("S' -> .%c\n", prod[0][0]);

    closure();

    return 0;
}