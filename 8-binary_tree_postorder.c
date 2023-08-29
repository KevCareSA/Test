#include "binary_trees.h"

/**
 * binary_tree_postorder - applies function (func) on node data while
 *                        traversing tree post-orderly
 * @tree: pointer to the root node
 * @func: function pointer
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree != NULL && func != NULL)
	{
		binary_tree_postorder(tree->left, func);
		binary_tree_postorder(tree->right, func);
		func(tree->n);
	}
}
