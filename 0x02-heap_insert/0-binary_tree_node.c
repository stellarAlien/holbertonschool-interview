#include "binary_trees.h"
/**
 * binary_tree_node - insert a binary tree node using max-heap
 * @parent: parent node of tree
 * @value: data field
 *
 * Return: node else NULL
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *node;


	node = (void *)malloc(sizeof(binary_tree_t));
	if (!node)
	{
		free(node);
		return (NULL)

	}
	node->parent = NULL;
	node->left = NULL;
	node->right = NULL;
	node->n = value;
	if (parent == NULL)
		return (node);
	node->parent = parent;
	return (node);
}

/**
 * binary_tree_height - prints out the height of the tree
 * @tree: input tree to printout
 * Return: tree height
 */

int binary_tree_height(const heap_t *tree)
{
	int left_height;
	int right_height;

	if (tree == NULL)
		return (0);
	if (tree->left)
		left_height = 1 + binary_tree_height(tree->left);
	else
		left_height = 0;
	if (tree->right)
		right_height = 1 + binary_tree_height(tree->right);
	else
		right_height = 0;
	return (left_height > right_height ? left_height : right_height);
}
