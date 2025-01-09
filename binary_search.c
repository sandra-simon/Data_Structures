/*Implement Binary Search.*/


#include<stdio.h>
int main()
{
	int i, key, mid, beg, end, list[20], count;
	printf("How many elements: ");
	scanf("%d", &count);
	printf("Enter the elements: ");
 	for (i = 0; i < count; i++)
	{
		scanf("%d", &list[i]);
	}
 	printf("Enter the element to be searched: ");
 	scanf("%d", &key);
 	beg = 0;
 	end = count - 1;
 	while (beg <= end)
	{
		mid = (beg + end) / 2;
		if (list[mid] == key)
		{
			printf("The element %d is found at position %d.\n", key, mid + 1);
			break;
		}
		if (list[mid] < key)
		{
			beg = mid + 1;
		}
		else
		{
			end = mid - 1;
		}
	}
	if (beg > end)
	{
		printf("The element %d is not found.\n", key);
	}
	return 0;
}
