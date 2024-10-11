#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    char arr[MAX];
    int top;
} Stack;


void init(Stack *s) {
    s->top = -1;
}

bool isEmpty(Stack *s) {
    return s->top == -1;
}


void push(Stack *s, char c) {
    s->arr[++(s->top)] = c;
}

char pop(Stack *s) {
    return s->arr[(s->top)--];
}

char peek(Stack *s) {
    return s->arr[s->top];
}

bool ispar(const char *s) {
    Stack stk;
    init(&stk);

    for (int i = 0; s[i] != '\0'; i++) {
        char ch = s[i];

        if (isEmpty(&stk)) {
            push(&stk, ch);
        } else if ((peek(&stk) == '(' && ch == ')') ||
                   (peek(&stk) == '{' && ch == '}') ||
                   (peek(&stk) == '[' && ch == ']')) {

            pop(&stk);
        } else {
            push(&stk, ch);
        }
    }

    return isEmpty(&stk);
}

int main() {
    const char *s = "{()}[]";

    if (ispar(s)) {
        printf("true\n");
    } else {
        printf("false\n");
    }

    return 0;
}