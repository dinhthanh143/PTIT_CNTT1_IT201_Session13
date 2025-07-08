#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct Stack {
    int *arr;
    int top;
    int cap;
}Stack;
Stack *createStack(int cap) {
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->cap = cap;
    stack->top = -1;
    stack->arr = (int *)malloc(sizeof(int)*cap);
    return stack;
}
int isEmpty(Stack *stack) {
    if (stack->top == -1) {
        return 1;
    }
    return 0;
}
int pop(Stack *stack) {
    if (isEmpty(stack)) {
        printf("\nStack khong co phan tu.");
        return -1;
    }
    int temp = stack->arr[stack->top];
    stack->top--;
    return temp;
}
int isFull(Stack *stack) {
    if (stack->top == stack->cap-1) {
        return 1;
    }
    return 0;
}
void push(Stack *stack, int value) {
    if (isFull(stack)) {
        return;
    }
    stack->top++;
    stack->arr[stack->top] = value;
}
void freeStack(Stack *stack) {
    free(stack->arr);
    stack->arr = NULL;
    free(stack);
}
int main(){
    Stack *st = createStack(5);
    for (int i = 1; i <= 5; i++) {
        push(st, i);
    }
    printf("%d\n", pop(st));
    freeStack(st);
    return 0;
}
