/*Implement Stack using array.*/


#include <stdio.h>
#define SIZE 5
#define INVALID -99999
int stack[SIZE], top = -1;
void push(int item)
{
	if (top == SIZE - 1)
	printf("Stack Overflow!!\n");
	else
	stack[++top] = item;
}

int pop()
{
 	if (top == -1)
	printf("Stack Underflow!!\n");
	else
	return stack[top--];
	return INVALID;
}

void show()
{
	int i;
	if (top == -1)
	printf("Stack is empty!!\n");
	else
	{
 		printf("Stack elements are : ");
 		for (i = 0; i <= top; i++)
 		printf("%d ", stack[i]);
 		printf("\n");
 	}
}

int main()
{
	int flag = 0, in, out;
	printf("1 - Push\n2 - Pop\n3 - Display\n4 - Exit\n");
	while (flag != 4)
	{
		printf("\nEnter the choice : ");
		scanf("%d", &flag);
 		switch (flag)
		{
			case 1:
			printf("Enter : ");
			scanf("%d", &in);
			push(in);
			break;

			case 2:
			out = pop();
			if (out != INVALID)
			printf("Popped element: %d\n", out);
			break;

			case 3:
			show();
			break;

			case 4: 
			printf("Exiting!!\n");
			break;
			default:
 			printf("Invalid input\n");
		}
	}
	return 0;
}
