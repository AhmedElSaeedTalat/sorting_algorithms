#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
/**
  * find_max - find max value
  *
  * @array: array passed
  * @size: size of array passed
  *
  * Return: max value
  */
int find_max(int *array, size_t size)
{
	int max;
	size_t i;

	max = array[0];
	for (i = 0; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}
/**
  * array_init - initialize array
  *
  * @array: array passed
  * @size: size of array passed
  */
void array_init(int *array, int size)
{
	int i;

	for (i = 0; i < size; i++)
		array[i] = 0;
}
/**
  * counting_sort - counting_sort
  *
  * @array: array passed
  * @size: size of array passed
  */
void counting_sort(int *array, size_t size)
{
	size_t i, k;
	int *index_array, *sorted_array, index, y;

	if (array == NULL || !size || size < 2)
		return;

	k = find_max(array, size);
	index_array = malloc(sizeof(int) * (k + 1));
	if (index_array == NULL)
		return;
	array_init(index_array, k + 1);
	for (i = 0; i < size; i++)
		index_array[array[i]]++;
	for (i = 1; i <= k; i++)
		index_array[i] = index_array[i] + index_array[i - 1];
	print_array(index_array, k + 1);
	sorted_array = malloc(sizeof(int) * size);
	if (sorted_array == NULL)
	{
		free(index_array);
		return;
	}
	for (y = size - 1; y >= 0; y--)
	{
		index = index_array[array[y]];
		index--;
		sorted_array[index] = array[y];
	}
	for (i = 0; i < size; i++)
		array[i] = sorted_array[i];
	free(index_array), free(sorted_array);
}
