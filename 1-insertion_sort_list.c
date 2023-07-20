#include "sort.h"

/**
 * insertion_sort_list - function implements insertion sort algorithm
 * @list: pointer to the adress of the head node
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *i, *j = NULL, *ahead = NULL, *behind = NULL;

	if (list == NULL || *list == NULL)
		return;

	i = (*list)->next;

	while (i != NULL)
	{
		j = i;
		while (j->prev != NULL && j->prev->n > j->n)
		{
			ahead = j->next;
			behind = j->prev;

			j->next = behind;
			j->prev = behind->prev;
			if (behind->prev != NULL)
				behind->prev->next = j;
			behind->prev = j;
			behind->next = ahead;
			if (ahead != NULL)
				ahead->prev = behind;
			if (j->prev == NULL)
				*list = j;
			print_list(*list);
		}
		i = i->next;
	}

}
