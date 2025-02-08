/*Created a doubly linked list from a string taking each character from the string and checks if the string is palindrome or not*/

#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node *prev, *next;
    char data;
};

struct node *getnode(char data) {
    struct node *ne = (struct node *)malloc(sizeof(struct node));
    ne->prev = NULL;
    ne->next = NULL;
    ne->data = data;
    return ne;
}

int main() {
    char str[30];
    printf("Enter the string: ");
    scanf("%s", str);

    struct node *head, *tail, *temp, *ptr1, *ptr2;
    head = getnode(str[0]);
    tail = head;

    int i = 1, flag = 1;
    while (str[i] != '\0') {
        temp = getnode(str[i]);
        temp->prev = tail;
        tail->next = temp;
        tail = temp;
        i++;
    }

    ptr1 = head;
    ptr2 = tail;

    while (ptr1 != ptr2) {
        if (ptr1->data != ptr2->data) {
            flag = 0;
            break;
        } else if (ptr1->next == ptr2) {
            break;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->prev;
    }

    if (flag)
        printf("Palindrome.\n");
    else
        printf("Not palindrome.\n");

    return 0;
}
