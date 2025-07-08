#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct Stack {
    char *c;
    int top;
    int cap;
}Stack;
Stack *createStack(int cap) {
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->cap = cap;
    stack->top = -1;
    stack->c = (char *)malloc(cap * sizeof(char));
    return stack;
}
int isEmpty(Stack *stack) {
    if (stack->top == -1) {
        return 1;
    }
    return 0;
}
int isFull(Stack *stack) {
    if (stack->top == stack->cap-1) {
        return 1;
    }
    return 0;
}
void push(Stack *stack, char value) {
    if (isFull(stack)) {
        return;
    }
    stack->top++;
    stack->c[stack->top] = value;
}
char pop(Stack *stack) {
    if (isEmpty(stack)) {
        return '\0';
    }
    char temp = stack->c[stack->top];
    stack->top--;
    return temp;
}
void freeStack(Stack *stack) {
    free(stack->c);
    stack->c = NULL;
    free(stack);
}
int closeCheck(char a, char b) {
    if (a == '(' && b == ')') return 1;
    if (a == '[' && b == ']') return 1;
    if (a == '{' && b == '}') return 1;
    return 0;
}
void checkStr(char *str) {
    Stack *stack = createStack(strlen(str));
    for (int i=0; i<strlen(str); i++) {
        char temp = str[i];
        if (temp == '(' || temp == '[' || temp == '{') {
            push(stack, temp);
        }else if ( temp == ')' || temp == ']' || temp == '}') {
            if (isEmpty(stack)) {
                printf("\nFalse");
                freeStack(stack);
                return;
            }
            char match = pop(stack);
            if (!closeCheck(match, temp)) {
                printf("\nFalse");
                freeStack(stack);
                return;
            }
        }
    }
    if (isEmpty(stack)) {
        printf("\nTrue");
    }else {
        printf("\nFalse");
    }
    freeStack(stack);
    return;
}
int main(){
    char str[100];
    printf("Moi nhap chuoi: ");
    fgets(str,100,stdin);
    str[strcspn(str, "\n")] = 0;
    checkStr(str);
    // for (int i =0; i<strlen(str); i++) {
    //     push(st,str[i]);
    // }
    // freeStack(st);
    return 0;
}
