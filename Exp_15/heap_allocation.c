#include <stdio.h>
#include <stdlib.h>

#define HEAP_SIZE 100

typedef struct {
    int start;
    int size;
    int free;
} Block;

Block heap[HEAP_SIZE];
int n = 0; // number of blocks

// Allocate memory
int allocate(int size) {
    for(int i = 0; i < n; i++) {
        if(heap[i].free && heap[i].size >= size) {
            heap[i].free = 0;
            printf("Allocated %d units at block %d\n", size, i);
            return i;
        }
    }
    if(n + 1 <= HEAP_SIZE) {
        heap[n].start = (n == 0) ? 0 : heap[n-1].start + heap[n-1].size;
        heap[n].size = size;
        heap[n].free = 0;
        printf("Allocated %d units at block %d\n", size, n);
        return n++;
    }
    printf("Heap full, cannot allocate %d units\n", size);
    return -1;
}

// Free memory
void deallocate(int blockNo) {
    if(blockNo >= 0 && blockNo < n && heap[blockNo].free == 0) {
        heap[blockNo].free = 1;
        printf("Deallocated block %d\n", blockNo);
    } else {
        printf("Invalid deallocation request\n");
    }
}

// Display heap status
void displayHeap() {
    printf("Heap status:\n");
    for(int i=0;i<n;i++)
        printf("Block %d: start=%d size=%d free=%d\n", i, heap[i].start, heap[i].size, heap[i].free);
}

int main() {
    int b1 = allocate(10);
    int b2 = allocate(20);
    displayHeap();

    deallocate(b1);
    displayHeap();

    int b3 = allocate(5);
    displayHeap();

    return 0;
}