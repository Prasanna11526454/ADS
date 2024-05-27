#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

typedef struct Stack {
    int top;
    char items[MAX];
} Stack;

void initStack(Stack *s) {
    s->top = -1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

void push(Stack *s, char x) {
    s->items[++(s->top)] = x;
}

char pop(Stack *s) {
    if (!isEmpty(s))
        return s->items[(s->top)--];
    return '\0';
}

char peek(Stack *s) {
    return s->items[s->top];
}

int precedence(char op) {
    switch (op) {
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 2;
        case '^': return 3;
        default: return 0;
    }
}

void reverseString(char *str) {
    int n = strlen(str);
    for (int i = 0; i < n / 2; i++) {
        char temp = str[i];
        str[i] = str[n - i - 1];
        str[n - i - 1] = temp;
    }
}

void replaceParentheses(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '(') {
            str[i] = ')';
        } else if (str[i] == ')') {
            str[i] = '(';
        }
    }
}

void infixToPrefix(char infix[], char prefix[]) {
    int i, j = 0;
    Stack s;
    initStack(&s);

    reverseString(infix);
    replaceParentheses(infix);

    for (i = 0; infix[i] != '\0'; i++) {
        if (isalnum(infix[i])) {
            prefix[j++] = infix[i];
        } else if (infix[i] == '(') {
            push(&s, infix[i]);
        } else if (infix[i] == ')') {
            while (!isEmpty(&s) && peek(&s) != '(') {
                prefix[j++] = pop(&s);
            }
            pop(&s);  // Pop '('
        } else {
            while (!isEmpty(&s) && precedence(peek(&s)) > precedence(infix[i])) {
                prefix[j++] = pop(&s);
            }
            push(&s, infix[i]);
        }
    }

    while (!isEmpty(&s)) {
        prefix[j++] = pop(&s);
    }

    prefix[j] = '\0';
    reverseString(prefix);
}

int main() {
    char infix[MAX], prefix[MAX];
    printf("Enter infix expression: ");
    scanf("%s", infix);

    infixToPrefix(infix, prefix);
    printf("Prefix expression: %s\n", prefix);

    return 0;
}
