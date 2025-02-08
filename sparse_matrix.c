#include <stdio.h>

struct tuple {
    int row, col, val;
};

void createsparse(int m[10][10], struct tuple a[], int r, int c) {
    int k = 1, i, j;
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            if (m[i][j] != 0) {
                a[k].row = i;
                a[k].col = j;
                a[k].val = m[i][j];
                k++;
            }
        }
    }
    a[0].row = r;
    a[0].col = c;
    a[0].val = k - 1;
}

void displaysparse(struct tuple a[]) {
    printf("\nSparse matrix\n");
    for (int i = 0; i <= a[0].val; i++)
        printf("%d - %d - %d\n", a[i].row, a[i].col, a[i].val);
}

void transpose(struct tuple a[], struct tuple b[]) {
    int n = a[0].val, q = 1;
    b[0].col = a[0].row;
    b[0].row = a[0].col;
    b[0].val = n;
    for (int i = 0; i < a[0].col; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[j].col == i) {
                b[q].col = a[j].row;
                b[q].row = a[j].col;
                b[q].val = a[j].val;
                q++;
            }
        }
    }
}

void addsparse(struct tuple p[], struct tuple q[], struct tuple r[]) {
    r[0].col = p[0].col;
    r[0].row = p[0].row;
    int i = 1, j = 1, k = 1;
    while (i <= p[0].val && j <= q[0].val) {
        if (p[i].row > q[j].row || (p[i].row == q[j].row && p[i].col > q[j].col)) {
            r[k] = q[j];
            j++;
        } else if (p[i].row < q[j].row || (p[i].row == q[j].row && p[i].col < q[j].col)) {
            r[k] = p[i];
            i++;
        } else {
            r[k].row = q[j].row;
            r[k].col = q[j].col;
            r[k].val = p[i].val + q[j].val;
            i++;
            j++;
        }
        k++;
    }
    while (i <= p[0].val) r[k++] = p[i++];
    while (j <= q[0].val) r[k++] = q[j++];
    r[0].val = k - 1;
}

int main() {
    int m1[10][10], m2[10][10], r, c_, i, j;
    struct tuple a[20], b[20], c[30], at[20], bt[20];

    printf("Enter the row and columns: ");
    scanf("%d%d", &r, &c_);

    printf("Enter the elements of first matrix: ");
    for (i = 0; i < r; i++)
        for (j = 0; j < c_; j++)
            scanf("%d", &m1[i][j]);

    printf("Enter the elements of second matrix: ");
    for (i = 0; i < r; i++)
        for (j = 0; j < c_; j++)
            scanf("%d", &m2[i][j]);

    createsparse(m1, a, r, c_);
    createsparse(m2, b, r, c_);
    transpose(a, at);
    transpose(b, bt);
    addsparse(at, bt, c);

    displaysparse(at);
    displaysparse(bt);
    displaysparse(c);

    return 0;
}
