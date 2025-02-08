/* Create a binary tree with the following operations :
1. Insert a new node
2. Inorder traversal
3. Preorder traversal
4. Postorder traversal
5. Delete a node */


#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
} *temp, *gparent, *gchild;

struct node *getnode() {
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

void buildtree(struct node *ptr, int data) {
    int Data, ch;
    if (ptr != NULL) {
        ptr->data = data;
        printf("Does [%d] have a left child [y=1/n=2]: ", ptr->data);
        scanf("%d", &ch);
        if (ch == 1) {
            printf("Enter the element: ");
            scanf("%d", &Data);
            temp = getnode();
            ptr->left = temp;
            buildtree(temp, Data);
        } else {
            ptr->left = NULL;
        }
        printf("Does [%d] have a right child [y=1/n=2]: ", ptr->data);
        scanf("%d", &ch);
        if (ch == 1) {
            printf("Enter the element: ");
            scanf("%d", &Data);
            temp = getnode();
            ptr->right = temp;
            buildtree(temp, Data);
        } else {
            ptr->right = NULL;
        }
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

void inorderparent(struct node *ptr, int item) {
    if (ptr != NULL) {
        if (ptr->left != NULL && ptr->left->data == item) {
            gparent = ptr;
            gchild = ptr->left;
            return;
        } else if (ptr->right != NULL && ptr->right->data == item) {
            gparent = ptr;
            gchild = ptr->right;
            return;
        }
        if (ptr->data == item) {
            gchild = ptr;
            gparent = NULL;
        }
        inorderparent(ptr->left, item);
        inorderparent(ptr->right, item);
    }
}

void successor(struct node *ptr) {
    gparent = ptr;
    if (ptr->right != NULL) {
        ptr = ptr->right;
        while (ptr->left != NULL) {
            gparent = ptr;
            ptr = ptr->left;
        }
    }
    gchild = ptr;
}

void deletenode() {
    struct node *child = gchild;
    struct node *parent = gparent;
    if (parent == NULL) {
        if (child != NULL) {
            successor(child);
            child->data = gchild->data;
            deletenode();
        }
    } else if (child->left == NULL && child->right == NULL) {
        if (parent->left == child) {
            free(child);
            parent->left = NULL;
        } else {
            free(child);
            parent->right = NULL;
        }
    } else if (child->right == NULL) {
        if (parent->left == child) {
            parent->left = child->left;
            free(child);
        } else {
            parent->right = child->left;
            free(child);
        }
    } else if (child->left == NULL) {
        if (parent->left == child) {
            parent->left = child->right;
            free(child);
        } else {
            parent->right = child->right;
            free(child);
        }
    } else {
        successor(child);
        child->data = gchild->data;
        deletenode();
    }
}

int main() {
    struct node *root = getnode();
    int rootelement, a;
    printf("Enter the root element: ");
    scanf("%d", &rootelement);
    buildtree(root, rootelement);
    printf("\nInorder: ");
    inorder(root);
    printf("\nPreorder: ");
    preorder(root);
    printf("\nPostorder: ");
    postorder(root);
    printf("\nEnter the element to be deleted: ");
    scanf("%d", &a);
    inorderparent(root, a);
    deletenode();
    printf("\n\nInorder: ");
    inorder(root);
    printf("\nPreorder: ");
    preorder(root);
    printf("\nPostorder: ");
    postorder(root);
    printf("\n");
    return 0;
}
