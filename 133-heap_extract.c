#include "binary_trees.h"

/**
 * swap_values - Swap values between two nodes.
 * @node1: Pointer to the first node.
 * @node2: Pointer to the second node.
 */
void swap_values(heap_t *node1, heap_t *node2)
{
	int swap = node1->n;

	node1->n = node2->n;
	node2->n = swap;
}

/**
 * get_last_node - Find the last level-order node of the heap.
 * @root: Pointer to the root node of the heap.
 * Return: Pointer to the last level-order node.
 */
heap_t *get_last_node(heap_t *root)
{
	heap_t *queue[1024];
	size_t start = 0, rear = 0;
	heap_t *lase = NULL;

	if (!root)
		return (NULL);

	queue[rear] = root;
	rear++;

	while (start < rear)
	{
		lase = queue[start];

		if (lase->left)
		{
			queue[rear] = lase->left;
			rear++;
		}
		if (lase->right)
		{
			queue[rear] = lase->right;
			rear++;
		}
		start++;
	}

	return (lase);
}

/**
 * heapify_d - Perform downward heapification after extracting the root.
 * @root: Pointer to the root node of the heap.
 */
void heapify_d(heap_t *root)
{
	heap_t *max, *left, *right;

	if (!root)
		return;

	max = root;
	left = root->left;
	right = root->right;

	if (left && left->n > max->n)
		max = left;

	if (right && right->n > max->n)
		max = right;

	if (max != root)
	{
		swap_values(root, max);
		heapify_d(max);
	}
}

/**
 * heap_extract - Extract the root node of a Max Binary Heap.
 * @root: Double pointer to the root node of the heap.
 * Return: The value stored in the extracted root node, or 0 on failure.
 */
int heap_extract(heap_t **root)
{
	int xtract;
	heap_t *lase;

	if (!root || !*root)
		return (0);

	xtract = (*root)->n;
	lase = get_last_node(*root);

	if (*root == lase)
	{
		free(*root);
		*root = NULL;
		return (xtract);
	}

	swap_values(*root, lase);

	if (lase->parent->left == lase)
		lase->parent->left = NULL;
	else
		lase->parent->right = NULL;

	free(lase);

	heapify_d(*root);

	return (xtract);
}

