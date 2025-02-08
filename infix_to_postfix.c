#include<stdio.h>
#include<string.h>
#define INVALID '\0'
#define FINVALID -99999.99
#define SIZE 20


float fstack[SIZE];
int ftop = -1;

void fpush(float item)
{
	if (ftop == SIZE - 1)
	{
		printf("Stack overflow!!\n");
	}
	else
	{
		fstack[++ftop] = item;
	}
}

float fpop()
{
	if (ftop != -1)
	{
		return fstack[ftop--];
	}
	else
	{
		printf("Stack underflow!!\n");
 		return FINVALID;
	}
}

char stack[SIZE];
int top = -1;

void push(char item)
{
	if (top == SIZE - 1)
	{
		printf("Stack overflow!!\n");
	}
	else
	{
		stack[++top] = item;
	}
}

char pop()
{
	if (top != -1)
	{
		return stack[top--];
	}
	else
	{
		printf("Stack underflow!!\n");
		return INVALID;
	}
}

int icp(char c)
{
	if (c == '+' || c == '-') return 1;
	else if (c == '*' || c == '/') return 3;
	else if (c == '^') return 6;
	else if (c == '(') return 7;
	else if (c == ')') return 0;
	else return -1;
}

int isp(char c)
{
	if (c == '+' || c == '-') return 2;
	else if (c == '*' || c == '/') return 4;
	else if (c == '^') return 5;
	else if (c == '(') return 0;
	else return -1;
}

int isoperand(char ch)
{
	if (ch <= '9' && ch >= '0') return 1;
	return 0;
}

float calculate(float a, char op, float b)
{
	if (op == '*') return (a * b);
	else if (op == '/') return (a / b);
	else if (op == '^')
	{
		float c = 1;
		int i;
 		for (i = 0; i < b; i++)
		{
			c *= a;
 		}
		return c;
	}
	else if (op == '+') return (a + b);
	else if (op == '-') return (a - b);
	else return FINVALID;
}

int main()
{
	char op, infix[20], post[20], item, x;
	int i = 0, j = 0, citem;
	float res, a, b;

	printf("Enter the infix expression : ");
	scanf("%s", infix);
	strcat(infix, ")");
	push('(');

 	while (top > -1)
	{
 		item = infix[i++];
		x = pop();
 		if (isoperand(item))
		{
			post[j++] = item;
			push(x);
		}
		else if (item == ')')\
		{
			while (x != '(')
			{
				post[j++] = x;
				x = pop();
 			}
		}
		else if (isp(x) >= icp(item))
		{
			while (isp(x) >= icp(item))
			{
				post[j++] = x;
				x = pop();
			}
			push(x);
			push(item);
		}
		else if (isp(x) < icp(item))
		{
			push(x);
			push(item);
 		}
	}
	printf("\n\n -> %s\n\n", post);
	post[j++] = '#';
	post[j++] = '\0';
	i = 0;
	citem = post[i++];
	while (citem != '#')
	{
		if (isoperand(citem))
		{
			fpush((citem - '0'));
		}
		else
		{
			op = citem;
			b = fpop();
			a = fpop();
			res = calculate(a, op, b);
			fpush(res);
 		}
		citem = post[i++];
	}
	res = fpop();
	printf("\n\nResult = %.2f\n\n", res);
	return 0;
}
