/* Write a program to create a binary search tree (data items are integers) with the following operations
1. Insert a new node
2. Inorder traversal
3. Preorder traversal
4. Postorder traversal
5. Delete a node
6. Find the number of leaf nodes
7. Sort the input numbers */


#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

struct node *getnode() {
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

void insert(struct node *ptr, int item) {
    int f = 0;
    struct node *ptr1 = NULL;
    while (ptr != NULL) {
        if (item < ptr->data) {
            ptr1 = ptr;
            ptr = ptr->left;
        } else if (item > ptr->data) {
            ptr1 = ptr;
            ptr = ptr->right;
        } else if (item == ptr->data) {
            f = 1;
            printf("Duplication...\n");
            break;
        }
    }
    if (ptr1 != NULL && f == 0) {
        struct node *ne = getnode();
        ne->data = item;
        if (ptr1->data > item)
            ptr1->left = ne;
        else
            ptr1->right = ne;
    }
}

void leafcount(struct node *ptr, int *count) {
    if (ptr != NULL) {
        leafcount(ptr->left, count);
        if (ptr->left == NULL && ptr->right == NULL)
            (*count)++;
        leafcount(ptr->right, count);
    }
}

void inorder(struct node *ptr) {
    if (ptr != NULL) {
        inorder(ptr->left);
        printf(" %d", ptr->data);
        inorder(ptr->right);
    }
}

void preorder(struct node *ptr) {
    if (ptr != NULL) {
        printf(" %d", ptr->data);
        preorder(ptr->left);
        preorder(ptr->right);
    }
}

void postorder(struct node *ptr) {
    if (ptr != NULL) {
        postorder(ptr->left);
        postorder(ptr->right);
        printf(" %d", ptr->data);
    }
}

void inorderparent(struct node *ptr, int item, struct node **gparent, struct node **gchild) {
    if (ptr != NULL) {
        if (ptr->left != NULL && ptr->left->data == item) {
            *gparent = ptr;
            *gchild = ptr->left;
            return;
        } else if (ptr->right != NULL && ptr->right->data == item) {
            *gparent = ptr;
            *gchild = ptr->right;
            return;
        }
        inorderparent(ptr->left, item, gparent, gchild);
        inorderparent(ptr->right, item, gparent, gchild);
    }
}

void successor(struct node *ptr, struct node **gparent, struct node **gchild) {
    *gparent = ptr;
    ptr = ptr->right;
    while (ptr->left != NULL) {
        *gparent = ptr;
        ptr = ptr->left;
    }
    *gchild = ptr;
}

void deletenode(struct node *gparent, struct node *gchild) {
    int s = gchild->data;
    printf("\n%d ---> %d ", gparent->data, gchild->data);
    if (gchild == NULL || gparent == NULL) {
        printf("---");
    } else if (gchild->left == NULL && gchild->right == NULL) {
        if (gparent->left == gchild) {
            free(gchild);
            printf("Deleted......left");
            gparent->left = NULL;
        } else {
            free(gchild);
            printf("Deleted......right");
            gparent->right = NULL;
        }
    } else if (gchild->right == NULL) {
        if (gparent->left == gchild) {
            gparent->left = gchild->left;
            free(gchild);
        } else {
            gparent->right = gchild->left;
            free(gchild);
        }
    } else if (gchild->left == NULL) {
        if (gparent->left == gchild) {
            gparent->left = gchild->right;
            free(gchild);
        } else {
            gparent->right = gchild->right;
            free(gchild);
        }
    } else {
        successor(gchild, &gparent, &gchild);
        gchild->data = gchild->data;
        deletenode(gparent, gchild);
    }
}

int main() {
    struct node *root = getnode();
    int rootelement, n, i, a, count = 0;
    printf("\nEnter the number of elements: ");
    scanf("%d", &n);
    printf("Enter the elements: ");
    scanf("%d", &rootelement);
    root->data = rootelement;
    for (i = 0; i < n - 1; i++) {
        scanf("%d", &a);
        insert(root, a);
    }
    printf("\nInorder: ");
    inorder(root);
    printf("\nPreorder: ");
    preorder(root);
    printf("\nPostorder: ");
    postorder(root);
    printf("\n\n");
    printf("Enter the element to be deleted: ");
    scanf("%d", &a);
    struct node *gparent = NULL, *gchild = NULL;
    inorderparent(root, a, &gparent, &gchild);
    deletenode(gparent, gchild);
    count = 0;
    leafcount(root, &count);
    printf("\n\nNo of leaf nodes -> %d\n", count);
    printf("\n\nInorder: ");
    inorder(root);
    printf("\nPreorder: ");
    preorder(root);
    printf("\nPostorder: ");
    postorder(root);
    printf("\n\n");
    return 0;
}
