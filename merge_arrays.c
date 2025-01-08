/*given two arrays sorted in ascending order. Write a C Program to merge the elements of the two arrays and to form a single array sorted in ascending order.*/

#include<stdio.h>
int main()
{
	int a1[10], a2[10], a3[20];
	int l1, l2, l3;
	int i, j1 = 0, j2 = 0, j, t;

	printf("No of elements in the first array : ");
	scanf(" %d", &l1);
	printf("Enter the elements : ");
	for (i = 0; i < l1; i++)
	{
		scanf("%d", &a1[i]);
	}

	printf("No of elements in the second array : ");
	scanf(" %d", &l2);
	printf("Enter the elements : ");
	for (i = 0; i < l2; i++)
	{
		scanf("%d", &a2[i]);
	}

	l3 = l1 + l2;
	for (i = 0; i < l3; i++)
	{
		if (j1 < l1 && (j2 >= l2 || a1[j1] <= a2[j2]))
		{
			a3[i] = a1[j1++];
		}
		else
		{
			a3[i] = a2[j2++];
		}
	}
	printf("\nSorted array : ");
	for (i = 0; i < l3; i++)
	{
		printf("%d ", a3[i]);
	}
	printf("\n");
	return 0;
}