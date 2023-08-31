#include "binary_trees.h"

/**
  * binary_tree_sibling - a function that creates a binary tree node
  * @node: pointer to the parent node
  * Return: pointer to the node or NULL on failure
  */

binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{

	if (!node || node->parent == NULL)
		return (NULL);

	if (node->parent->left == node)
		return (node->parent->right);

	return (node->parent->left);
}
