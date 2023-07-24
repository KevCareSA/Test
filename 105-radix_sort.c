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

	max = count_digits(arr[0]);
	for(i = 1; i < size; i++)
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

void radix_sort(int *array, size_t size)
{
	int count, *copy = NULL;

	count = max_digit_count(array, size);
}
