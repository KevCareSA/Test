#include "sort.h"

/**
 * iswap - function swaps 2 integers, x and y
 * @x: integer to be swapped
 * @y: integer to be swapped
 */
void iswap(int *x, int *y, int *arr, size_t size)
{
    int temp = *x;

    *x = *y;
    *y = temp;
    print_array(arr, size);
}

void max_heapify(int *arr, int index, size_t size)
{
    int largest = index;
    int lchild = 2 * index + 1;
    int rchild = 2 * index + 2;
    int sze = (int)size;

    largest = lchild < sze && arr[lchild] > arr[largest] ? lchild : largest;
    largest = rchild < sze && arr[rchild] > arr[largest] ? rchild : largest;

    if (largest != index)
    {
        iswap(&(arr[largest]), &(arr[index]), arr, size);
        max_heapify(arr, largest, size);
    }
}
void build_max_heap(int *arr, size_t size)
{
    int i, start = (int)size/2 - 1;

    for (i = start; i >= 0; i--)
        max_heapify(arr, i, size);
}

void heap_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    build_max_heap(array, size);
}
