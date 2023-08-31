#include "binary_trees.h"

int max(int a, int b);
avl_t *minNode(avl_t *tree);
/**
  * max - function that returns the highest value
  * @a: value
  * @b: value
  * Return: a if higher otherwise b
  */
int max(int a, int b)
{
	return ((a > b) ? a : b);
}

/**
  * minNode - Given a non-empty binary search tree, return the node with
  * minimum key value found in that tree.
  * @tree: binary tree
  * Return: minimum key value found in that tree.
  */
avl_t *minNode(avl_t *tree)
{
	avl_t *curr = tree;

	/* loop down to find the leftmost leaf */
	while (curr->left != NULL)
		curr = curr->left;

	return (curr);
}
/**
  * avl_bal_and_rot - a function that rebalances an avl tree after deletion
  * @root: pointer to the root node of the tree
  * Return: new root node of the tree
  */
avl_t *avl_bal_and_rot(avl_t **root)
{
	int balance;

	if (!root || !(*root))
		return (NULL);

	balance = binary_tree_balance(*root);

	if (balance > 1)
	{
		if (binary_tree_balance((*root)->left) < 0)
			(*root)->left = binary_tree_rotate_left((*root)->left);
		return (binary_tree_rotate_right(*root));
	}
	if (balance < -1)
	{
		if (binary_tree_balance((*root)->right) > 0)
			(*root)->right = binary_tree_rotate_right((*root)->right);
		return (binary_tree_rotate_left(*root));
	}
	return (*root);
}
/**
  * avl_remove - a function that removes a node from an avl tree and rebalances
  * it
  * @value: value in the node
  * @root: pointer to the root node of the tree to remove the node
  * Return: pointet to the new root node after removing the value
  */
avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *swap;

	if (root == NULL)
		return (root);

	if (value < root->n)
		root->left = avl_remove(root->left, value);
	else if (value > root->n)
		root->right = avl_remove(root->right, value);
	else
	{
		if ((root->left == NULL) || (root->right == NULL))
		{
			swap = root->left ? root->left :
				root->right;
			if (swap == NULL)
			{
				swap = root;
				root = NULL;
			}
			else
				*root = *swap;
			free(swap);
		}
		else
		{
			swap = minNode(root->right);
			root->n = swap->n;
			root->right = avl_remove(root->right, swap->n);
		}
	}
	root = avl_bal_and_rot(&root);
	return (root);
}
