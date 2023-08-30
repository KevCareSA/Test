#include "binary_trees.h"

/**
 * number_of_nodes - calulates number of nodes a tree's longest path
 * @tree: pointer to a node
 * @lh: initialized left height
 * @rh: initialized right height
 * Return: max nodes
 */
size_t number_of_nodes(const binary_tree_t *tree, size_t lh, size_t rh)
{
	if (tree != NULL)
	{
		lh = number_of_nodes(tree->left, lh, rh);
		rh = number_of_nodes(tree->right, lh, rh);

		return ((lh > rh ? lh : rh) + 1);
	}
	else
		return (0);
}

/**
 * binary_tree_height - returns height of node relative to its lowest leaf
 * @tree: pointer to a node in the tree
 * Return: height of a node
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t lh = 0, rh = 0;

	if (tree == NULL)
		return (0);

	return (number_of_nodes(tree, lh, rh) - 1);
}
