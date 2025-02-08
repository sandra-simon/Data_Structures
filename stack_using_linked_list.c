#include <stdio.h>
#include <stdlib.h>

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

void pop(struct node *top) {
    if (top->next == NULL) {
        printf("Stack underflow..\n");
    } else {
        struct node *temp = top->next;
        top->next = temp->next;
        printf("Deleted data: %d\n", temp->data);
        free(temp);
    }
}

void display(struct node *top) {
    top = top->next;
    printf("Elements are: ");
    while (top != NULL) {
        printf("%d ", top->data);
        top = top->next;
    }
    printf("\n");
}

int main() {
    struct node *top = getnode(0);
    int flag = 0, in;

    printf("1. Push 2. Pop 3. Display 4. Exit\n");
    while (flag != 4) {
        printf("\nEnter the choice: ");
        scanf("%d", &flag);
        switch (flag) {
            case 1:
                printf("Enter: ");
                scanf("%d", &in);
                push(top, in);
                break;
            case 2:
                pop(top);
                break;
            case 3:
                display(top);
                break;
            case 4:
                break;
            default:
                printf("Invalid input\n");
        }
    }
    return 0;
}
