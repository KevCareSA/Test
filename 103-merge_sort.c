#include "sort.h"

void merge(int *arr, int *copy, int start, int middle, int end);

void topdown_merge_sort(int *arr, int *copy, int start, int end)
{
	int middle;

	if((end - start) <= 1)
		return;

	middle = (end - start) / 2;

	topdown_merge_sort(arr, copy, start, middle);
	topdown_merge_sort(arr, copy, middle, end);
    merge(arr, copy, start, middle, end);
}

void merge_sort(int *array, size_t size)
{
	int *copy, i;

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
