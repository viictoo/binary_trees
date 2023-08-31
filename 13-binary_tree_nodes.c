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

	if (tree == NULL)
		return (0);

	if (tree->right || tree->left)
		{
		return (1 + binary_tree_nodes(tree->left) +
		binary_tree_nodes(tree->right));
		}
	return (0);
}
