#include "binary_trees.h"

/**
 * array_to_avl - a function that builds an avl tree from an array
 * @array: pointer to the first element of a n array
 * @size: the number of elements in the array
 * Return: pointer to the root node of the tree created
 */

avl_t *array_to_avl(int *array, size_t size)
{
	size_t i;
	avl_t *tree;

	if (!array || size == 0)
		return (NULL);

	tree = NULL;

	for (i = 0; i < size; i++)
	{
		if (avl_insert(&tree, array[i]) == NULL)
			return (NULL);
	}
	return (tree);
}

