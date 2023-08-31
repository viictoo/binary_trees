#include "binary_trees.h"

/**
 * bst_search - a function that searches for a value in a BST
 * @tree: pointer to the root node of the tree
 * @value: value to search for
 * Return: pointer to the node containing the value otherwise NULL
 */

bst_t *bst_search(const bst_t *tree, int value)
{
	bst_t *q;

	q = (bst_t *)tree;

	while (q)
	{
		if (q->n == value)
			return (q);

		if (q->n < value)
			q = q->right;
		else
			q = q->left;
	}
	return (NULL);
}
