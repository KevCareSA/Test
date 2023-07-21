#include "sort.h"

/**
 * lomuto_partition - function implements lomuto algorithm
 * @array: array to sort
 * @start: start of array/sub-array
 * @end: end of array/sub-array
 * @size: size of the array
 * Return: the index of the new pivot
 */
int lomuto_partition(int *array, int start, int end, size_t size)
{
	int temp;
	int j, i = start;
	int pivot = array[end];

	for (j = start; j < end; j++)
	{
		if (array[j] <= pivot)
		{
			if (i != j)
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
			i++;
		}
	}
	if (i != end)
	{
		temp = array[i];
		array[i] = array[end];
		array[end] = temp;
		print_array(array, size);
	}
	return (i);
}

/**
 * quick_sort_init - function implements initiates quick sort recursively
 * @array: array to sort
 * @start: start of array/sub-array
 * @end: end of array/sub-array
 * @size: size of the array
 */
void quick_sort_init(int *array, int start, int end, size_t size)
{
	int pivot_index;

	if (start < end)
	{
		pivot_index = lomuto_partition(array, start, end, size);
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
	if (array == NULL || size < 2)
		return;

	quick_sort_init(array, 0, (int)size - 1, size);
}
