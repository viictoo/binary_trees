#include "binary_trees.h"
/**
  * bst_remove - a function that removes a node from a Binary Search Tree
  * deletes the key and returns the new root
  * @root: pointer to the root node of the tree to remove the value
  * @value: value to remove in the tree
  * Return: pointer to the new root node after removing the value
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *tmp, *succ, *succP;

	if (root == NULL)
		return (root);
	if (root->n > value)
	{
		root->left = bst_remove(root->left, value);
		return (root);
	}
	else if (root->n < value)
	{
		root->right = bst_remove(root->right, value);
		return (root);	}
	if (root->left == NULL)
	{
		tmp = root->right;
		free(root);
		return (tmp);	}
	else if (root->right == NULL)
	{
		tmp = root->left;
		free(root);
		return (tmp);
	}
	else
	{
		succP = root;
		succ = root->right;
		while (succ->left != NULL)
		{
			succP = succ;
			succ = succ->left;
		}
		if (succP != root)
			succP->left = succ->right;
		else
			succP->right = succ->right;
		root->n = succ->n;
		free(succ);
		return (root);	}
}
