#include "sort.h"

/**
 * count_digits - counts the number of digits in a positive integer
 * @value: a positive integer
 * Return: the number of digits
 */
int count_digits(int value)
{
	int count;

	for (count = 1; value / 10 != 0; value /= 10)
		count++;

	return (count);
}

/**
 * max_digit_count - counts the maximum digit count of an integer in an array
 * @arr: array to sort
 * @size: size of an array
 * Return: the maximum digit count
 */
int max_digit_count(int *arr, size_t size)
{
	size_t i;
	int max, count;

	max = 1;
	for (i = 0; i < size; i++)
	{
		count = count_digits(arr[i]);
		max = count > max ? count : max;
	}
	return (max);
}

/**
 * p_value - calculates the value of a digit {value} at position {count}
 * @value: a positive integer
 * @count: position of value
 * Return: the positional value
 */
int p_value(int value, int count)
{
	int i, modulus = 10, divisor = 1, pval;

	for (i = 0; i < count; i++)
		divisor *= 10;

	pval = (value / divisor) % modulus;
	return (pval);
}

/**
 * radix_count_arr - intialises count array, fills it, and uses it's values
 *                   to sort the original array.
 * @arr: original array
 * @copy: copy of the original array
 * @ca: counting array
 * @size: size of the array
 * @pval: position value of given integer element
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
	/*loop in reverse to preserve the order of the  radix sorting algorithm*/
	for (i = size - 1; (int)i >= 0; i--)
	{
		arr[ca[p_value(copy[i], pval)] - 1] = copy[i];
		ca[p_value(copy[i], pval)] -= 1;
	}
}

/**
 * radix_sort - implements counting sort individual digits of an integer
 * @array: original array
 * @size: size of the array
 */
void radix_sort(int *array, size_t size)
{
	int i, count, *copy = NULL, carray[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

	if (array == NULL || size < 2)
		return;

	copy = malloc(sizeof(int) * size);
	if (copy == NULL)
		return;

	count = max_digit_count(array, size);

	for (i = 0; i < count; i++)
	{
		radix_count_arr(array, copy, carray, size, i);
		print_array(array, size);
	}
	free(copy);
}
