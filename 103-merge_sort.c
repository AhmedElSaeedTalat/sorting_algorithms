#include <stdio.h>
#include "sort.h"
#include <stdlib.h>
void merge(int *arr, int l, int m, int r)
{
	int i, j, k, *left_arr, *right_arr;
	int left_len = m - l + 1, right_len = r - m;
	left_arr = malloc(sizeof(int) * left_len);
	if (left_arr == NULL)
		return;
	right_arr = malloc(sizeof(int) * right_len);
	if (right_arr == NULL)
	{
		free(left_arr);
		return;
	}
	for (i = 0; i < left_len; i++)
		left_arr[i] = arr[l + i];
	for (i = 0; i < right_len; i++)
		right_arr[i] = arr[m + 1 + i];
	for (i = 0, j = 0, k = l; k <= r; k++)
	{
		if(i < left_len && (j >= right_len || left_arr[i] <= right_arr[j]))
		{
			arr[k] = left_arr[i];
			i++;
		} else
		{
			arr[k] = right_arr[j];
			j++;
		}
	}
	free(left_arr), free(right_arr);
}
void m_sort(int *array, int l, int r, size_t size)
{
	int m;

	if (l < r)
	{
		m = l + (r - l) / 2;
		m_sort(array, l, m, size);
		m_sort(array, m + 1, r, size);
		merge(array, l, m, r);
	}
}
/**
  * merge_sort - sort merge algorith
  *
  * @array: array passed
  * @size: size of the array
  */
void merge_sort(int *array, size_t size)
{
	m_sort(array, 0, size - 1, size);	
}
