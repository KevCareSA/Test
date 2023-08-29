#include "binary_trees.h"

/**
 * binary_tree_inorder - applies function (func) on node data while
 *                        traversing tree in-orderly
 * @tree: pointer to the root node
 * @func: function pointer
 */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree != NULL && func != NULL)
	{
		binary_tree_inorder(tree->left, func);
		func(tree->n);
		binary_tree_inorder(tree->right, func);
	}
}
