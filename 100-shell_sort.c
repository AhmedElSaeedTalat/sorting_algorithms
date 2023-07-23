#include <stdio.h>
#include "sort.h"
/**
  * shell_sort - shell sort an array
  * @array: array passed
  * @size: size passed
  */
void shell_sort(int *array, size_t size)
{
	size_t gap, j;
	int temp, i;

	if (array == NULL || !size || size < 2)
		return;
	gap = 1;
	while (gap < size / 3)
		gap = gap * 3 + 1;

	for (gap = gap; gap >= 1; gap = (gap - 1) / 3)
	{
		for (j = gap; j < size; j++)
		{
			temp = array[j];
			for (i = j - gap; array[i] > temp && i >= 0; i = i - gap)
				array[i + gap] = array[i];
			array[i + gap] = temp;
		}
		print_array(array, size);
	}
}
