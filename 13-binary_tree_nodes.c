#include "binary_trees.h"

/**
 * calculate_nodes - calculates number of non-leaves inside a tree/subtree
 * @tree: pointer to root of tree/subtree
 * @node: node count
 * Return: number of non-leaves of tree/subtree
 */

size_t calculate_nodes(const binary_tree_t *tree, size_t node)
{
	if (tree != NULL)
	{
		node += (tree->right != NULL || tree->left != NULL) ? 1 : 0;
		node = calculate_nodes(tree->left, node);
		node = calculate_nodes(tree->right, node);
	}
	return (node);
}

/**
 * binary_tree_nodes - calculates number of non-leaves inside a tree/subtree
 * @tree: pointer to root of tree/subtree
 * Return: number of non-leaves of tree/subtree
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t node = 0;

	return (calculate_nodes(tree, node));
}
