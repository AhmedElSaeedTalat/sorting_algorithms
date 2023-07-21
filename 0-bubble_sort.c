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
	size_t i, j, temp, swapped;

	if (array == NULL || size < 2)
		return;
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
	}
}