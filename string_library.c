/*Implement the following string library functions using pointers:
* string length (int StringLengh (char *s))
* string copy (void StringCopy(char *s1, char *s2) )
* string comparison (int StringCompare (char *s1, char *s2))
* string concatenation (void StringConcat(char *s1, char *s2) )*/


#include <stdio.h>
int StringLength(char *s)
{
	int len;
	for (len = 0; *(s + len) != '\0'; len++);
	{
		return len;
	}
}
void StringCopy(char *s1, char *s2)
{
	int i = 0;
	while (*(s2 + i) != '\0')
	{
		*(s1 + i) = *(s2 + i);
		i++;
	}
	*(s1 + i) = '\0';
}
int StringCompare(char *s1, char *s2)
{
	int i = 0, diff = 0;
	while (*(s1 + i) != '\0' && *(s2 + i) != '\0')
	{
		diff = *(s1 + i) - *(s2 + i);
		if (diff != 0)
		{
			break;
		}
 		i++;
 	}
	return diff;
}
void StringConcat(char *s1, char *s2)
{
	int i = 0, len;
	len = StringLength(s1);
	while (*(s2 + i) != '\0')
	{
		*(s1 + i + len) = *(s2 + i);
		i++;
 	}
	*(s1 + i + len) = '\0';
}

int main()
{
	char s1[40], s2[20], s3[20];
	printf("Enter first string: ");
	scanf("%s", s1);
	printf("Enter second string: ");
	scanf("%s", s2);
	printf("The length of first string: %d\n", StringLength(s1));
	printf("Difference between the first and second strings: %d\n", StringCompare(s1, s2));
	StringCopy(s3, s1);
	printf("Third string after copying the first string: %s\n", s3);
	StringConcat(s1, s2);
	printf("First string after concatenating the second one: %s\n", s1);
	return 0;
}
