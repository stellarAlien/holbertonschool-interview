#include "binary_trees.h"

/**
 * add_node - creates binary tree node
 * @parent: is a pointer to the parent node of the node to create
 * @value: is the value to put in the new node
 * Return: return the newly created node
 */
heap_t *add_node(heap_t *parent, int value)
{
	heap_t *node;

	node = malloc(sizeof(heap_t));
	if (node == NULL)
		return (NULL);
	node->n = value;
	node->parent = parent;
	node->left = NULL;
	node->right = NULL;
	return (node);
}

/**
 * is_leaf - checks if noe is leaf
 * @node: node to check if if leaf
 * Return: 1 if node is leaf else 0
 */
size_t is_leaf(heap_t *node)
{
	if (!node->left && !node->right)
	{
		return (1);
	}
	return (0);
}

/**
 * binary_tree_depth - tree depth
 * @tree:input
 * Return:size_t depth
 */
int binary_tree_depth(const heap_t *tree)
{
	int depth = 0;

	if (tree == NULL)
		return (0);
	while (tree->parent != NULL)
	{
		tree = tree->parent;
		depth++;
	}
	return (depth);
}

/**
 * insert - inserts a value into a MBH
 * @root: is a pointer to the root node of the Heap
 * @value: is the value to put in the new node
 * @level: the row to insert a node
 * Return: pointer to node
 */
heap_t *insert(heap_t *root, int value, int level)
{
	heap_t *left, *right;

	if (root == NULL)
		return (NULL);
	if (binary_tree_depth(root) == level)
	{
		if (is_leaf(root))
			return (root->left = add_node(root, value));
		if (root->left != NULL && root->right == NULL)
			return (root->right = add_node(root, value));
		return (NULL);
	}
	left = insert(root->left, value, level);
	if (left == NULL)
		right = insert(root->right, value, level);
	else
		return (left);
	return (right);
}


/**
 * heap_insert - insert a  node in binary tree(max-heap)
 * @root: root node of tree
 * @value: data field
 * Return: node or null
 */
heap_t *heap_insert(heap_t **root, int value)
{
	int height, i, tmp;
	heap_t *node = NULL;

	if (*root == NULL)
	{
		*root = add_node(NULL, value);
		return (*root);
	}
	height = binary_tree_height(*root);
	for (i = 0; i <= height; i++)
	{
		node = insert(*root, value, i);
		if (node != NULL)
			break;
	}
	while (node->parent != NULL && node->n > node->parent->n)
	{
		tmp = node->parent->n;
		node->parent->n = node->n;
		node->n = tmp;
		node = node->parent;
	}
	return (node);
}
