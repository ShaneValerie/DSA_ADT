#include <stdio.h>
#include <stdlib.h>

#define MAX 4

typedef struct {
    int elem;
    int next;
} Cell, HeapSpace[MAX];

typedef struct {
    HeapSpace H;
    int avail;
} VHeap;

typedef int List;

void initialize(VHeap *V) {
    V->avail = 0;
    for (int i = 0; i < MAX - 1; i++) {
        V->H[i].next = i + 1;
    }
    V->H[MAX - 1].next = -1;
}

int allocSpace(VHeap* V) {
    if (V->avail == -1) return -1;
    int index = V->avail;
    V->avail = V->H[index].next;
    return index;
}

void deallocSpace(VHeap* V, int index) {
    V->H[index].next = V->avail;
    V->avail = index;
}

void insertFirst(int* L, VHeap* V, int elem) {
    int newCell = allocSpace(V);
    if (newCell == -1) return;
    V->H[newCell].elem = elem;
    V->H[newCell].next = *L;
    *L = newCell;
}

void insertLast(int* L, VHeap* V, int elem) {
    int newCell = allocSpace(V);
    if (newCell == -1) return;
    V->H[newCell].elem = elem;
    V->H[newCell].next = -1;
    if (*L == -1) {
        *L = newCell;
    } else {
        int current = *L;
        while (V->H[current].next != -1) current = V->H[current].next;
        V->H[current].next = newCell;
    }
}

void insertPos(int* L, VHeap* V, int elem, int pos) {
    if (pos == 0) {
        insertFirst(L, V, elem);
        return;
    }
    int newCell = allocSpace(V);
    if (newCell == -1) return;
    V->H[newCell].elem = elem;
    int current = *L;
    for (int i = 0; i < pos - 1 && current != -1; i++) current = V->H[current].next;
    if (current != -1) {
        V->H[newCell].next = V->H[current].next;
        V->H[current].next = newCell;
    } else {
        deallocSpace(V, newCell);
    }
}

void insertSorted(int* L, VHeap* V, int elem) {
    int newCell = allocSpace(V);
    if (newCell == -1) return;
    V->H[newCell].elem = elem;
    if (*L == -1 || V->H[*L].elem >= elem) {
        V->H[newCell].next = *L;
        *L = newCell;
        return;
    }
    int current = *L;
    while (V->H[current].next != -1 && V->H[V->H[current].next].elem < elem) current = V->H[current].next;
    V->H[newCell].next = V->H[current].next;
    V->H[current].next = newCell;
}

void delete(int* L, VHeap* V, int elem) {
    if (*L == -1) return;
    int current = *L;
    int prev = -1;
    while (current != -1 && V->H[current].elem != elem) {
        prev = current;
        current = V->H[current].next;
    }
    if (current == -1) return;
    if (prev == -1) *L = V->H[current].next;
    else V->H[prev].next = V->H[current].next;
    deallocSpace(V, current);
}

void deleteAllOccurrence(int* L, VHeap* V, int elem) {
    int current = *L;
    int prev = -1;
    while (current != -1) {
        if (V->H[current].elem == elem) {
            int toDelete = current;
            if (prev == -1) {
                *L = V->H[current].next;
                current = *L;
            } else {
                V->H[prev].next = V->H[current].next;
                current = V->H[prev].next;
            }
            deallocSpace(V, toDelete);
        } else {
            prev = current;
            current = V->H[current].next;
        }
    }
}

void display(int L, VHeap V) {
    int current = L;
    printf("List: ");
    while (current != -1) {
        printf("%d ", V.H[current].elem);
        current = V.H[current].next;
    }
    printf("\n");
}
