#include <stdio.h>
#include <string.h>

char table[5][5][10];

int main() {

    // Example grammar
    // E → T R
    // R → + T R | #
    // T → i

    strcpy(table[0][0], "TR");    // E , i
    strcpy(table[1][1], "+TR");   // R , +
    strcpy(table[1][3], "#");     // R , $
    strcpy(table[2][0], "i");     // T , i

    printf("\nPredictive Parsing Table\n\n");
    printf("      i      +      $   \n");
    printf("--------------------------------\n");

    printf("E |  %-6s  -      -\n", table[0][0]);
    printf("R |  -      %-6s  %-6s\n", table[1][1], table[1][3]);
    printf("T |  %-6s  -      -\n", table[2][0]);

    printf("\n# represents epsilon\n");

    return 0;
}
