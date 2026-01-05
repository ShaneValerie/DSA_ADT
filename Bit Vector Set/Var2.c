#include <stdio.h>
#include <stdbool.h>

typedef struct 
{
    unsigned int field : 8;
} Set;

void initialize(Set *set) 
{
    set->field = 0;
}

void insert(Set *set, int element) 
{
    if (element >= 0 && element < 8) {
        unsigned int mask = 1 << element;
        set->field |= mask;
    }
}

void delete(Set *set, int element) 
{
    if (element >= 0 && element < 8) {
        unsigned int mask = ~(1 << element);
        set->field &= mask;
    }
}

bool find(Set set, int element) 
{
    if (element >= 0 && element < 8) {
        unsigned int mask = 1 << element;
        return (set.field & mask) != 0;
    }
    return false;
}

Set set_union(Set A, Set B) 
{
    Set C;
    C.field = A.field | B.field;
    return C;
}

Set intersection(Set A, Set B) 
{
    Set C;
    C.field = A.field & B.field;
    return C;
}

Set difference(Set A, Set B) 
{
    Set C;
    C.field = A.field & ~B.field;
    return C;
}

void display(Set set) 
{
    printf("{ ");
    for (int i = 0; i < 8; i++) {
        if (set.field & (1 << i)) {
            printf("%d ", i);
        }
    }
    printf("}\n");
}