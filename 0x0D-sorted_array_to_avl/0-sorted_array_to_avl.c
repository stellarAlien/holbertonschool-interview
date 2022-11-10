#include "binary_trees.h"
/**
 * binary_tree_node - creates a binary tree node
 * @parent: pointer to the parent node of the node to create
 * @value: value to put in the new node
 *
 * Return: new binary tree node else NULL
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *node = NULL;

	node = malloc(sizeof(binary_tree_t));

	if (!node)
		return (NULL);

	node->parent = parent;
	node->left = NULL;
	node->right = NULL;
	node->n = value;

	return (node);
}
/**
 * sort_insert - Auxiliary Function for sort insertion
 * @array: array to be converted
 * @min: lower bound
 * @max: upper bound
 *
 * Return: root node of the created AVL tree else NULL
 */
avl_t *sort_insert(int *array, int min, int max)
{
    avl_t *tree;
	int mid;
	
	if (min > max)
		return (NULL);

	mid = (max + min) / 2;

	tree = binary_tree_node(NULL, array[mid]);
	if (!tree)
		return (NULL);

	tree->left = sort_insert(array, min, mid - 1);

	tree->right = sort_insert(array, mid + 1, max);

	if (tree->left)
		tree->left->parent = tree;

	if (tree->right)
		tree->right->parent = tree;

	return (tree);
}

/**
 * sorted_array_to_avl - builds an AVL tree from an array
 * @array: pointer to the first element of the array to be converted
 * @size: number of element in the array
 *
 * Return:  root node of the created AVL tree esle NULL
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *root = NULL;

	if (!array || size < 1)
		return (NULL);
	root = sort_insert(array, 0, size - 1);
	return (root);
}