#include <stdio.h>
#include "sort.h"
/**
  * selection_sort - sort by selection
  *
  * @array: array passed
  * @size: size of array
  */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min;
	int temp;

	if (array == NULL)
		return;
	for (i = 0; i < size; i++)
	{
		min = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[i] > array[j])
			{
				if (array[j] < array[min])
					min = j;
			}
		}

		if (min != i)
		{
			temp = array[i];
			array[i] = array[min];
			array[min] = temp;
			print_array(array, size);
		}
	}
}
