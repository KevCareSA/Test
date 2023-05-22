#include "main.h"

/**
 * check_env - checks if the typed variable is an env variable
 *
 * @h: head of linked list
 * @in: input string
 * @data: data structure
 * Return: no return
 */
void check_env(variable_t **h, char *in, globals_t *data)
{
	int row, chr, j, lval;
	char **_envr;

	_envr = data->my_env;
	for (row = 0; _envr[row]; row++)
	{
		for (j = 1, chr = 0; _envr[row][chr]; chr++)
		{
			if (_envr[row][chr] == '=')
			{
				lval = _strlen(_envr[row] + chr + 1);
				varadd_node(h, j, _envr[row] + chr + 1, lval);
				return;
			}

			if (in[j] == _envr[row][chr])
				j++;
			else
				break;
		}
	}

	for (j = 0; in[j]; j++)
	{
		if (in[j] == ' ' || in[j] == '\t' || in[j] == ';' || in[j] == '\n')
			break;
	}

	varadd_node(h, j, NULL, 0);
}

/**
 * check_vars - check if the typed variable is $$ or $?
 *
 * @h: head of the linked list
 * @in: input string
 * @st: last status of the Shell
 * @data: data structure
 * Return: no return
 */
int check_vars(variable_t **h, char *in, char *st, globals_t *data)
{
	int i, lst, lpd;

	lst = _strlen(st);
	lpd = _strlen(data->this_pid);

	for (i = 0; in[i]; i++)
	{
		if (in[i] == '$')
		{
			if (in[i + 1] == '?')
				varadd_node(h, 2, st, lst), i++;
			else if (in[i + 1] == '$')
				varadd_node(h, 2, data->this_pid, lpd), i++;
			else if (in[i + 1] == '\n')
				varadd_node(h, 0, NULL, 0);
			else if (in[i + 1] == '\0')
				varadd_node(h, 0, NULL, 0);
			else if (in[i + 1] == ' ')
				varadd_node(h, 0, NULL, 0);
			else if (in[i + 1] == '\t')
				varadd_node(h, 0, NULL, 0);
			else if (in[i + 1] == ';')
				varadd_node(h, 0, NULL, 0);
			else
				check_env(h, in + i, data);
		}
	}

	return (i);
}

/**
 * replaced_input - replaces string into variables
 *
 * @head: head of the linked list
 * @input: input string
 * @new_input: new input string (replaced)
 * @nlen: new length
 * Return: replaced string
 */
char *replaced_input(variable_t **head, char *input, char *new_input, int nlen)
{
	variable_t *indx;
	int i, j, k;

	indx = *head;
	for (j = i = 0; i < nlen; i++)
	{
		if (input[j] == '$')
		{
			if (!(indx->len1) && !(indx->len2))
			{
				new_input[i] = input[j];
				j++;
			}
			else if (indx->len1 && !(indx->len2))
			{
				for (k = 0; k < indx->len1; k++)
					j++;
				i--;
			}
			else
			{
				for (k = 0; k < indx->len2; k++)
				{
					new_input[i] = indx->myvalue[k];
					i++;
				}
				j += (indx->len1);
				i--;
			}
			indx = indx->link;
		}
		else
		{
			new_input[i] = input[j];
			j++;
		}
	}

	return (new_input);
}

/**
 * rep_var - calls functions to replace string into vars
 *
 * @input: input string
 * @globvar: data structure
 * Return: replaced string
 */
char *rep_var(char *input, globals_t *globvar)
{
	variable_t *head, *indx;
	char *status, *new_input;
	int olen, nlen;

	status = aux_itoa(globvar->exitstat);
	head = NULL;

	olen = check_vars(&head, input, status, globvar);

	if (head == NULL)
	{
		free(status);
		return (input);
	}

	indx = head;
	nlen = 0;

	while (indx != NULL)
	{
		nlen += (indx->len2 - indx->len1);
		indx = indx->link;
	}

	nlen += olen;

	new_input = malloc(sizeof(char) * (nlen + 1));
	new_input[nlen] = '\0';

	new_input = replaced_input(&head, input, new_input, nlen);

	free(input);
	free(status);
	free_variables(&head);

	return (new_input);
}
