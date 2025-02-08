#include <stdio.h>

#define SIZE 5
#define INVALID -99999

int pq[10][SIZE], f[10], r[10];

void init_fr() {
    int i;
    for (i = 0; i < 10; i++) {
        f[i] = r[i] = -1;
    }
}

void enque(int item, int pr) {
    if (r[pr] == SIZE - 1)
        printf("Queue is full\n");
    else {
        if (f[pr] == -1)
            f[pr] = 0;
        pq[pr][++r[pr]] = item;
    }
}

int deque() {
    int i;
    for (i = 0; i < 10; i++) {
        if (r[i] != -1) {
            int item = pq[i][f[i]];
            f[i]++;
            if (f[i] > r[i])
                f[i] = r[i] = -1;
            return item;
        }
    }
    return INVALID;
}

void show() {
    int i;
    for (i = 0; i < 10; i++) {
        if (r[i] != -1) {
            int j;
            for (j = f[i]; j <= r[i]; j++)
                printf(" %d ", pq[i][j]);
        }
    }
    printf("\n");
}

int main() {
    int flag = 0, in, pr, out;
    init_fr();

    printf("1 - Enque\n2 - Deque\n3 - Display\n4 - Exit\n");

    while (flag != 4) {
        printf("\nEnter the choice : ");
        scanf("%d", &flag);

        switch (flag) {
            case 1:
                printf("Enter the value and priority: ");
                scanf("%d%d", &in, &pr);
                enque(in, pr);
                break;
            case 2:
                out = deque();
                if (out != INVALID)
                    printf("Dequeued element: %d\n", out);
                break;
            case 3:
                show();
                break;
            case 4:
                break;
            default:
                printf("Invalid input\n");
        }
    }
    return 0;
}
