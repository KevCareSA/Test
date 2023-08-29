#include "binary_trees.h"

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

size_t binary_tree_height(const binary_tree_t *tree)
{
    size_t lh = 0, rh = 0;

    return (number_of_nodes(tree, lh, rh) - 1);
}
