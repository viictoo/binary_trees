#include "binary_trees.h"
#include <limits.h>
int is_bst(const binary_tree_t *tree, int lo, int hi);
int binary_tree_is_bst(const binary_tree_t *tree);
size_t binary_tree_height(const binary_tree_t *tree);
int binary_tree_balance(const binary_tree_t *tree);
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
/**
 * binary_tree_height - Measures the height of a binary tree
 *
 * @tree: Pointer to the node to measures the height
 *
 * Return: The height of the tree starting at @node
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t l = 0;
	size_t r = 0;

	if (tree == NULL)
		return (0);

	l = tree->left ? 1 + binary_tree_height(tree->left) : 1;
	r = tree->right ? 1 + binary_tree_height(tree->right) : 1;
	return (l > r ? l : r);
}

/**
 * binary_tree_balance - Measures the height of a binary tree
 *
 * @tree: Pointer to the node to measures the height
 *
 * Return: The height of the tree starting at @node
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (binary_tree_height(tree->left) -
			binary_tree_height(tree->right));
}
/**
  * binary_tree_is_avl - a function that checks if a binary tree is AVL tree
  * @tree: the tree to validate
  * Return: 1 if AVL otherwise 0
  */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int x;

	if (!tree)
		return (0);
	x = binary_tree_balance(tree);
	if (!x && binary_tree_is_bst(tree))
		return (1);
	return (0);
}
