#include "binary_trees.h"
/**
 * count_nodes - a function that counts the number of nodes in a binary tree
 * @tree: a pointer to the root node of a binary tree
 * Return: number of nodes
 */
int count_nodes(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (1 + count_nodes(tree->left) + count_nodes(tree->right));
}
/**
 * re_check_complete - a function that checks if a binary tree is complete
 * @tree: pointer to the root node of the tree
 * @index: integer
 * @numberNodes: number of nodes in the tree
 * Return: 1 if complete otherwise 0
 */
int re_check_complete(const binary_tree_t *tree, int index, int numberNodes)
{
	if (tree == NULL)
		return (1);

	if (index >= numberNodes)
		return (0);

	return (re_check_complete(tree->left, 2 * index + 1, numberNodes) &&
			re_check_complete(tree->right, 2 * index + 2, numberNodes));
}
/**
 * binary_tree_is_complete - function that checks if a binary tree is complete
 * @tree: pointer to the root node of the binary tree to check
 * Return: 1 if complete otherwise 0
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	int node_count = count_nodes(tree);
	int index = 0;

	return (re_check_complete(tree, index, node_count));
}
/**
  * re_tree_is_heap - a function that checks if a binary tree is valid max heap
  * @tree: pointer to the root node of the tree to check
  * Return: 1 if is valid max binary heap otherwise 0
 */
int re_tree_is_heap(const binary_tree_t *tree)
{
	if (!tree)
		return (1);

	if (!binary_tree_is_complete(tree))
		return (0);

	if (tree->left)
		if (tree->left->n > tree->n)
			return (0);

	if (tree->right)
		if (tree->right->n > tree->n)
			return (0);

	return (re_tree_is_heap(tree->left) &&
			re_tree_is_heap(tree->right));
}
/**
  * binary_tree_is_heap - checks if a binary tree is valid max heap
  * @tree: pointer to the root node of the tree to check
  * Return: 1 if is valid max binary heap otherwise 0
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (re_tree_is_heap(tree));
}
