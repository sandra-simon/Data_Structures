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

void enque(struct node *head, int data) {
    struct node *temp = getnode(data);
    while (head->next != NULL)
        head = head->next;
    head->next = temp;
}

void deque(struct node *head) {
    if (head->next == NULL) {
        printf("Queue empty\n");
    } else {
        struct node *temp = head->next;
        head->next = temp->next;
        printf("Deleted data: %d\n", temp->data);
        free(temp);
    }
}

void display(struct node *head) {
    head = head->next;
    if (head != NULL) {
        printf("Elements are: ");
        while (head != NULL) {
            printf("%d ", head->data);
            head = head->next;
        }
        printf("\n");
    } else {
        printf("Queue empty\n");
    }
}

int main() {
    struct node *head = getnode(0);
    int flag = 0, in;

    printf("1. Enqueue 2. Dequeue 3. Display 4. Exit\n");
    while (flag != 4) {
        printf("\nEnter the choice: ");
        scanf("%d", &flag);
        switch (flag) {
            case 1:
                printf("Enter: ");
                scanf("%d", &in);
                enque(head, in);
                break;
            case 2:
                deque(head);
                break;
            case 3:
                display(head);
                break;
            case 4:
                break;
            default:
                printf("Invalid input\n");
        }
    }
    return 0;
}
