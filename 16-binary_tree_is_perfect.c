#include "binary_trees.h"

/**
 * node_height - Measures the height of a binary tree.
 * @tree: A pointer to the root node of the tree to measure the height.
 *
 * Return: If tree is NULL, your function must return 0, else return height.
 */
size_t node_height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t lh = 0, rh = 0;

		lh = tree->left ? 1 + node_height(tree->left) : 0;
		rh = tree->right ? 1 + node_height(tree->right) : 0;
		return ((lh > rh) ? lh : rh);
	}
	return (0);
}

/**
 * balancer - returns balance ratio of a tree
 * @tree: root node of a tree
 * Return: balance ratio
 */
int balancer(const binary_tree_t *tree)
{
	int lsubtree = 0, rsubtree = 0;

	if (tree == NULL)
		return (0);
	if (tree->left != NULL)
		lsubtree = 1 + node_height(tree->left);
	if (tree->right != NULL)
		rsubtree = 1 + node_height(tree->right);

	return (lsubtree - rsubtree);
}

/**
 * fcheck - uses recurision to traverse tree and check for children count
 * @tree: root node of a tree
 * @full: intialized to 1 assuming every tree will be a full tree
 * Return: 1 if full tree 0 if not
 */

int fcheck(const binary_tree_t *tree, int full)
{
	if (tree != NULL)
	{
		if ((!tree->left && tree->right) || (tree->left && !tree->right))
			full = 0;
		full = fcheck(tree->left, full);
		full = fcheck(tree->right, full);
	}
	return (full);
}

/**
 * isfull - determines if tree is a full tree
 * @tree: root node of a tree
 * Return: 1 if full tree 0 if not
 */
int isfull(const binary_tree_t *tree)
{
	int full = 1;

	if (tree == NULL)
		return (0);
	return (fcheck(tree, full));
}

/**
 * binary_tree_is_perfect - determine if a tree is perfect or not.
 * @tree: root node of a tree
 * Return: 1 if a perfect tree,  0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if (isfull(tree) == 1 && balancer(tree) == 0)
		return (1);

	return (0);
}
