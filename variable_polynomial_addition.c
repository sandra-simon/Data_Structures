/* A program for addition of polynomials containing two variables using linked list. The terms of the polynomials are ordered by the power of the first variable and then the second variable, in the descending order. */


#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node *next;
    int exp, coeff, yexp;
};

struct node *getnode(int exp, int yexp, int coeff) {
    struct node *ne = (struct node *)malloc(sizeof(struct node));
    ne->next = NULL;
    ne->exp = exp;
    ne->coeff = coeff;
    ne->yexp = yexp;
    return ne;
}

void insert(struct node *head, int count) {
    struct node *temp;
    int coeff, exp, yexp;
    while (count > 0) {
        printf("Enter the coeff, exp of x, and exp of y respectively: ");
        scanf("%d%d%d", &coeff, &exp, &yexp);
        temp = getnode(exp, yexp, coeff);
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
                printf("%dx^%dy^%d\n\n", head->coeff, head->exp, head->yexp);
                break;
            }
            printf("%dx^%dy^%d + ", head->coeff, head->exp, head->yexp);
            head = head->next;
        }
    } else {
        printf("Empty..\n");
    }
}

int main() {
    struct node *p1, *p2, *p3, *ptr1, *ptr2, *ptr3, *temp;
    int n;

    p1 = getnode(0, 0, 0);
    p2 = getnode(0, 0, 0);
    p3 = getnode(0, 0, 0);

    printf("How many elements for Polynomial 1: ");
    scanf("%d", &n);
    insert(p1, n);

    printf("How many elements for Polynomial 2: ");
    scanf("%d", &n);
    insert(p2, n);

    ptr1 = p1->next;
    ptr2 = p2->next;
    ptr3 = p3;

    while (ptr1 != NULL && ptr2 != NULL) {
        if (ptr1->exp == ptr2->exp && ptr1->yexp == ptr2->yexp) {
            temp = getnode(ptr1->exp, ptr1->yexp, ptr1->coeff + ptr2->coeff);
            ptr3->next = temp;
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
            ptr3 = ptr3->next;
        } else if (ptr1->exp > ptr2->exp || (ptr1->exp == ptr2->exp && ptr1->yexp > ptr2->yexp)) {
            temp = getnode(ptr1->exp, ptr1->yexp, ptr1->coeff);
            ptr3->next = temp;
            ptr1 = ptr1->next;
            ptr3 = ptr3->next;
        } else {
            temp = getnode(ptr2->exp, ptr2->yexp, ptr2->coeff);
            ptr3->next = temp;
            ptr2 = ptr2->next;
            ptr3 = ptr3->next;
        }
    }

    while (ptr1 != NULL) {
        temp = getnode(ptr1->exp, ptr1->yexp, ptr1->coeff);
        ptr3->next = temp;
        ptr1 = ptr1->next;
        ptr3 = ptr3->next;
    }

    while (ptr2 != NULL) {
        temp = getnode(ptr2->exp, ptr2->yexp, ptr2->coeff);
        ptr3->next = temp;
        ptr2 = ptr2->next;
        ptr3 = ptr3->next;
    }

    printf("\nPolynomial 1: ");
    display(p1);

    printf("\nPolynomial 2: ");
    display(p2);

    printf("\nResultant Polynomial: ");
    display(p3);

    return 0;
}
