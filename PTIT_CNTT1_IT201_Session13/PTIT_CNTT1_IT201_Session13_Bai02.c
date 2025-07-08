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
   stack->arr = (int*)malloc(sizeof(int)*cap);
   return stack;
}
int isFull(Stack *stack) {
   if(stack->top == stack->cap-1) {
      return 1;
   }
   return 0;
}
void push(Stack *stack, int value) {
   if (isFull(stack)) {
      return;
   }
   stack->arr[++stack->top] = value;
}
void printStack(Stack *stack) {
   if (stack->top == -1) {
      return;
   }
   for (int i = 0; i <= stack->top; i++) {
      printf("%d \t", stack->arr[i]);
   }
   printf("\ntop: %d\n", stack->top);
   printf("\ncap: %d",stack->cap);
}
void freeStack(Stack *stack) {
   free(stack->arr);
   stack->arr = NULL;
   free(stack);
}
int main(){
   Stack *st = createStack(5);
   for(int i=0;i<5;i++) {
      int value;
      printf("Moi nhap phan tu thu %d : ", i+1 );
      scanf("%d", &value);
      push(st, value);
   }
   printStack(st);
   freeStack(st);
   return 0;
}
