#include "binary_trees.h"
/**
 * binary_tree_nodes - counts nodes with at least 1 child
 *
 * @tree: Pointer to the node to measures the size
 *
 * Return: The size of the tree starting at @node
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t height_l;
	size_t height_r;

	if (tree == NULL)
		return (0);

	height_l = tree->left ? 1 + binary_tree_nodes(tree->left) : 0;
	height_r = tree->right ? 1 + binary_tree_nodes(tree->right) : 0;
	return (height_l > height_r ? height_l : height_r);
}
