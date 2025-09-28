#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10

typedef struct {
    int items[MAX];
    int front;
    int rear;
} Queue;

Queue* initialize() {
    Queue* q = (Queue*) malloc(sizeof(Queue));
    if (q == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }

    q->front = 1;  
    q->rear = 0;   
    return q;
}

bool isEmpty(Queue* q) {
    return q->front == (q->rear + 1) % MAX;
}

bool isFull(Queue* q) {
    return q->front == (q->rear + 2) % MAX;
}

void enqueue(Queue* q, int value) {
    if (isFull(q)) {
        printf("Queue is full!\n");
        return;
    }

    q->rear = (q->rear + 1) % MAX;  
    q->items[q->rear] = value;
}

int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return -1;
    }

    int value = q->items[q->front];
    q->front = (q->front + 1) % MAX; 
    return value;
}

int frontVal(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return -1;
    }
    return q->items[q->front];
}

void display(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    }

    printf("[ ");
    int i = q->front;
    while (i != (q->rear + 1) % MAX) {
        printf("%d ", q->items[i]);
        i = (i + 1) % MAX;
    }
    printf("]\n");
}

