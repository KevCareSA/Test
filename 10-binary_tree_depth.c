#include "binary_trees.h"

/**
 * binary_tree_depth - calculates depth of a node inside a tree
 * @tree: pointer to the node to calculate the depth of
 * Return: depth of a node
 */

size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth = 0;

	while (tree != NULL && tree->parent != NULL)
	{
		depth++;
		tree = tree->parent;
	}

	return (depth);
}
