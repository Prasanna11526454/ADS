#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int top;
    int items[MAX];
} Stack;

void initialize(Stack *s) {
    s->top = -1;
}

int isFull(Stack *s) {
    return s->top == MAX - 1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

void push(Stack *s, int value) {
    if (isFull(s)) {
        printf("Stack Overflow\n");
    } else {
        s->items[++(s->top)] = value;
    }
}

int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow\n");
        return -1;
    } else {
        return s->items[(s->top)--];
    }
}

// A. Factorial of a given number using a stack
int factorial(int n) {
    Stack s;
    initialize(&s);
    int result = 1;
    
    while (n > 1) {
        push(&s, n);
        n--;
    }
    
    while (!isEmpty(&s)) {
        result *= pop(&s);
    }
    
    return result;
}

// B. Generation of Fibonacci series using a stack
void fibonacci(int n) {
    Stack s;
    initialize(&s);
    
    push(&s, 0);  
    push(&s, 1);  
    
    printf("Fibonacci Series: ");
    printf("0 1 ");
    
    for (int i = 2; i < n; i++) {
        int b = pop(&s); 
        int a = pop(&s); 
        
        int next = a + b;
        printf("%d ", next);
        
        push(&s, b);    
        push(&s, next); 
    }
    printf("\n");
}

int main() {
    int num, n;
    
    printf("Enter a number to calculate its factorial: ");
    scanf("%d", &num);
    printf("Factorial of %d is %d\n", num, factorial(num));
    
    printf("Enter the number of terms for Fibonacci series: ");
    scanf("%d", &n);
    fibonacci(n);
    
    return 0;
}
