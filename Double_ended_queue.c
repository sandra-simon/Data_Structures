#include <stdio.h>
#define SIZE 5
#define INVALID -99999

int queue[SIZE], f = -1, r = -1;

void enque(int item, int pos) {
    if (pos == 2) {
        if ((r + 1) % SIZE == f) {
            printf("Queue is full\n");
        } else {
            if (f == -1) f = 0;
            r = (r + 1) % SIZE;
            queue[r] = item;
        }
    } else if (pos == 1) {
        if ((r + 1) % SIZE == f) {
            printf("Queue is full\n");
        } else {
            if (f == 0) f = SIZE - 1;
            else if (f == -1) f = r = 0;
            else f = f - 1;
            queue[f] = item;
        }
    }
}

int deque(int pos) {
    if (pos == 1) {
        if (r == -1) {
            printf("Queue is empty\n");
        } else {
            int item = queue[f];
            f = (f + 1) % SIZE;
            if (f == (r + 1) % SIZE) f = r = -1;
            return item;
        }
    } else if (pos == 2) {
        if (f == -1) {
            printf("Queue is empty\n");
        } else {
            int item = queue[r];
            if (r == 0) r = SIZE - 1;
            else r = r - 1;
            if (f == (r + 1) % SIZE) f = r = -1;
            return item;
        }
    }
    return INVALID;
}

void show() {
    if (r != -1) {
        int i;
        if (f <= r) {
            for (i = f; i <= r; i++) printf("%d ", queue[i]);
        } else {
            for (i = f; i < SIZE; i++) printf("%d ", queue[i]);
            for (i = 0; i <= r; i++) printf("%d ", queue[i]);
        }
    }
}

int main() {
    int flag = 0, in, out, dir;
    printf("1 - Enque\n2 - Deque\n3 - Display\n4 - Exit\n");

    while (flag != 4) {
        printf("\nEnter the choice : ");
        scanf("%d", &flag);
        switch (flag) {
            case 1:
                printf("Enter value and direction: ");
                scanf("%d%d", &in, &dir);
                enque(in, dir);
                break;
            case 2:
                printf("Enter the direction : ");
                scanf("%d", &dir);
                out = deque(dir);
                if (out != INVALID) printf("Dequeued element: %d\n", out);
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
