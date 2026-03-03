#include <stdio.h>
#include <ctype.h>
#include <string.h>

int n;
char production[10][10];
char first[10];
char follow[10];
int m = 0, k = 0;

void findFirst(char c);
void findFollow(char c);

int main() {
    int i;
    char c;

    printf("Enter number of productions: ");
    scanf("%d", &n);

    printf("Enter productions (Example: E=TR):\n");
    for(i = 0; i < n; i++) {
        scanf("%s", production[i]);
    }

    printf("Enter non-terminal: ");
    scanf(" %c", &c);

    findFirst(c);

    printf("\nFIRST(%c) = { ", c);
    for(i = 0; i < m; i++)
        printf("%c ", first[i]);
    printf("}\n");

    findFollow(c);

    printf("FOLLOW(%c) = { ", c);
    for(i = 0; i < k; i++)
        printf("%c ", follow[i]);
    printf("}\n");

    return 0;
}

void findFirst(char c) {
    int i;

    if(!isupper(c)) {
        first[m++] = c;
        return;
    }

    for(i = 0; i < n; i++) {
        if(production[i][0] == c) {
            if(!isupper(production[i][2]))
                first[m++] = production[i][2];
            else
                findFirst(production[i][2]);
        }
    }
}

void findFollow(char c) {
    int i, j;

    if(production[0][0] == c)
        follow[k++] = '$';

    for(i = 0; i < n; i++) {
        for(j = 2; j < strlen(production[i]); j++) {
            if(production[i][j] == c) {
                if(production[i][j+1] != '\0')
                    follow[k++] = production[i][j+1];
                else if(production[i][0] != c)
                    findFollow(production[i][0]);
            }
        }
    }
}
