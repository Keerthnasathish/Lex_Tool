#include <stdio.h>
#include <string.h>

#define MAX 10
#define VARS 26  // assuming variables a-z

typedef struct {
    char name[10];
    int gen[VARS];
    int kill[VARS];
    int in[VARS];
    int out[VARS];
} BasicBlock;

int n; // number of blocks
BasicBlock bb[MAX];

// Function to print variable set
void printSet(int set[VARS]) {
    for(int i=0; i<VARS; i++) {
        if(set[i]) printf("%c ", 'a'+i);
    }
    printf("\n");
}

// Union of two sets: result = a U b
void unionSet(int a[VARS], int b[VARS], int result[VARS]) {
    for(int i=0; i<VARS; i++) result[i] = a[i] || b[i];
}

// Subtract sets: result = a - b
void subtractSet(int a[VARS], int b[VARS], int result[VARS]) {
    for(int i=0; i<VARS; i++) result[i] = a[i] && !b[i];
}

int equalSet(int a[VARS], int b[VARS]) {
    for(int i=0;i<VARS;i++) if(a[i]!=b[i]) return 0;
    return 1;
}

// Live variable analysis
void dataFlowAnalysis() {
    int changed = 1;
    while(changed) {
        changed = 0;
        for(int i=n-1; i>=0; i--) {  // reverse order
            int old_in[VARS];
            memcpy(old_in, bb[i].in, sizeof(old_in));

            // Compute OUT[i] = Union of IN of successors
            memset(bb[i].out, 0, sizeof(bb[i].out));
            if(i+1 < n) unionSet(bb[i+1].in, bb[i].out, bb[i].out);

            // IN[i] = GEN[i] U (OUT[i] - KILL[i])
            int temp[VARS];
            subtractSet(bb[i].out, bb[i].kill, temp);
            unionSet(bb[i].gen, temp, bb[i].in);

            if(!equalSet(old_in, bb[i].in)) changed = 1;
        }
    }
}

int main() {
    n = 3;

    // Example program: B1: a=b+c, B2: d=a+e, B3: f=d+g
    // Initialize GEN and KILL sets
    memset(bb, 0, sizeof(bb));

    // B1
    bb[0].gen['a'-'a'] = 1;
    bb[0].kill['a'-'a'] = 0;

    // B2
    bb[1].gen['d'-'a'] = 1;
    bb[1].kill['a'-'a'] = 1;

    // B3
    bb[2].gen['f'-'a'] = 1;
    bb[2].kill['d'-'a'] = 1;

    dataFlowAnalysis();

    for(int i=0;i<n;i++) {
        printf("Block B%d\n", i+1);
        printf("IN: "); printSet(bb[i].in);
        printf("OUT: "); printSet(bb[i].out);
        printf("\n");
    }

    return 0;
}