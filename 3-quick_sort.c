#include <stdio.h>
#include "sort.h"
/**
  * swap - swap two elements
  *
  * @i: element of an array
  * @j: second element of an array
  */
void swap(int *i, int *j)
{
	int temp;

	temp = *i;
	*i = *j;
	*j = temp;
}
/**
  * partition - sort array around the pivot
  *
  * @array: element of an array
  * @low: first index
  * @high:last index
  * @size: size of the array
  *
  * Return: the new pivot
  */
int partition(int *array, int low, int high, size_t size)
{
	int pivot, i, j;

	pivot = array[high];

	for (i = low, j = low; j <= high; j++)
	{
		if (array[j] <= pivot && array[j] < array[i])
		{
			swap(&array[j], &array[i]);
			print_array(array, size);
			i++;
		}
		if (array[j] <= pivot)
			i++;

	}
	return (i - 1);
}
/**
  * qsort - sort array around the pivot
  *
  * @array: element of an array
  * @low: first index
  * @high:last index
  * @size: size of the array
  */

void qsort(int *array, int low, int high, size_t size)
{
	int pivot;

	if (low < high)
	{
		pivot = partition(array, low, high, size);
		qsort(array, low, pivot - 1, size);
		qsort(array, pivot + 1, high, size);
	}
}
/**
  * quick_sort - quick sort an array
  *
  * @array: array passed
  * @size: size of the array
  */
void quick_sort(int *array, size_t size)
{
	if (array == NULL)
		return;
	qsort(array, 0, size - 1, size);
}
