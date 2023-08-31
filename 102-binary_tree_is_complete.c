#include "binary_trees.h"
/**
 * count_node - a function that counts the number of nodes in a binary tree
 * @tree: a pointer to the root node of a binary tree
 * Return: number of nodes
*/
int count_node(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (1 + count_node(tree->left) + count_node(tree->right));
}
/**
 * checker - a function that checks if a binary tree is complete
 * @tree: pointer to the root node of the tree
 * @pos: integer
 * @numberNodes: number of nodes in the tree
 * Return: 1 if complete otherwise 0
*/
int checker(const binary_tree_t *tree, int pos, int numberNodes)
{
	if (tree == NULL)
		return (1);

	if (pos >= numberNodes)
		return (0);

	return (checker(tree->left, 2 * pos + 1, numberNodes) &&
			checker(tree->right, 2 * pos + 2, numberNodes));
}
/**
 * binary_tree_is_complete - function that checks if a binary tree is complete
 * @tree: pointer to the root node of the binary tree to check
 * Return: 1 if complete otherwise 0
*/
int binary_tree_is_complete(const binary_tree_t *tree)
{
	int node_count = count_node(tree);
	int pos = 0;

	return (checker(tree, pos, node_count));
}
