#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

typedef struct {
    char op;
    char arg1[10];
    char arg2[10];
    char res[10];
} Quadruple;

typedef struct {
    char op;
    char arg1[10];
    char arg2[10];
} Triple;

Quadruple quads[MAX];
Triple triples[MAX];
int quadCount = 0;
int tripleCount = 0;
int tempVar = 1;

// Function to generate temporary variable name
void getTemp(char *temp) {
    sprintf(temp, "t%d", tempVar++);
}

// Example: generate quadruple for operator and operands
void generateQuad(char op, char *arg1, char *arg2, char *res) {
    quads[quadCount].op = op;
    strcpy(quads[quadCount].arg1, arg1);
    strcpy(quads[quadCount].arg2, arg2);
    strcpy(quads[quadCount].res, res);
    quadCount++;
}

// Example: generate triple
void generateTriple(char op, char *arg1, char *arg2) {
    triples[tripleCount].op = op;
    strcpy(triples[tripleCount].arg1, arg1);
    strcpy(triples[tripleCount].arg2, arg2);
    tripleCount++;
}

int main() {
    // TODO: Read expression, convert to postfix, evaluate with stack
    // Generate Quadruples, Triples, Indirect Triples

    printf("Quadruples Table:\n");
    printf("Op\tArg1\tArg2\tRes\n");
    for(int i = 0; i < quadCount; i++) {
        printf("%c\t%s\t%s\t%s\n", quads[i].op, quads[i].arg1, quads[i].arg2, quads[i].res);
    }

    printf("\nTriples Table:\n");
    printf("Index\tOp\tArg1\tArg2\n");
    for(int i = 0; i < tripleCount; i++) {
        printf("%d\t%c\t%s\t%s\n", i, triples[i].op, triples[i].arg1, triples[i].arg2);
    }

    // Indirect triples can just point to triple indexes
    return 0;
}