#include <stdio.h>
#include "sort.h"
#include <stdlib.h>
/**
  * get_digit - get digit starting from lsd
  *
  * @num: number in an array
  * @num_iteration: number of iteration of main loop
  *
  * Return: the digit needed
  */
int get_digit(int num, int num_iteration)
{
	int i, num_count, count = 0, var = 1;

	/* count digits in the number */
	num_count = num, count = 0;
	while (num_count > 0)
		num_count = num_count / 10, count++;
	if (num_iteration + 1 > count)
		return (0);
	/* calculate var */
	for (i = 0; i < num_iteration; i++)
	{
		var = var * 10;
	}
		num = num / var;
		num = num % 10;
	return (num);
}
/**
  * _caloc - create memory for a new bucket and copy data
  * from old bucket
  *
  * @arr: old bucket
  * @value: new value from array to be passed to the bucket
  * @count: length of old bucket
  *
  * Return: new bucket
  */
int *_caloc(int *arr, int value, int count)
{
	int i, *new_arr;

	new_arr = malloc(sizeof(int) * (count + 2));
	for (i = 0; arr[i] != -1; i++)
	{
		new_arr[i] = arr[i];
	}
	new_arr[i] = value;
	i++;
	new_arr[i] = -1;
	free(arr);
	return (new_arr);
}
/**
  * free_buckets - frees the buckets
  *
  * @buckets: buckets
  */
void free_buckets(int **buckets)
{
	int b;

	for (b = 0; b < 10; b++)
	{
		if (buckets[b] == NULL)
			continue;
		free(buckets[b]);
		buckets[b] = NULL;
	}

}
/**
  * get_numDigit - calculate maximum number of digits
  * in each integer
  *
  * @array: array passed
  * @size: size passed
  *
  * Return: max number of digits
  */
int get_numDigit(int *array, size_t size)
{
	size_t i;
	int num, count = 0, num_digits = 1;

	for (i = 0; i < size; i++)
	{
		num = array[i], count = 0;
		while (num > 0)
			num = num / 10, count++;
		if (count > num_digits)
			num_digits = count;
	}
	return (num_digits);
}
/**
  * radix_sort - sort using radix algorith
  *
  * @array: array passed
  * @size: size passed
  */
void radix_sort(int *array, size_t size)
{
	size_t i;
	int **buckets, index, k, b, x, num_digits = 1, count_bucket = 0, counter = 0;

	if (array == NULL || !size || size < 2)
		return;
	num_digits = get_numDigit(array, size), buckets = malloc(sizeof(int *) * 10);
	if (buckets == NULL)
		return;
	for (i = 0; i < 10; i++)
		buckets[i] = NULL;
	for (k = 0; k < num_digits; k++)
	{
		for (i = 0; i < size; i++)
		{
			index = get_digit(array[i], k);
			if (buckets[index] == NULL)
			{
				buckets[index] = malloc(sizeof(int) * 2);
				buckets[index][0] = array[i], buckets[index][1] = -1;
			} else
			{
				while (buckets[index][count_bucket] != -1)
					count_bucket++;
				buckets[index] = _caloc(buckets[index], array[i],  count_bucket);
				count_bucket = 0;
			}
		}
		counter = 0;
		for (b = 0; b < 10; b++)
		{
			if (buckets[b] == NULL)
				continue;
			for (x = 0; buckets[b][x] != -1; x++)
				array[counter] = buckets[b][x], counter++;
		}
		print_array(array, size);
		free_buckets(buckets);
	}
	free(buckets);
}
