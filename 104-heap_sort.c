#include "sort.h"

/**
 * iswap - function swaps 2 integers, x and y and the prints the array
 * @x: integer to be swapped
 * @y: integer to be swapped
 * @arr: pointer to original array
 * @size: size of original array
 */
void iswap(int *x, int *y, int *arr, size_t size)
{
	int temp = *x;

	*x = *y;
	*y = temp;
	print_array(arr, size);
}

/**
 * max_heapify - recursive function that ensures the max-heap datastructure
 *               maintains it's form by checking if the child nodes are
 *               greater than the parent nodes.
 * @arr: array to convert to max-heap
 * @h_size: size of heap
 * @index: index of the parent node in which we apply max_heapify
 * @size: size of original array to be sorted
 * Description: if the child node is found to be greater,
 *            1) we swap the values, then
 *            2) call max_heapify on the index in which we found the max value
 */
void max_heapify(int *arr, int index, size_t h_size, size_t size)
{
	int largest = index;
	int lchild = 2 * index + 1;
	int rchild = 2 * index + 2;
	int sze = (int)h_size;

	largest = lchild < sze && arr[lchild] > arr[largest] ? lchild : largest;
	largest = rchild < sze && arr[rchild] > arr[largest] ? rchild : largest;

	if (largest != index)
	{
		iswap(&(arr[largest]), &(arr[index]), arr, size);
		max_heapify(arr, largest, h_size, size);
	}
}

/**
 * build_max_heap - builds max-heap data structure by heapifying all the
 *                  parent nodes starting from the last one.
 * @arr: array to convert to max-heap
 * @h_size: size of heap
 * @size: size of original array to be sorted
 */
void build_max_heap(int *arr, size_t h_size, size_t size)
{
	int i, start = (int)size / 2 - 1;

	for (i = start; i >= 0; i--)
		max_heapify(arr, i, h_size, size);
}

/**
 * sift_down - recursive method that deletes the max element of a max_heap
 *             and swaps it with the last element, then heapifies the heap
 *             again, this is done until the heap size is 1
 * @heap: heap to sift down
 * @h_size: size of decreasing heap
 * @size: size of original array to be sorted
 */
void sift_down(int *heap, size_t h_size, size_t size)
{
	if (h_size > 1)
	{
		/*delete max value and shift*/
		iswap(&(heap[0]), &(heap[h_size - 1]), heap, size);
		max_heapify(heap, 0, h_size - 1, size);
		sift_down(heap, h_size - 1, size);
	}
}

/**
 * heap_sort - builds a max heap from the array and applies the sift down
 *             algorithm
 * @array: array to sort
 * @size: the size of the array
 */
void heap_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	build_max_heap(array, size, size);
	sift_down(array, size, size);
}
