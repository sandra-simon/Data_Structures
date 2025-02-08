/*A program to reverse the contents of a queue using stack*/


#include <stdio.h>
#include <stdlib.h>

#define INVALID -99999

struct node {
    struct node *next;
    int data;
};

struct node *getnode(int data) {
    struct node *ne = (struct node *)malloc(sizeof(struct node));
    ne->next = NULL;
    ne->data = data;
    return ne;
}

void push(struct node *top, int data) {
    struct node *temp = getnode(data);
    temp->next = top->next;
    top->next = temp;
}

int pop(struct node *top) {
    if (top->next == NULL) {
        return INVALID;
    } else {
        struct node *temp = top->next;
        int data = temp->data;
        top->next = temp->next;
        free(temp);
        return data;
    }
}

void enque(struct node *head, int data) {
    struct node *temp = getnode(data);
    while (head->next != NULL) {
        head = head->next;
    }
    head->next = temp;
}

int deque(struct node *head) {
    if (head->next == NULL) {
        return INVALID;
    } else {
        struct node *temp = head->next;
        int data = temp->data;
        head->next = temp->next;
        free(temp);
        return data;
    }
}

void display(struct node *head) {
    head = head->next;
    if (head != NULL) {
        printf("Elements are: ");
        while (head != NULL) {
            printf(" %d", head->data);
            head = head->next;
        }
        printf("\n");
    } else {
        printf("Empty list..\n");
    }
}

int main() {
    struct node *stack = getnode(0);
    struct node *queue = getnode(0);
    int flag = 0, out = 0, in, ct, i;

    printf("How many elements: ");
    scanf("%d", &ct);

    printf("Enter the elements: ");
    for (i = 0; i < ct; i++) {
        scanf("%d", &in);
        enque(queue, in);
    }

    printf("Before reversing -> ");
    display(queue);

    out = deque(queue);
    while (out != INVALID) {
        push(stack, out);
        out = deque(queue);
    }

    out = pop(stack);
    while (out != INVALID) {
        enque(queue, out);
        out = pop(stack);
    }

    printf("After reversing -> ");
    display(queue);

    return 0;
}
