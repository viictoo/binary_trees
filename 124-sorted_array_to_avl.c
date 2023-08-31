#include "binary_trees.h"
/**
 * r_insert_node - node value instertion in a AVL.
 * @array: type **pointer of root node of the AVL tree struct.
 * @parent: parent node of struct AVL.
 * @lo: lowest value.
 * @hi: highest value
 * Return: pointer to the new root after insertion otherwise NULL
 */
avl_t *r_insert_node(int *array, avl_t *parent, int lo, int hi)
{

	avl_t *nu_node;
	size_t middle;

	if (lo > hi)
		return (NULL);


	middle = (lo + hi) / 2;

	nu_node = binary_tree_node(parent, array[middle]);

	if (nu_node == NULL)
		return (NULL);

	nu_node->left = r_insert_node(array, nu_node, lo, middle - 1);
	nu_node->right = r_insert_node(array, nu_node, middle + 1, hi);

	return (nu_node);
}

/**
 * sorted_array_to_avl - a function that builds an avl tree from an array
 * @array: pointer to the first element of a n array
 * @size: the number of elements in the array
 * Return: pointer to the root node of the tree created
 */

avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (!array || size == 0)
		return (NULL);

	return (r_insert_node(array, NULL, 0, size - 1));
}
