/*Write a program to find the smallest number in a list of integers using pointers*/


#include<stdio.h>
void main()
{
	int list[20], n, *s, i;
	printf("How many numbers : ");
	scanf(" %d", &n);
	printf("Enter the elements :");
	for (i = 0; i < n; i++)
	{
		scanf(" %d", list + i);
	}
	s = list;
	for (i = 1; i < n; i++)
	{
		if (*s > *(list + i))
		{
			s = (list + i);
		}
	}
printf("Smallest number is %d \n", *s);
}
