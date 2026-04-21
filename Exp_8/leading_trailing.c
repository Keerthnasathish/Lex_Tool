#include <stdio.h>
#include <string.h>
#include <ctype.h>

char prod[10][10];
char leading[10][10];
char trailing[10][10];
int n;

void add(char *res, char val) {
    for (int i = 0; res[i] != '\0'; i++)
        if (res[i] == val)
            return;
    int len = strlen(res);
    res[len] = val;
    res[len + 1] = '\0';
}

void findLeading(int i) {
    if (!isupper(prod[i][2])) {
        add(leading[i], prod[i][2]);
    } else {
        for (int j = 0; j < n; j++) {
            if (prod[i][2] == prod[j][0]) {
                findLeading(j);
                for (int k = 0; leading[j][k] != '\0'; k++)
                    add(leading[i], leading[j][k]);
            }
        }
    }
}

void findTrailing(int i) {
    int len = strlen(prod[i]);

    if (!isupper(prod[i][len - 1])) {
        add(trailing[i], prod[i][len - 1]);
    } else {
        for (int j = 0; j < n; j++) {
            if (prod[i][len - 1] == prod[j][0]) {
                findTrailing(j);
                for (int k = 0; trailing[j][k] != '\0'; k++)
                    add(trailing[i], trailing[j][k]);
            }
        }
    }
}

int main() {
    printf("Enter number of productions: ");
    scanf("%d", &n);

    printf("Enter productions (E=E+T):\n");
    for (int i = 0; i < n; i++) {
        scanf("%s", prod[i]);
        leading[i][0] = '\0';
        trailing[i][0] = '\0';
    }

    for (int i = 0; i < n; i++) {
        findLeading(i);
        findTrailing(i);
    }

    printf("\nLEADING:\n");
    for (int i = 0; i < n; i++) {
        printf("%c : %s\n", prod[i][0], leading[i]);
    }

    printf("\nTRAILING:\n");
    for (int i = 0; i < n; i++) {
        printf("%c : %s\n", prod[i][0], trailing[i]);
    }

    return 0;
}