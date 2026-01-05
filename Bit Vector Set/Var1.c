#include <stdio.h>
#include <stdbool.h>

void initialize(unsigned char *set) 
{
    *set = 0;
}

void insert(unsigned char *set, int element) 
{
    if (element >= 0 && element < 8) {
        unsigned char mask = 1 << element;
        *set |= mask;
    }
}

void delete(unsigned char *set, int element){
    if (element >= 0 && element < 8) {
        unsigned char mask = ~(1 << element);
        *set &= mask;
    }
}

bool find(unsigned char set, int element)
{
    if (element >= 0 && element < 8) {
        unsigned char mask = 1 << element;
        return (set & mask) != 0;
    }
    return false;
}

unsigned char set_union(unsigned char A, unsigned char B) 
{
    return A | B;
}

unsigned char intersection(unsigned char A, unsigned char B) 
{
    return A & B;
}

unsigned char difference(unsigned char A, unsigned char B) 
{
    return A & ~B;
}

void display(unsigned char set) 
{
    printf("{ ");
    for (int i = 0; i < 8; i++) 
    {
        if (set & (1 << i)) {
            printf("%d ", i);
        }
    }
    printf("}\n");
}



