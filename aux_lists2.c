#include "main.h"

/**
 * varadd_node - adds a variable at the end
 * of a variable_t list.
 * @head: head of the linked list.
 * @lvar: length of the variable.
 * @val: value of the variable.
 * @lval: length of the value.
 * Return: address of the head.
 */
variable_t *varadd_node(variable_t **head, int lvar, char *val, int lval)
{
	variable_t *new, *temp;

	new = malloc(sizeof(variable_t));
	if (new == NULL)
		return (NULL);

	new->len1 = lvar;
	new->myvalue = val;
	new->len2 = lval;

	new->link = NULL;
	temp = *head;

	if (temp == NULL)
	{
		*head = new;
	}
	else
	{
		while (temp->link != NULL)
			temp = temp->link;
		temp->link = new;
	}

	return (*head);
}

/**
 * free_variables - frees a variable_t list
 * @head: head of the linked list.
 * Return: no return.
 */
void free_variables(variable_t **h)
{
	variable_t *nxt_ptr;

	if (h == NULL)
		return;

	while (*h)
	{
		nxt_ptr = (*h)->link;
		free(*h);
		*h = nxt_ptr;
	}

	*h = NULL;
}
