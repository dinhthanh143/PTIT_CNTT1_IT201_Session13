#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct Stack {
   char *str;
   int top;
   int cap;
}Stack;
Stack *createStack(int cap) {
   Stack *stack = (Stack *)malloc(sizeof(Stack));
   stack->cap = cap;
   stack->top = -1;
   stack->str = (char *)malloc(cap * sizeof(char));
   return stack;
}
int isEmpty(Stack *stack) {
   if (stack->top == -1) {
      return 1;
   }
   return 0;
}
int isFull(Stack *stack) {
   if (stack->top == stack->cap - 1) {
      return 1;
   }
   return 0;
}
void push(Stack *stack, char *str) {
   if (isFull(stack)) {
      return;
   }
   stack->top++;
   stack->str[stack->top] = str;
}
char pop(Stack *stack) {
   if (isEmpty(stack)) {
      return '\0';
   }
   char temp = stack->str[stack->top];
   stack->top--;
   return temp;
}
// void printStack(Stack *stack) {
//    if (isEmpty(stack)) {
//       return;
//    }
//    while (!isEmpty(stack)) {
//       printf("%c", pop(stack));
//    }
// }
void checkStr(char *str) {
   Stack *stack = createStack(100);
   for (int i=0; i<strlen(str); i++) {
      push(stack, str[i]);
   }
   int i = 0;
   while (i<=stack->top/2) {
      char value = stack->str[stack->top - i];
      if (value != stack->str[i]) {
         printf("\nFalse");
         return;
      }
      i++;
   }
   printf("\nTrue");
   return;
}
void freeStack(Stack *stack) {
   free(stack->str);
   stack->str = NULL;
   free(stack);
}
int main(){
   char str[100];
   printf("Moi nhap chuoi: ");
   fgets(str, 100, stdin);
   str[strcspn(str, "\n")] = 0;
   // printStack(stack);
   checkStr(str);
   return 0;
}
