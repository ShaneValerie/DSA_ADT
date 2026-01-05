#include <stdio.h>
#include <stdbool.h>

#define ARRAY_SIZE 8

typedef bool Set[ARRAY_SIZE];

void initialize(Set *S);
void insert(Set *S, int x);
void delete(Set *S, int x);
bool find(Set S, int x);
void Union(Set A, Set B, Set C);
void intersection(Set A, Set B, Set C);
void difference(Set A, Set B, Set C);
void display(Set S);

int main()
{
    Set A, B, U, I, D;

    initialize(&A);
    initialize(&B);

    insert(&A, 1);
    insert(&A, 3);
    insert(&A, 5);

    insert(&B, 3);
    insert(&B, 4);
    insert(&B, 6);

    printf("Set A: ");
    display(A);

    delete(&A, 5);
    printf("Set A after deleting 5: ");
    display(A);

    printf("Find 3 in A: %s\n", find(A, 3) ? "FOUND" : "NOT FOUND");

    Union(A, B, U);
    printf("Union: ");
    display(U);

    intersection(A, B, I);
    printf("Intersection: ");
    display(I);

    difference(A, B, D);
    printf("Difference (A - B): ");
    display(D);

    return 0;
}


void initialize(Set *S)
{
    int i;
    for(i = 0; i < ARRAY_SIZE; i++)
        (*S)[i] = false;
}

void insert(Set *S, int x)
{
    if(x >= 0 && x < ARRAY_SIZE)
        (*S)[x] = true;
}

void delete(Set *S, int x)
{
    if(x >= 0 && x < ARRAY_SIZE)
        (*S)[x] = false;
}

bool find(Set S, int x)
{
    if(x >= 0 && x < ARRAY_SIZE)
        return S[x];

    return false;
}

void Union(Set A, Set B, Set C)
{
    int i;
    for(i = 0; i < ARRAY_SIZE; i++)
        C[i] = A[i] || B[i];
}

void intersection(Set A, Set B, Set C)
{
    int i;
    for(i = 0; i < ARRAY_SIZE; i++)
        C[i] = A[i] && B[i];
}

void difference(Set A, Set B, Set C)
{
    int i;
    for(i = 0; i < ARRAY_SIZE; i++)
        C[i] = A[i] && !B[i];
}

void display(Set S)
{
    int i;
    printf("{ ");
    for(i = 0; i < ARRAY_SIZE; i++) {
        if(S[i])
            printf("%d ", i);
    }
    printf("}\n");
}
