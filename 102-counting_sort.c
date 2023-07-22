#include "sort.h"

/**
 * count_arr - finds the maximum integer and initializes counting array
               of size (k + 1) with 0 for each element, where k is the
               maximum integer of {array}
 * @array: array to sort
 * @size: size of the array
 * @max: maximum integer in {array}
 * @copy: copy of {array}
 * Return: returns pointer to counting array
 */
int *count_arr(int *array, size_t size, size_t *max, int **copy)
{
	size_t i;
	int *max_array;

	*max = array[0];

	*copy = malloc(sizeof(int) * size);
	if (*copy == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
		(*copy)[i] = array[i];

	for (i = 1; i < size; i++)
		*max = (size_t)array[i] > *max ? (size_t)array[i] : *max;

	max_array = malloc(sizeof(int) * ((*max) + 1));

	if (max_array == NULL)
	{
		free(copy);
		return (NULL);
	}

	for (i = 0; i <= *max; i++)
		max_array[i] = 0;

	return (max_array);
}

/**
 * counting_sort - function implements the counting sort algorithm
 * @array: array to sort
 * @size: size of the array
 */
void counting_sort(int *array, size_t size)
{
	int *ca, *copy;
	size_t i, max;

	if (array == NULL)
		return;
	/*initialize counting array*/
	ca = count_arr(array, size, &max, &copy);
	if (ca == NULL)
		return;

	for (i = 0; i < size; i++)
		ca[array[i]] += 1;

	for (i = 1; i <= max; i++)
		ca[i] += ca[i - 1];

	print_array(ca, max + 1);

	for (i = 0; i < size; i++)
	{
		array[ca[copy[i]] - 1] = copy[i];
		ca[copy[i]] -= 1;
	}

	free(copy);
	free(ca);

}
