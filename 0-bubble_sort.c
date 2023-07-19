#include "sort.h"

/**
 * bubble_sort - function implements bubble sort algorithm
 * @array: array to sort
 * @size: size of the array
 */

void bubble_sort(int *array, size_t size)
{
    size_t i, j;
    int temp, sorted = 1;

    for (i = 0; i < size - 1 && sorted; i++)
    {
        for (j = 0; j < size - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
                sorted = 1;
                print_array(array, size);
                
            }
        }
    }
}
