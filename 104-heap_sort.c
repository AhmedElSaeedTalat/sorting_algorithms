#include <stdio.h>
#include "sort.h"
void swap(int *a, int *b)
{
	int temp = *a;

	*a = *b;
	*b = temp;
}
/**
  * main - Entry point
  *
  * Return: Always 0 (Success)
  */
void heap_sort(int *array, size_t size)
{
	int i, j, parent, child, child2;

	if (array == NULL || !size || size < 2)
		return;
	for (i = 0; i <= (int)size - 1; i++)
	{
		parent = i;
		if ((i * 2) <= (int) size - 1)
			child = i * 2;
		if (((i * 2) + 1) <= (int) size - 1)
			child2 = (i * 2) + 1;
		if 
	}
}
		
