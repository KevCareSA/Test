#include "binary_trees.h"

/**
 * binary_tree_leaves - calculates number of leaves inside a tree/subtree
 * @tree: pointer to root of tree/subtree
 * Return: number of leaves of tree/subtree
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
    if (tree == NULL)
        return 0;

    if (!tree->left && !tree->right)
        return 1;

    return binary_tree_leaves(tree->left) + binary_tree_leaves(tree->right);
}
