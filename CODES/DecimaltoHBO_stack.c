// Q: Convert a decimal number to Binary, Octal, and Hexadecimal using stack
// Time Complexity: O(log n)
// Space Complexity: O(log n)

#include <stdio.h>

struct Stack {
    int arr[100];
    int top;
};

void push(struct Stack* s, int v) {
    s->arr[++s->top] = v;
}

int pop(struct Stack* s) {
    return s->arr[s->top--];
}

void convert(int num, int base) {
    struct Stack s;
    s.top = -1;

    if (num == 0) {
        printf("0");
        return;
    }

    while (num > 0) {
        push(&s, num % base);
        num /= base;
    }

    while (s.top != -1) {
        int v = pop(&s);
        if (v >= 10)
            printf("%c", 'A' + (v - 10));
        else
            printf("%d", v);
    }
}

int main() {
    int num;
    printf("Enter decimal number: ");
    scanf("%d", &num);

    printf("Binary: ");
    convert(num, 2);

    printf("\nOctal: ");
    convert(num, 8);

    printf("\nHexadecimal: ");
    convert(num, 16);

    return 0;
}
