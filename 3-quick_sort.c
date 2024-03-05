#include "sort.h"
#include <stdio.h>

/**
 * list_partition - creates partition using Lomuto scheme
 * @array: array to sort
 * @min: lower partion index
 * @max: upper partition index
 * @size: size of the array
 *
 * Return: partition index
 */
size_t list_partition(int *array, ssize_t min, ssize_t max, size_t size)
{
	ssize_t i, j;
	int swap, pivot;

	pivot = array[max];
	i = min - 1;
	for (j = min; j < max; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				swap = array[i];
				array[i] = array[j];
				array[j] = swap;
				print_array(array, size);
			}
		}
	}
	if (array[max] < array[i + 1])
	{
		swap = array[i + 1];
		array[i + 1] = array[max];
		array[max] = swap;
		print_array(array, size);
	}
	return (i + 1);
}

/**
 * part_quicksort - sorts partition
 * @array: array to sort
 * @min: lowest index of the partition to sort
 * @max: highest index of the partition to sort
 * @size: size of the array
 *
 * Return: void
 */
void part_quicksort(int *array, ssize_t min, ssize_t max, size_t size)
{
	ssize_t pivot;

	if (min < max)
	{
		pivot = list_partition(array, min, max, size);
		part_quicksort(array, min, pivot - 1, size);
		part_quicksort(array, pivot + 1, max, size);

	}
}

/**
 * quick_sort - sorts an array of integers in ascending order
 * @array: The array to sort
 * @size: Array size
 *
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	part_quicksort(array, 0, size - 1, size);
}
