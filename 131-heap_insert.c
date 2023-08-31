#include "binary_trees.h"

/**
  * binary_node - a function that creates a binary tree node
  * @parent: pointer to the parent node
  * @value: value to put in the new node
  * Return: pointer to the new node or NULL on failure
  */
binary_tree_t *binary_node(binary_tree_t *parent, int value)
{
	binary_tree_t *newnode;

	newnode = (binary_tree_t *)malloc(sizeof(binary_tree_t));
	if (!newnode)
		return (NULL);

	newnode->n = value;
	newnode->parent = parent;
	newnode->left = NULL;
	newnode->right = NULL;

	return (newnode);
}
/**
 * binary_tree_size - Measures the height of a binary tree
 *
 * @tree: Pointer to the node to measures the size
 *
 * Return: The size of the tree starting at @node
 */
size_t binary_tree_size(const binary_tree_t *tree)
{

	if (tree == NULL)
		return (0);

	return (binary_tree_size(tree->left) + 1 +
			binary_tree_size(tree->right));
}

/**
 * get_parent - Find the parent node for inserting a new node.
 * @root: Pointer to the root node of the tree.
 * @size: The size of the tree.
 * Return: Pointer to the parent node for insertion.
 */
heap_t *get_parent(heap_t *root, size_t size)
{
	heap_t *parent = NULL;
	size_t idx = size + 1;

	while (idx > 1)
	{
		idx >>= 1;
		parent = root;

		if (idx & 1)
			root = root->right;
		else
			root = root->left;
	}

	return (parent);
}

/**
 * heap_insert - Insert a value into a Max Binary Heap.
 * @root: Double pointer to the root node of the heap.
 * @value: The value to insert.
 * Return: Pointer to the created node, or NULL on failure.
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *nunode, *parent;
	size_t size;
	int temp;

	if (!root)
		return (NULL);

	nunode = binary_node(NULL, value);
	if (!nunode)
		return (NULL);

	if (!*root)
	{
		*root = nunode;
		return (nunode);
	}

	size = binary_tree_size(*root);
	parent = get_parent(*root, size);

	if (!parent->left)
		parent->left = nunode;
	else
		parent->right = nunode;

	nunode->parent = parent;

	while (parent && nunode->n > parent->n)
	{
		temp = nunode->n;
		nunode->n = parent->n;
		parent->n = temp;

		nunode = parent;
		parent = parent->parent;
	}

	return (nunode);
}
