#include "sort.h"

/**
 * quick_sort - function implements quick sort algorithm
 * @array: array to sort
 * @size: size of the array
 */
void shell_sort(int *array, size_t size)
{
	int gap = 1;
	int i = 0, j, temp, k;
	int sze = (int)size;

	while (gap * 3 + 1 < sze)
		gap = gap * 3 + 1;

	for (; gap >= 1; gap /= 3)
	{
		for (i = 0, j = i + gap; j < sze; i++, j++)
		{
			if (array[j] < array[i])
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				k = i;
				while (k - gap >= 0 && array[k] < array[k - gap])
				{
					temp = array[k];
					array[k] = array[k - gap];
					array[k - gap] = temp;
					k = k - gap;
				}
			}
		}
		print_array(array, size);
	}

}
