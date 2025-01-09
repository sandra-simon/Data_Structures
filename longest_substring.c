/*Given a string s, write a C program to find the length of the longest substring without  repeating characters. Also, display the substring.*/

#include<stdio.h>
#include<string.h>

int isunique(char *str, int start, int end)
{
	int i, j, visited[256];
	for (i = 0; i < 256; i++)
	{
		visited[i] = 0;
	}
	int flag = 1;
	for (j = start; j <= end; j++)
	{
		if(visited[str[j]] == 1)
		{
			flag = 0;
 			break;
 		}
		visited[str[j]] = 1;
 	}
	return flag;
}

void main()
{
	char str[100], sub[50];
	int i, j, len, start = 0, max = 0;
	printf("Enter the string: ");
	scanf("%s", str);
	len = strlen(str);
	for (i = 0; i < len; i++)
	{
		for (j = i; j < len; j++)
		{
			if (isunique(str, i, j))
			{
				if (j - i + 1 > max)
				{
					max = j - i + 1;
					start = i;
				}
			}
		}
	}
 	strncpy(sub, str + start, max);
	sub[max] = '\0';
	printf("\nLongest non-repeating substring is: %s\n", sub);
}
