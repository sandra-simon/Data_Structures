#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *link;
} *ptr, *ne, *temp;

struct node *getnode(int data) {
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    if (!temp) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    temp->data = data;
    temp->link = NULL;
    return temp;
}

void display(struct node *head) {
    ptr = head->link;
    if (ptr == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("Data elements are:");
    while (ptr != NULL) {
        printf(" %d", ptr->data);
        ptr = ptr->link;
    }
    printf("\n");
}

void insertfront(struct node *head, int data) {
    ne = getnode(data);
    ne->link = head->link;
    head->link = ne;
}

void insertrear(struct node *head, int data) {
    ne = getnode(data);
    ptr = head;
    while (ptr->link != NULL)
        ptr = ptr->link;
    ptr->link = ne;
}

void insertposition(struct node *head, int data, int key) {
    ne = getnode(data);
    ptr = head;
    while (ptr->link != NULL && ptr->data != key)
        ptr = ptr->link;
    if (ptr->data == key) {
        ne->link = ptr->link;
        ptr->link = ne;
    } else {
        printf("Key %d not found. Insertion failed.\n", key);
        free(ne);
    }
}

void deletefront(struct node *head) {
    if (head->link == NULL) {
        printf("Empty list\n");
        return;
    }
    ptr = head->link;
    head->link = ptr->link;
    printf("Deleted data: %d\n", ptr->data);
    free(ptr);
}

void deleterear(struct node *head) {
    if (head->link == NULL) {
        printf("Empty list\n");
        return;
    }
    ptr = head->link;
    temp = head;
    while (ptr->link != NULL) {
        temp = ptr;
        ptr = ptr->link;
    }
    temp->link = NULL;
    printf("Deleted data: %d\n", ptr->data);
    free(ptr);
}

void deleteposition(struct node *head, int key) {
    if (head->link == NULL) {
        printf("Empty list\n");
        return;
    }
    ptr = head->link;
    temp = head;
    while (ptr != NULL && ptr->data != key) {
        temp = ptr;
        ptr = ptr->link;
    }
    if (ptr != NULL) {
        temp->link = ptr->link;
        printf("Deleted data: %d\n", ptr->data);
        free(ptr);
    } else {
        printf("Key %d not found. Deletion failed.\n", key);
    }
}

int main() {
    struct node *head = getnode(0);
    int choice, subChoice, data, key;

    while (1) {
        printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("1. Beginning\n2. End\n3. Insert at position\nEnter your choice: ");
                scanf("%d", &subChoice);
                printf("Enter the data: ");
                scanf("%d", &data);
                switch (subChoice) {
                    case 1: insertfront(head, data); break;
                    case 2: insertrear(head, data); break;
                    case 3:
                        printf("Enter the key position: ");
                        scanf("%d", &key);
                        insertposition(head, data, key);
                        break;
                    default: printf("Invalid input!\n");
                }
                break;
            case 2:
                printf("1. Beginning\n2. End\n3. Delete at position\nEnter your choice: ");
                scanf("%d", &subChoice);
                switch (subChoice) {
                    case 1: deletefront(head); break;
                    case 2: deleterear(head); break;
                    case 3:
                        printf("Enter the key position: ");
                        scanf("%d", &key);
                        deleteposition(head, key);
                        break;
                    default: printf("Invalid input!\n");
                }
                break;
            case 3:
                display(head);
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid input!\n");
        }
    }
    return 0;
}
