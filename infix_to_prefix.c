#include <stdio.h>
#include <string.h>

#define INVALID '\0'
#define FINVALID -99999.99
#define SIZE 20

char stack[SIZE];
int top = -1;

void push(char item) {
    if (top == SIZE - 1)
        printf("Stack Overflow\n");
    else
        stack[++top] = item;
}

char pop() {
    if (top != -1)
        return stack[top--];
    else
        return INVALID;
}

int icp(char c) {
    if (c == '+' || c == '-')
        return 1;
    else if (c == '*' || c == '/')
        return 3;
    else if (c == '^')
        return 6;
    else if (c == '(')
        return 7;
    else if (c == ')')
        return 0;
    else
        return -1;
}

int isp(char c) {
    if (c == '+' || c == '-')
        return 2;
    else if (c == '*' || c == '/')
        return 4;
    else if (c == '^')
        return 5;
    else if (c == '(')
        return 0;
    else
        return -1;
}

int isoperand(char ch) {
    if ((ch >= '0' && ch <= '9') || (ch >= 'a' && ch <= 'z'))
        return 1;
    return 0;
}

int main() {
    char ch, op, infix[20], post[20], item, x;
    int l, i = 0, j = 0, citem;
    float res, a, b;

    printf("Enter the infix expression : ");
    scanf("%s", infix);

    for (i = 0; infix[i] != '\0'; i++)
        push(infix[i]);

    ch = pop();

    for (j = 0; j < i; j++) {
        if (ch == '(')
            infix[j] = ')';
        else if (ch == ')')
            infix[j] = '(';
        else
            infix[j] = ch;
        ch = pop();
    }

    l = i;
    i = j = 0;

    strcat(infix, ")");
    push('(');

    while (top != -1) {
        item = infix[i++];
        x = pop();

        if (isoperand(item)) {
            post[j++] = item;
            push(x);
        } else if (item == ')') {
            while (x != '(') {
                post[j++] = x;
                x = pop();
            }
        } else if (isp(x) >= icp(item)) {
            while (isp(x) >= icp(item)) {
                post[j++] = x;
                x = pop();
            }
            push(x);
            push(item);
        } else if (isp(x) < icp(item)) {
            push(x);
            push(item);
        }
    }

    post[j++] = '\0';

    for (i = 0; post[i] != '\0'; i++) {
        push(post[i]);
    }

    ch = pop();
    printf("\nResult == ");

    while (ch != INVALID) {
        printf("%c", ch);
        ch = pop();
    }

    printf("\n\n");
    return 0;
}
