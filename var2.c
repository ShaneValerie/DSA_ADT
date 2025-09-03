#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct {
    int elem[MAX];
    int count;
} Etype, *EPtr;

void initialize(EPtr L){
    if(L != NULL)
        L->count = 0;
}

void insertPos(EPtr L, int data, int position){
    if(L == NULL) return;

    if(position < 0 || position > L->count){
        printf("Invalid position!\n");
        return;
    }
    if(L->count == MAX){
        printf("List is full!\n");
        return;
    }

    for(int i = L->count - 1; i >= position; i--){
        L->elem[i + 1] = L->elem[i];
    }

    L->elem[position] = data;
    L->count++;
}

void deletePos(EPtr L, int position){
    if(L == NULL) return;

    if(position < 0 || position >= L->count){
        printf("Invalid position!\n");
        return;
    }

    for(int i = position; i < L->count - 1; i++){
        L->elem[i] = L->elem[i + 1];
    }

    L->count--;
}

int locate(EPtr L, int data){
    if(L == NULL) return -1;

    for(int i = 0; i < L->count; i++){
        if(L->elem[i] == data)
            return i;
    }
    return -1;
}

int retrieve(EPtr L, int position){
    if(L == NULL || position < 0 || position >= L->count){
        printf("Invalid position!\n");
        return -1;
    }
    return L->elem[position];
}

void insertSorted(EPtr L, int data){
    if(L == NULL) return;

    if(L->count == MAX){
        printf("List is full!\n");
        return;
    }

    int pos = 0;
    while(pos < L->count && L->elem[pos] < data){
        pos++;
    }

    insertPos(L, data, pos);
}

void display(EPtr L){
    if(L == NULL) return;

    for(int i = 0; i < L->count; i++){
        printf("%d ", L->elem[i]);
    }
    printf("\n");
}

void makeNULL(EPtr L){
    if(L != NULL){
        free(L);
    }
}

int main(){
    EPtr L = (EPtr)malloc(sizeof(Etype));
    if(L == NULL){
        printf("Memory allocation failed!\n");
        return 1;
    }

    initialize(L);

    insertPos(L, 1, 0);
    insertPos(L, 3, 1);
    insertPos(L, 5, 2);
    insertSorted(L, 4);

    printf("List after insertions: ");
    display(L);

    int pos = locate(L, 3);
    printf("Position of 3: %d\n", pos);

    deletePos(L, pos);
    printf("List after deletion: ");
    display(L);

    makeNULL(L);

    return 0;
}

