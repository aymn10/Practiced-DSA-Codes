// Q: Convert an infix expression to postfix and evaluate it using stack
// Time Complexity: O(n)
// Space Complexity: O(n)

#include <stdio.h>
#include <ctype.h>

struct Stack {
    int top;
    char arr[100];
};

void push(struct Stack* s, char v) {
    s->arr[++s->top] = v;
}

char pop(struct Stack* s) {
    return s->arr[s->top--];
}

char peek(struct Stack* s) {
    return s->arr[s->top];
}

int precedence(char c) {
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2;
    return 0;
}

void infixToPostfix(char infix[], char postfix[]) {
    struct Stack s;
    s.top = -1;
    int i = 0, j = 0;

    while (infix[i] != '\0') {
        if (isalnum(infix[i])) {
            postfix[j++] = infix[i];
        } else if (infix[i] == '(') {
            push(&s, infix[i]);
        } else if (infix[i] == ')') {
            while (s.top != -1 && peek(&s) != '(')
                postfix[j++] = pop(&s);
            pop(&s);
        } else {
            while (s.top != -1 && precedence(peek(&s)) >= precedence(infix[i]))
                postfix[j++] = pop(&s);
            push(&s, infix[i]);
        }
        i++;
    }

    while (s.top != -1)
        postfix[j++] = pop(&s);

    postfix[j] = '\0';
}

int evalPostfix(char postfix[]) {
    struct Stack s;
    s.top = -1;
    int i = 0;

    while (postfix[i] != '\0') {
        if (isdigit(postfix[i])) {
            push(&s, postfix[i] - '0');
        } else {
            int b = pop(&s);
            int a = pop(&s);
            switch (postfix[i]) {
                case '+': push(&s, a + b); break;
                case '-': push(&s, a - b); break;
                case '*': push(&s, a * b); break;
                case '/': push(&s, a / b); break;
            }
        }
        i++;
    }

    return pop(&s);
}

int main() {
    char infix[100], postfix[100];

    printf("Enter infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);
    printf("Postfix: %s\n", postfix);

    int result = evalPostfix(postfix);
    printf("Evaluation: %d\n", result);

    return 0;
}
