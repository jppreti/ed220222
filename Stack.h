#ifndef DataStructure_Stack_h
#define DataStructure_Stack_h

#include <stdbool.h>

typedef struct Node {
    void *data;
    struct Node *under;
}Node;

typedef struct Stack {
    Node *top;
    int size;
}Stack;

void init(Stack *stack);               // 0,5 pt
bool push(Stack *stack, void *data);   // 2,5 pts
void* pop(Stack *stack);               // 2,5 pts
void* top(Stack *stack);               // 2,5 pts
bool isEmpty(Stack *stack);            // 0,5 pt
void show(Stack *stack);               // 1,5 pt

#endif