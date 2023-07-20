#include "sort.h"

/**
 * selection_sort - function implements selection sort algorithm
 * @array: array to sort
 * @size: size of the array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min_index = 0;
	int temp, min;

	if (array == NULL)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min = array[i];
		for (j = i; j < size - 1; j++)
		{
			if (array[j + 1] < min)
			{
				min = array[j + 1];
				min_index = j + 1;
			}
		}
		if (min != array[i])
		{
			temp = array[i];
			array[i] = array[min_index];
			array[min_index] = temp;
			print_array(array, size);
		}
	}
}
