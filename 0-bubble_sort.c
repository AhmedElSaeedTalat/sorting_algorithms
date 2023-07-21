#include <stdio.h>
#include "sort.h"
/**
  * bubble_sort - bubble sort algorithm
  *
  * @array: passed array
  * @size: len of array
  */
void bubble_sort(int *array, size_t size)
{
	unsigned int i, j, temp, swapped;

	if (size < 2)
	{
		print_array(array, size);
		return;
	}
	for (i = 0; i < size - 1; i++)
	{
		swapped = 0;
		for (j = 0; j < size - 1 - i; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				swapped = 1;
			}
			if (swapped == 1)
				print_array(array, size);
		}
		if (swapped == 0)
			break;
	}
}
