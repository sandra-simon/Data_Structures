#include <stdio.h>
#define MAX 20  // Increased MAX to prevent overflow

struct poly {
    int exp, coeff;
};

void printpoly(struct poly a[], int b) {
    int i;
    for (i = 0; i < b; i++) {
        if (i != b - 1)
            printf("%dX^%d + ", a[i].coeff, a[i].exp);
        else
            printf("%dX^%d\n\n", a[i].coeff, a[i].exp);
    }
}

int main() {
    struct poly p[MAX], q[MAX], r[MAX];
    int i, j, k, n, m;

    printf("How many elements are in the first polynomial: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("Enter the coeff and exp: ");
        scanf("%d%d", &p[i].coeff, &p[i].exp);
    }

    printf("How many elements are in the second polynomial: ");
    scanf("%d", &m);
    for (i = 0; i < m; i++) {
        printf("Enter the coeff and exp: ");
        scanf("%d%d", &q[i].coeff, &q[i].exp);
    }

    i = j = k = 0;
    while (i < n && j < m) {
        if (p[i].exp == q[j].exp) {
            r[k].coeff = q[j].coeff + p[i].coeff;
            r[k].exp = q[j].exp;
            i++;
            j++;
            k++;
        } else if (p[i].exp > q[j].exp) {
            r[k].coeff = p[i].coeff;
            r[k].exp = p[i].exp;
            i++;
            k++;
        } else {
            r[k].coeff = q[j].coeff;
            r[k].exp = q[j].exp;
            j++;
            k++;
        }
    }

    while (i < n) {
        r[k].coeff = p[i].coeff;
        r[k].exp = p[i].exp;
        i++;
        k++;
    }

    while (j < m) {
        r[k].coeff = q[j].coeff;
        r[k].exp = q[j].exp;
        j++;
        k++;
    }

    printf("\nFirst Polynomial: ");
    printpoly(p, n);

    printf("Second Polynomial: ");
    printpoly(q, m);

    printf("Resultant Polynomial: ");
    printpoly(r, k);

    return 0;
}
