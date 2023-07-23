#include <stdio.h>
#include "sort.h"
/**
  * shell_sort - shell sort an array
  * @array: array passed
  * @size: size passed
  */
void shell_sort(int *array, size_t size)
{
	int gap, j, i, temp;
	int len = size;

	gap = 1;
	while (gap < len / 3)
		gap = gap * 3 + 1;

	for (gap = gap; gap >= 1; gap = (gap - 1) / 3)
	{
		for (j = gap; j < len; j++)
		{
			temp = array[j];
			for (i = j - gap; array[i] > temp && i >= 0; i = i - gap)
				array[i + gap] = array[i];
			array[i + gap] = temp;
		}
		print_array(array, size);
	}
}
