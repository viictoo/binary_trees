#include "binary_trees.h"

/**
 * array_to_heap - a function that builds a max BHP tree from an array
 * @array: pointer to the first element of a n array
 * @size: the number of elements in the array
 * Return: pointer to the root node of the tree created
 */

avl_t *array_to_heap(int *array, size_t size)
{
	size_t i;
	heap_t *tree;

	if (!array || size == 0)
		return (NULL);

	tree = NULL;

	for (i = 0; i < size; i++)
	{
		heap_insert(&tree, array[i]);
	}
	return (tree);
}

