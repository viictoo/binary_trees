#include "binary_trees.h"


/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: A pointer to the root node of the tree to measure the height
 * Return: Size_t value as the height of the tree
 */


size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left, right, height = 0;

	if (tree == NULL)
		return (0);

	if (tree->left)
		left = 1 + binary_tree_height(tree->left);
	else
		left = 0;

	if (tree->right)
		right = 1 +  binary_tree_height(tree->right);
	else
		right = 0;

	if (left > right)
		height += left;
	else
		height += right;

	return (height);
}
