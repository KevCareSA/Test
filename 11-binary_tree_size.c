#include "binary_trees.h"

/**
 * calculate_size - calculates number of noes inside a tree/subtree
 * @tree: pointer to root of tree/subtree
 * @size: initialized size of 0
 * Return: size of tree/subtree
 */
size_t calculate_size(const binary_tree_t *tree, size_t size)
{
	if (tree != NULL)
	{
		size++;
		size = calculate_size(tree->left, size);
		size = calculate_size(tree->right, size);
	}
	return (size);
}

/**
 * binary_tree_size - calculates number of noes inside a tree/subtree
 * @tree: pointer to root of tree/subtree
 * Return: size of tree/subtree
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t size = 0;

	return (calculate_size(tree, size));
}
