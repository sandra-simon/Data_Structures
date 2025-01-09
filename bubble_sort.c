/*Implement bubble sort without using array (Use pointers instead)*/


#include<stdio.h>
void main()
{
	int i, j, t, list[20], count;
	printf("How many elements : ");
	scanf("%d", &count);
	printf("Enter the elements : ");
	for (i = 0; i < count; i++)
	{
		scanf("%d", list + i);
	}
	for (i = 0; i < count; i++)
	{
		for (j = 0; j < count - i - 1; j++)
		{
			if (*(list + j) > *(list + j + 1))
			{
				t = *(list + j);
				*(list + j) = *(list + j + 1);
				*(list + j + 1) = t;
			}
		}
	}
	printf("The sorted elements are : ");
	for (i = 0; i < count; i++)
	{
		printf(" %d ", *(list + i));
	}
	printf("\n");
}
