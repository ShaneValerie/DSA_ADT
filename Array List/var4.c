#include <stdio.h>
#include <stdlib.h>  

#define LENGTH 10

typedef struct {
    int *elemPtr;
    int count;
    int max;
} List;

void initialize(List *L){
    L->elemPtr = (int*) malloc(LENGTH * sizeof(int));
    L->max = LENGTH;
    L->count = 0;
}

void resize(List *L){
    L->max *= 2;
    L->elemPtr = (int*) realloc(L->elemPtr, L->max * sizeof(int));
}

void insertPos(List *L, int data, int position){
    if(position < 0 || position > L->count){
        printf("Invalid position!\n");
        return;
    }
    if(L->count == L->max){
        resize(L);
    }
    for(int i = L->count; i > position; i--){
        L->elemPtr[i] = L->elemPtr[i-1];
    }
    L->elemPtr[position] = data;
    L->count++;
}

void deletePos(List *L, int position){
    if(position < 0 || position >= L->count){
        printf("Invalid position!\n");
        return;
    }
    for(int i = position; i < L->count - 1; i++){
        L->elemPtr[i] = L->elemPtr[i+1];
    }
    L->count--;
}

int locate(List *L, int data){
    for(int i = 0; i < L->count; i++){
        if(L->elemPtr[i] == data)
            return i;
    }
    return -1;
}

int retrieve(List *L, int position){
    if(position < 0 || position >= L->count){
        printf("Invalid position!\n");
        return -1;
    }
    return L->elemPtr[position];
}

void insertSorted(List *L, int data){
    if(L->count == L->max){
        resize(L);
    }
    int i = L->count - 1;
    while(i >= 0 && L->elemPtr[i] > data){
        L->elemPtr[i+1] = L->elemPtr[i];
        i--;
    }
    L->elemPtr[i+1] = data;
    L->count++;
}

void display(List *L){
    printf("List: ");
    for(int i = 0; i < L->count; i++){
        printf("%d ", L->elemPtr[i]);
    }
    printf("\n");
}

void makeNULL(List *L){
    free(L->elemPtr);
    L->elemPtr = NULL;
    L->count = 0;
    L->max = 0;
}