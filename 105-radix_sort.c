#include <stdio.h>
#include "sort.h"
#include <stdlib.h>
char *convert_int(int num, int num_digits)
{
	char *str;
	int i, j, elem, var = 1, count = 0;
	str = malloc(sizeof(char) * (num_digits + 1));
	elem = num;
	while(elem > 0)
	{
		elem = elem / 10;
		count++;
	}
	j = num_digits;
	while (j > 1)
	{
		var *= 10;
		j--;
	}
	for (i = 0, var = var; i < num_digits; i++, var /= 10)
	{
		elem = num;
		if (count < num_digits && i == 0)
		{
			str[i] = '0';
			continue;
		}
		elem = elem / var;
		elem = elem % 10;
		str[i] = elem + '0';
	}
	str[i] = '\0';
	return (str);
}
void sort_array(char ***temp_arr, int *arr)
{
	int n, m, i, num, counter = 0, res = 0;

	for (n = 0; n <= 9; n++)
	{
		if (temp_arr[n] == NULL)
			continue;
		for (m = 0; temp_arr[n][m] != NULL; m++)
		{
			res = 0;
			for (i = 0; temp_arr[n][m][i] != '\0'; i++)
			{
				num = temp_arr[n][m][i] - '0';
				res = res * 10 + num;
			}
			arr[counter] = res;
			counter++;
		}
	}
	print_array(arr, counter);
}
char **caloc_array(char **arr, char *data, int c)
{
	char **new_arr;
	int i;

	new_arr = malloc(sizeof(char *) * (c + 2));
	for (i = 0; i < c; i++)
		new_arr[i] = arr[i];
	new_arr[i] = data;
	i++;
	new_arr[i] = NULL;

	return (new_arr);
}
void convert_toString(int *array, size_t size, int num_digits)
{
	size_t i;
	char ***temp_arr; 
	char *converted_str;
	int j, k, index,c = 0;
	int n, m;
	
	char **arr_str = malloc(sizeof(char *) * (size + 1));
	if (arr_str == NULL)
		return;
	for (i = 0; i < size; i++)
	{
		converted_str = convert_int(array[i], num_digits);
		arr_str[i] = converted_str;
	}
	arr_str[i] = NULL;
	j = num_digits - 1;
	temp_arr = malloc(sizeof(char *) * 10);
	for (n = 0; n < 10; n++)
		temp_arr[n] = NULL;
	for (k = 0; k < num_digits; k++)
	{
		for (i = 0; i < size; i++)
		{
			
			index = arr_str[i][j] - '0';
			if (temp_arr[index] == NULL)
			{
				temp_arr[index] = malloc(sizeof(char *) * (2));
				temp_arr[index][0] = arr_str[i];
				temp_arr[index][1] = NULL;
			} else
			{
				while (temp_arr[index][c])
					c++;
				temp_arr[index] = caloc_array(temp_arr[index], arr_str[i], c);
			}	
		}
		sort_array(temp_arr, array);
		j--;
	}

}
/**
  * main - Entry point
  *
  * Return: Always 0 (Success)
  */
void radix_sort(int *array, size_t size)
{
	size_t i;
	int elem, count = 0, num_digits = 1;

	for (i = 0; i < size; i++)
	{
		elem = array[i];
		count = 0;
		while(elem > 0)
		{
			elem = elem / 10;
			count++;
		}

		if (num_digits < count)
			num_digits = count;
	}

	convert_toString(array, size, num_digits);
}
