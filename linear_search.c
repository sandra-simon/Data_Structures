/*Implement Linear Search.*/


#include<stdio.h>
void main()
{
	int list[20], count, key, i;
	printf("Enter the no of elements: ");
	scanf("%d", &count);
	printf("Enter the elements: ");
	for (i = 0; i < count; i++)
	{
		scanf("%d", &list[i]);
	}
	printf("Enter the element to be searched: ");
	scanf("%d", &key);
	for (i = 0; i < count; i++)
	{
		if (list[i] == key)
		{
			break;
		}
	}
	if (i == count)
	{
		printf("The element %d not in the list.\n", key);
	}
	else
	{
		printf("The element %d found at position %d in the list.\n", key, i + 1);
	}
}
