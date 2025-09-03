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
    if(pos < 0 || pos > L.count){
        printf("Invalid!\n");
        return L;
    }
}

List deletePos(List L, int position){
    if(pos < 0 || pos >= L.count){
        printf("Invalid!\n");
        return L;
    }
    for(int i = pos; i < L.count - 1; i++){
        L.elemPtr[i] = L.elemPtr[i + 1];
    }
    L.count--;
    return L;  
}

int locate(List L, int data){
    for(int i = 0; i < L.count; i++){
        if(L.elemPtr[i] == data)
    return i;
    }
    return -1;
}
List  insertSorted(List L, int data){
    if(L.count == L.max){
        
    }
}
void display(List L){
    
}
List resize(List L){

}























