#include "sort.h"

/**
 * lamuto_partition - function implements lamuto algorithm
 * @array: array to sort
 * @start: start of array/sub-array
 * @end: end of array/sub-array
 * @size: size of the array
 */
size_t lamuto_partition(int *array, size_t start, size_t end, size_t size)
{
	size_t j, i = start;
	int  temp, pivot = array[end];

	for (j = start; j < end; j++)
	{
		if (array[j] <= pivot)
		{
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			print_array(array, size);
			i++;
		}
	}

	temp = array[i];
	array[i] = array[end];
	array[end] = temp;
	print_array(array, size);

	return (i);
}

/**
 * quick_sort_init - function implements initiates quick sort recursively
 * @array: array to sort
 * @start: start of array/sub-array
 * @end: end of array/sub-array
 * @size: size of the array
 */
void quick_sort_init(int *array, size_t start, size_t end, size_t size)
{
	size_t pivot_index;

	if (start < end)
	{
		pivot_index = lamuto_partition(array, start, end, size);
		quick_sort_init(array, start, pivot_index - 1, size);
		quick_sort_init(array, pivot_index + 1, end, size);
	}
}

/**
 * quick_sort - function implements quick sort algorithm
 * @array: array to sort
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL)
		return;

	quick_sort_init(array, 0, size - 1, size);
}
