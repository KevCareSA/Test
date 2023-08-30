#include "binary_trees.h"

/**
 * node_depth - calculates depth of a node inside a tree
 * @tree: pointer to the node to calculate the depth of
 * Return: depth of a node
 */

size_t node_depth(const binary_tree_t *tree)
{
	size_t depth = 0;

	while (tree != NULL && tree->parent != NULL)
	{
		depth++;
		tree = tree->parent;
	}

	return (depth);
}


/**
 * binary_trees_ancestor - finds the lowerst common ancestor of first and
 *                         second node
 * @first: first potentially related node
 * @second: second potentially related node
 * Return: address of common ancestor
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
									 const binary_tree_t *second)
{
	size_t first_depth, second_depth, distance, i;

	if (first == NULL || second == NULL)
		return (NULL);

	first_depth = node_depth(first);
	second_depth = node_depth(second);
	/*bring first node up to second node depth*/
	if (first_depth >= second_depth)
	{
		distance = first_depth - second_depth;
		for (i = 0; second != NULL && i < distance; i++)
			first = first->parent;
	}
	/*bring second node up to first node depth*/
	else
	{
		distance = second_depth - first_depth;
		for (i = 0; first != NULL && i < distance; i++)
			second = second->parent;
	}

	while (first != NULL && second != NULL)
	{
		if (first == second)
			return ((binary_tree_t *)first);
		first = first->parent;
		second = second->parent;
	}

	return (NULL);
}
