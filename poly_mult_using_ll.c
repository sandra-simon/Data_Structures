/* A program that reads two polynomials and stores them using linked list and calculates the product of two polynomials. */


#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node *next;
    int exp, coeff;
};

struct node *getnode(int exp, int coeff) {
    struct node *ne = (struct node *)malloc(sizeof(struct node));
    ne->next = NULL;
    ne->exp = exp;
    ne->coeff = coeff;
    return ne;
}

void insert(struct node *head, int count) {
    struct node *temp;
    int coeff, exp;
    while (count > 0) {
        printf("Enter the coeff & exp: ");
        scanf("%d%d", &coeff, &exp);
        temp = getnode(exp, coeff);
        head->next = temp;
        head = temp;
        count--;
    }
}

void display(struct node *head) {
    head = head->next;
    if (head != NULL) {
        while (head != NULL) {
            if (head->next == NULL) {
                printf("%dx^%d\n\n", head->coeff, head->exp);
                break;
            }
            printf("%dx^%d + ", head->coeff, head->exp);
            head = head->next;
        }
    } else {
        printf("Empty..\n");
    }
}

int main() {
    struct node *p1, *p2, *p3, *ptr1, *ptr2, *ptr3, *temp;
    int n, coeff, exp;

    p1 = getnode(0, 0);
    p2 = getnode(0, 0);
    p3 = getnode(0, 0);

    printf("How many elements for Polynomial 1: ");
    scanf("%d", &n);
    insert(p1, n);

    printf("How many elements for Polynomial 2: ");
    scanf("%d", &n);
    insert(p2, n);

    ptr1 = p1->next;
    ptr3 = p3;

    while (ptr1 != NULL) {
        ptr2 = p2->next;
        while (ptr2 != NULL) {
            coeff = ptr1->coeff * ptr2->coeff;
            exp = ptr1->exp + ptr2->exp;
            temp = getnode(exp, coeff);
            ptr3->next = temp;
            ptr3 = temp;
            ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }

    printf("Polynomial 1: ");
    display(p1);

    printf("Polynomial 2: ");
    display(p2);

    printf("Resultant Polynomial: ");
    display(p3);

    return 0;
}
