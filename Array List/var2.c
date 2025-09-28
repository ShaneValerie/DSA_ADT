#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct {
    int elem[MAX];
    int count;
} Etype, *EPtr;

EPtr L;

void initialize(EPtr L){
    if (L != NULL) {
        L->count = 0;
    }
}

void insertPos(EPtr L, int data, int position){
    if (L == NULL) return;

    if (position < 0 || position > L->count) {
        printf("Invalid position!\n");
        return;
    }
    if (L->count == MAX) {
        printf("List is full!\n");
        return;
    }

    for (int i = L->count; i > position; i--) {
        L->elem[i] = L->elem[i - 1];
    }

    L->elem[position] = data;
    L->count++;
}

void deletePos(EPtr L, int position){
    if (L == NULL) return;

    if (position < 0 || position >= L->count) {
        printf("Invalid position!\n");
        return;
    }
    for (int i = position; i < L->count - 1; i++) {
        L->elem[i] = L->elem[i + 1];
    }

    L->count--;
}

int locate(EPtr L, int data){
    if (L == NULL) return -1;

    for (int i = 0; i < L->count; i++) {
        if (L->elem[i] == data) {
            return i; 
        }
    }
    return -1; 
}

int retrieve(EPtr L, int position){
    if (L == NULL || position < 0 || position >= L->count) {
        printf("Invalid position!\n");
        return -1;
    }
    return L->elem[position];
}

void insertSorted(EPtr L, int data){
    if (L == NULL) return;

    if (L->count == MAX) {
        printf("List is full!\n");
        return;
    }

    int i = L->count - 1;
    while (i >= 0 && L->elem[i] > data) {
        L->elem[i + 1] = L->elem[i];
        i--;
    }
    L->elem[i + 1] = data;
    L->count++;
}

void display(EPtr L){
    if (L == NULL) return;

    printf("List: ");
    for (int i = 0; i < L->count; i++) {
        printf("%d ", L->elem[i]);
    }
    printf("\n");
}

void makeNULL(EPtr L){
    if (L != NULL) {
        free(L);
    }
}