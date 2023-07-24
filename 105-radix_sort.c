#include "sort.h"

int count_digits(int value)
{
	int count;

	for (count = 1; value / 10 != 0; value /= 10)
		count++;

	return count;
}

int max_digit_count(int *arr, size_t size)
{
	size_t i;
	int max, count;

	max = 1;
	for(i = 0; i < size; i++)
	{
		count = count_digits(arr[i]);
		max = count > max ? count : max;
	}
	return max;
}

int p_value(int value, int count)
{
	int i, modulus = 10, divisor = 1, pval;

	for(i = 0; i < count; i++)
		divisor *= 10;

	pval = (value / divisor) % modulus;
	return (pval);
}

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
void radix_count_arr(int *arr, int *copy, int *ca, size_t size, int pval)
{
	size_t i;

	/*initializing counting array*/
	for (i = 0; i < 10; i++)
		ca[i] = 0;
	/*copying contents of original array to the copy*/
	for (i = 0; i < size; i++)
		copy[i] = arr[i];
	/*counting value occurences in counting array*/
	for (i = 0; i < size; i++)
		ca[p_value(arr[i], pval)] += 1;
	/*cumulative count on the counting array*/
	for (i = 1; i < 10; i++)
		ca[i] += ca[i - 1];

	for (i = 0; i < size; i++)
	{
		arr[ca[p_value(copy[i], pval)] - 1] = copy[i];
		ca[p_value(copy[i], pval)] -= 1;
	}
}

void radix_sort(int *array, size_t size)
{
	int i, count, *copy = NULL, carray[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

	if (array == NULL || size < 2)
		return;

	copy = malloc(sizeof(int) * size);
	if (copy == NULL)
		return;

	count = max_digit_count(array, size);

	for(i = 0; i < count; i++)
	{
		radix_count_arr(array, copy, carray, size, i);
		print_array(array, size);
	}
	free(copy);
}
