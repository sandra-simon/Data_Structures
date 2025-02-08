/*The details of students (number, name and total mark) are to be stored in a linked list.
Write functions for the following operations.
1. Insert (at the beginning)
2. Delete (based on number)
3. Search (based on name or number)
4. Sort on the basis of number 
5. Display*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    int no, mark;
    char name[50];
    struct node *link;
};

struct node *getnode(int no, char name[], int mark) {
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->no = no;
    temp->mark = mark;
    strcpy(temp->name, name);
    temp->link = NULL;
    return temp;
}

void swap(struct node *p, struct node *q) {
    struct node t;
    t.no = p->no;
    t.mark = p->mark;
    strcpy(t.name, p->name);

    p->no = q->no;
    p->mark = q->mark;
    strcpy(p->name, q->name);

    q->no = t.no;
    q->mark = t.mark;
    strcpy(q->name, t.name);
}

void display(struct node *head) {
    struct node *ptr = head->link;
    printf("\nStudent details:\n");
    if (ptr == NULL) {
        printf("List is empty.\n");
        return;
    }
    while (ptr != NULL) {
        printf("[%d] %s, %d marks\n", ptr->no, ptr->name, ptr->mark);
        ptr = ptr->link;
    }
    printf("\n");
}

void insertfront(struct node *head, int no, char name[], int mark) {
    struct node *ne = getnode(no, name, mark);
    if (ne == NULL) {
        printf("Memory underflow\n");
    } else {
        ne->link = head->link;
        head->link = ne;
        printf("Data inserted successfully..\n");
    }
}

void deleteposition(struct node *head, int key) {
    struct node *ptr = head->link, *temp = head;
    if (ptr == NULL) {
        printf("List is empty.\n");
        return;
    }

    while (ptr != NULL && ptr->no != key) {
        temp = ptr;
        ptr = ptr->link;
    }

    if (ptr != NULL) {
        temp->link = ptr->link;
        printf("Deleted data -> [%d] %s, %d marks\n", ptr->no, ptr->name, ptr->mark);
        free(ptr);
    } else {
        printf("Student not found..\n");
    }
}

void sort(struct node *head) {
    struct node *ptr1, *ptr2;
    if (head->link == NULL) {
        printf("List is empty.\n");
        return;
    }

    for (ptr1 = head->link; ptr1 != NULL; ptr1 = ptr1->link) {
        for (ptr2 = ptr1->link; ptr2 != NULL; ptr2 = ptr2->link) {
            if (ptr1->no > ptr2->no) {
                swap(ptr1, ptr2);
            }
        }
    }
    printf("Sorted successfully.\n");
}

void search(struct node *head) {
    char keyname[50];
    int key, ch, found = 0;
    struct node *ptr = head->link;

    if (ptr == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Search by name(1) or number(2): ");
    scanf("%d", &ch);

    if (ch == 1) {
        printf("Enter the name: ");
        scanf("%s", keyname);
        while (ptr != NULL) {
            if (strcmp(ptr->name, keyname) == 0) {
                printf("Details found -> [%d] %s, %d marks\n", ptr->no, ptr->name, ptr->mark);
                found = 1;
            }
            ptr = ptr->link;
        }
    } else if (ch == 2) {
        printf("Enter the number: ");
        scanf("%d", &key);
        while (ptr != NULL) {
            if (ptr->no == key) {
                printf("Details found -> [%d] %s, %d marks\n", ptr->no, ptr->name, ptr->mark);
                found = 1;
            }
            ptr = ptr->link;
        }
    } else {
        printf("Invalid choice.\n");
        return;
    }

    if (!found) {
        printf("Student not found.\n");
    }
}

int main() {
    char name[50];
    struct node *head = getnode(0, name, 0);
    int choice = 0, no, mark, key;

    while (choice != 6) {
        printf("\n1. Insert  2. Delete  3. Display  4. Search  5. Sort  6. Exit\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the number, name, and marks: ");
                scanf("%d %s %d", &no, name, &mark);
                insertfront(head, no, name, mark);
                break;
            case 2:
                printf("Enter the number: ");
                scanf("%d", &key);
                deleteposition(head, key);
                break;
            case 3:
                display(head);
                break;
            case 4:
                search(head);
                break;
            case 5:
                sort(head);
                break;
            case 6:
                break;
            default:
                printf("Invalid input!\n");
                break;
        }
    }
    return 0;
}

