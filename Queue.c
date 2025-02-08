#include <stdio.h>

#define SIZE 5
#define INVALID -99999

int queue[SIZE], f = -1, r = -1;

void enque(int item) {
    if (r == SIZE - 1)
        printf("Queue is full\n");
    else {
        if (f == -1)
            f = 0;
        queue[++r] = item;
    }
}

int deque() {
    if (r == -1)
        printf("Queue is empty\n");
    else {
        int item = queue[f++];
        if (f > r)
            f = r = -1;
        return item;
    }
    return INVALID;
}

void show() {
    if (r != -1) {
        int i;
        printf("\n-->");
        for (i = f; i <= r; i++)
            printf(" %d ", queue[i]);
        printf("\n");
    }
}

int main() {
    int flag = 0, in, out;

    printf("1 - Enque\n2 - Deque\n3 - Display\n4 - Exit\n");

    while (flag != 4) {
        printf("\nEnter the choice : ");
        scanf("%d", &flag);

        switch (flag) {
            case 1:
                printf("Enter element : ");
                scanf("%d", &in);
                enque(in);
                break;
            case 2:
                out = deque();
                if (out != INVALID)
                    printf("Dequeued : %d\n", out);
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
