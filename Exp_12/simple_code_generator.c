#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char op;
    char arg1[10];
    char arg2[10];
    char res[10];
} Quadruple;

Quadruple quads[100];
int quadCount = 0;
int tempVar = 1;

// Function to read quad input (manual or from previous intermediate code)
void inputQuadruples() {
    // Example for A + B * C
    quadCount = 2;
    quads[0] = (Quadruple){'*', "B", "C", "t1"};
    quads[1] = (Quadruple){'+', "A", "t1", "t2"};
}

// Simple code generation
void generateSimpleCode() {
    printf("Simple Code Generation (Pseudo-assembly):\n");
    for(int i = 0; i < quadCount; i++) {
        printf("MOV R1, %s\n", quads[i].arg1);
        if(quads[i].op == '+')
            printf("ADD R1, %s\n", quads[i].arg2);
        else if(quads[i].op == '-')
            printf("SUB R1, %s\n", quads[i].arg2);
        else if(quads[i].op == '*')
            printf("MUL R1, %s\n", quads[i].arg2);
        else if(quads[i].op == '/')
            printf("DIV R1, %s\n", quads[i].arg2);
        printf("MOV %s, R1\n\n", quads[i].res);
    }
}

int main() {
    inputQuadruples();
    generateSimpleCode();
    return 0;
}