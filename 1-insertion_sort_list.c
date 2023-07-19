#include "sort.h"

/**
 * insertion_sort_list - function implements insertion sort algorithm
 * @list: pointer to the adress of the head node
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *ptr, *back= NULL;

	if (list == NULL || *list == NULL)
		return;

	ptr = *list;

	while (ptr != NULL)
	{   
		back = ptr;
		printf("outside swap %d\n", back->n);
		while (back->prev != NULL && back->n < back->prev->n)
		{
			if (back->prev != NULL)
				back->prev->next = back->next;
			if (back->next != NULL)
				back->next->prev = back->prev;
			back->next = back->prev;
			back->prev = back->prev->prev;
			back->next->prev = back;

			back = back->prev;
			*list = back;
			printf("inside swap %d\n", back->n);
		}
		ptr = ptr->next;
	}

}
