#include "sort.h"

/**
 * merge - merges aux into arr
 * @arr: array to sort
 * @aux: auxillary array, deals with temporary sorting and storing of elements
 * @start: starting index of array/sub-array
 * @middle: where the left sub-array ends and the right sub-array begins
 * @end: the size of the array/sub-array
 */
void merge(int *aux, int *arr, int start, int middle, int end)
{
	int k, i = start, j = middle;

	printf("Merging...\n");
	printf("[left]: ");
	for (k = start; k < middle; k++)
	{
		if (k + 1 == middle)
			printf("%d\n", arr[k]);
		else
			printf("%d ", arr[k]);
	}
	printf("[right]: ");
	for (k = middle; k < end; k++)
	{
		if (k + 1 == end)
			printf("%d\n", arr[k]);
		else
			printf("%d ", arr[k]);
	}
	for (k = start; k < end; k++)
	{
		if (i < middle && (j >= end || arr[i] <= arr[j]))
		{
			aux[k] = arr[i];
			i = i + 1;
		}
		else
		{
			aux[k] = arr[j];
			j = j + 1;
		}
	}
	printf("[Done]: ");
	for (k = start; k < end; k++)
	{
		if (k + 1 == end)
			printf("%d\n", aux[k]);
		else
			printf("%d ", aux[k]);
	}
}

/**
 * topdown_merge_sort - recursive sort method that uses 'divide and conquer'
 * @arr: array to sort
 * @aux: auxillary array, deals with temporary sorting and storing of elements
 * @start: starting index of array/sub-array
 * @end: the size of the array/sub-array
 */
void topdown_merge_sort(int *aux, int *arr, int start, int end)
{
	int middle;

	if ((end - start) <= 1)
		return;

	middle = (end + start) / 2;

	topdown_merge_sort(arr, aux, start, middle);
	topdown_merge_sort(arr, aux, middle, end);

	merge(aux, arr, start, middle, end);
}

/**
 * merge_sort - copies array into an auxillary array and initiates the
 *              topdown_merge_sort method
 * @array: array to sort
 * @size: the size of the array/sub-array
 */
void merge_sort(int *array, size_t size)
{
	int *copy;
	size_t i;

	if (array == NULL || size < 2)
		return;

	copy = malloc(sizeof(int) * size);
	if (copy == NULL)
		return;

	for (i = 0; i < size; i++)
		copy[i] = array[i];

	topdown_merge_sort(array, copy, 0, (int)size);

	free(copy);
}
