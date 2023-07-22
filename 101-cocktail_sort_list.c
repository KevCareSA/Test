#include "sort.h"

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
	if(ahead->prev == NULL)
		*list = ahead;

}

/**
 * cocktail_sort_list - function implements cocktail sort algorithm
 * @list: pointer to the adress of the head node
 */

void cocktail_sort_list(listint_t **list)
{
	listint_t *i, *j = NULL;
	int count = 0, sorted = 1;
	if (list == NULL || *list == NULL)
		return;
	i = *list;

	while(i != NULL && sorted)
	{
		sorted = 0;
		j = *list;
		while(j->next != NULL)
		{
			if (j->n > j->next->n)
			{
				if (j == i)
					i = j->next;
				cocktail_swap_forward(list, j);
				print_list(*list);
				sorted = 1;
				continue;
			}
			j = j->next;
		}
		while(j != i)
		{

		}
		i = i->next;
		count++;
	}
	printf("\n%d\n\n", count);
}
