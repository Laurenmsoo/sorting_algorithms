#include "sort.h"

/**
 * bubble_sort - sorts array in ascending order
 * @array: The array to be sorted
 * @size: Array size
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, n, temp;
	int swap;

	if (array == NULL || size < 2)
		return;

	n = size;
	while (n > 0)
	{
		temp = 0;
		for (i = 0; i < n - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				swap = array[i];
				array[i] = array[i + 1];
				array[i + 1] = swap;
				temp = i + 1;
				print_array(array, size);
			}
		}
		n = temp;
	}
}

