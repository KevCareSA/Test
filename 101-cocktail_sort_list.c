#include "sort.h"

/**
 * cocktail_swap_forward - swaps j and element ahead of j
 * @list: pointer to the adress of the head node
 * @j: element to swap
 */
void cocktail_swap_forward(listint_t **list, listint_t *j)
{
	listint_t *ahead = NULL, *behind = NULL;

	ahead = j->next;
	behind = j->prev;
	if (ahead->next != NULL)
		ahead->next->prev = j;
	j->next = ahead->next;
	j->prev = ahead;
	ahead->next = j;
	ahead->prev = behind;
	if (behind != NULL)
		behind->next = ahead;
	if (ahead->prev == NULL)
		*list = ahead;
}

/**
 * cocktail_swap_backward - swaps j and element behind j
 * @list: pointer to the adress of the head node
 * @j: element to swap
 */
void cocktail_swap_backward(listint_t **list, listint_t *j)
{
	listint_t *ahead = NULL, *behind = NULL;

	ahead = j->prev;
	behind = j->next;
	if (ahead->prev != NULL)
		ahead->prev->next = j;
	j->prev = ahead->prev;
	j->next = ahead;
	ahead->prev = j;
	ahead->next = behind;
	if (behind != NULL)
		behind->prev = ahead;
	if (j->prev == NULL)
		*list = j;
}

/**
 * cocktail_sort_list - function implements cocktail sort algorithm
 * @list: pointer to the adress of the head node
 */

void cocktail_sort_list(listint_t **list)
{
	listint_t *i, *j = NULL;
	int len = 0, sorted = 1, index;

	if (list == NULL || *list == NULL)
		return;

	for (i = *list; i != NULL; i = i->next)
		len++;

	for (index = 0; index < len && sorted; index++)
	{
		sorted = 0;
		for (j = *list; j->next != NULL;)
		{
			if (j->n > j->next->n)
			{
				cocktail_swap_forward(list, j);
				print_list(*list);
				sorted = 1;
				continue;
			}
			j = j->next;
		}
		for (; j->prev != NULL;)
		{
			if (j->n < j->prev->n)
			{
				cocktail_swap_backward(list, j);
				print_list(*list);
				sorted = 1;
				continue;
			}
			j = j->prev;
		}
	}
}
