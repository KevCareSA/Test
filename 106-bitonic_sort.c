#include "sort.h"

void bitonic_merge(int *arr, int low, int len, int dir, size_t size)
{
	int i, temp, k;

	if (len > 1)
	{
		k = len / 2;
		for (i = low; i < low + k; i++)
		{
			if (dir == (arr[i] > arr[i + k]))
			{
				temp = arr[i];
				arr[i] = arr[i + k];
				arr[i + k] = temp;
				print_array(arr, size);
			}
		}
		bitonic_merge(arr, low, k, dir, size);
		bitonic_merge(arr, low + k, k, dir, size);
	}
}
void bitonic_split(int *arr, int low, int len, int dir, size_t size)
{
	int k;

	if (len > 1)
	{
		k = len / 2;
		bitonic_split(arr, low, k, 1, size);
		bitonic_split(arr, low + k, k, 0, size);
		bitonic_merge(arr, low, len, dir, size);
	}
}

void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	bitonic_split(array, 0, (int)size, 1, size);
}
