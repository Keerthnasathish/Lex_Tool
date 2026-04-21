#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char op;
    char left[10];
    char right[10];
    char result[10];
} DAGNode;

DAGNode dag[100];
int dagCount = 0;
int tempVar = 1;

// Function to create temporary variable
void getTemp(char *temp) {
    sprintf(temp, "t%d", tempVar++);
}

// Function to check if operator node already exists
int findNode(char op, char *left, char *right) {
    for(int i = 0; i < dagCount; i++) {
        if(dag[i].op == op && strcmp(dag[i].left, left) == 0 && strcmp(dag[i].right, right) == 0) {
            return i;
        }
    }
    return -1;
}

// Function to add node
int addNode(char op, char *left, char *right) {
    int index = findNode(op, left, right);
    if(index != -1) return index; // reuse existing node
    char temp[10];
    getTemp(temp);
    dag[dagCount].op = op;
    strcpy(dag[dagCount].left, left);
    strcpy(dag[dagCount].right, right);
    strcpy(dag[dagCount].result, temp);
    return dagCount++;
}

// Example usage
void buildDAG() {
    int t1 = addNode('*', "B", "C");
    int t2 = addNode('+', "A", dag[t1].result);
    int t3 = addNode('+', dag[t2].result, dag[t1].result);

    printf("Optimized Quadruples from DAG:\n");
    printf("Op\tArg1\tArg2\tResult\n");
    for(int i = 0; i < dagCount; i++) {
        printf("%c\t%s\t%s\t%s\n", dag[i].op, dag[i].left, dag[i].right, dag[i].result);
    }
}

int main() {
    buildDAG();
    return 0;
}