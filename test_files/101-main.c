#include <stdio.h>
#include <stdlib.h>
#include "../sort.h"

/**
 * create_listint - Creates a doubly linked list from an array of integers
 *
 * @array: Array to convert to a doubly linked list
 * @size: Size of the array
 *
 * Return: Pointer to the first element of the created list. NULL on failure
 */
listint_t *create_listint(const int *array, size_t size)
{
    listint_t *list;
    listint_t *node;
    int *tmp;

    list = NULL;
    while (size--)
    {
        node = malloc(sizeof(*node));
        if (!node)
            return (NULL);
        tmp = (int *)&node->n;
        *tmp = array[size];
        node->next = list;
        node->prev = NULL;
        list = node;
        if (list->next)
            list->next->prev = list;
    }
    return (list);
}

void cocktail_sort(int *array, size_t size)
{
	int i, j, temp, sorted = 1, sze = (int)size;

	for(i = 0; i < sze - 1 && sorted; i++)
	{
		sorted = 0;
		for(j = i; j < sze - i - 1; j++)
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
		j--;
		for(; j > i; j--)
		{
			if (array[j] < array[j - 1])
			{
				temp = array[j];
				array[j] = array[j - 1];
				array[j - 1] = temp;
				sorted = 1;
				print_array(array, size);
			}
		}
	}
}

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    listint_t *list;
    int array[] = {71, 76, 86, 37, 45, 33, 3, 79, 29, 21, 57, 98, 61, 63, 67, 2, 13, 59, 80, 18, 40};
    size_t n = sizeof(array) / sizeof(array[0]);

	/*
    print_array(array, n);
    printf("\n");
    cocktail_sort(array, n);
    printf("\n");
    print_array(array, n);*/	

    list = create_listint(array, n);
    if (!list)
        return (1);
    print_list(list);
    printf("\n");
    cocktail_sort_list(&list);
    printf("\n");
    print_list(list);
    return (0);
}
