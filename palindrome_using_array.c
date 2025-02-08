#include <stdio.h>
#define SIZE 20
#define INVALID '\0'


char stack[SIZE];
int top = -1;

void push(char item)
{
	if (top == SIZE - 1)
	{
		printf("Stack Overflow!!\n");
	}
	else
	{
		stack[++top] = item;
	}
}

char pop()
{
	if (top == -1)
	{
		printf("Stack Underflow!!\n");
		return INVALID;
	}
	else
	{
		return stack[top--];
	}
}

int main()
{
	char str[20];
	printf("Enter the string : ");
	scanf("%19s", str);
	int i, flag = 1;
	for (i = 0; str[i] != '\0'; i++)
	{
		push(str[i]);
	}
	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] != pop())
		{
			flag = 0;
			break;
		}
	}
	if (flag)
	{
		printf("The given string is palindrome.\n");
	}
	else
	{
		printf("The given string is not palindrome.\n");
	}
	return 0;
}
