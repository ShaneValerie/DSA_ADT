#include <stdio.h>
#include <stdlib.h>

#define LENGTH 10 
typedef struct{
    int *elemPtr;
    int count;
    int max;
} List;  


List initialize(List L){
  L.elemPtr = (int*)malloc(LENGTH * sizeof(int));
    if(L.elemPtr == NULL){
        printf("faoled!\n");
        exit(1)
    }
    L.count = 0;
    L.max = LENGTH;
    return L;
}

List insertPos(List L, int data, int position){

}
List deletePos(List L, int position){

}
int locate(List L, int data){

}
List  insertSorted(List L, int data){

}
void display(List L){
    
}
List resize(List L){

}


ssss





















