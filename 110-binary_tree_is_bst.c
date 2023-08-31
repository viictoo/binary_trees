#include "binary_trees.h"
#include <limits.h>

/**
 * is_bst - A function that checks if a binary tree is a bst
 * @tree: pointer to the root node of the tree to check
 * @lo: min value
 * @hi: max value
 * Return: 1 if is a valid BST otherwise 0
 */
int is_bst(const binary_tree_t *tree, int lo, int hi)
{
	if (tree == NULL)
		return (1);

	if (tree->n < lo || tree->n > hi)
		return (0);

	return (is_bst(tree->left, lo, tree->n - 1)
		&& is_bst(tree->right, tree->n + 1, hi));
}

/**
 * binary_tree_is_bst - A function that checks if a binary tree is a bst
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if is a valid BST otherwise 0
 */

int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (is_bst(tree, INT_MIN, INT_MAX));
}

