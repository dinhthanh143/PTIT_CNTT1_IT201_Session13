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
void freeStack(Stack *stack) {
   free(stack->arr);
   stack->arr = NULL;
   free(stack);
}
int main(){
   Stack *st = createStack(5);
   freeStack(st);
   return 0;
}
