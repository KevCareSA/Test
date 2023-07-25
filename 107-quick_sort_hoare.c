#include "sort.h"

int hoare_partition(int *arr, int start, int end, size_t size)
{
	int i = start - 1, j = end, temp;
	int pivot = arr[end];

	while (1)
	{
		do {
			i++;
		} while (arr[i] < pivot);
		do {
			j--;
		} while (arr[j] > pivot);

		if (i >= j)
			break;

		temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
		print_array(arr, size);
	}
	temp = arr[end];
	arr[end] = arr[i];
	arr[i] = temp;
	print_array(arr, size);
	return (i);
}

void quick_sort_hoare_init(int *arr, int start, int end, size_t size)
{
	int pivot_index;

	if (start < end)
	{
		pivot_index = hoare_partition(arr, start, end, size);
		quick_sort_hoare_init(arr, start, pivot_index - 1, size);
		quick_sort_hoare_init(arr, pivot_index + 1, end, size);
	}
}

void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_hoare_init(array, 0, (int)size - 1, size);
}
