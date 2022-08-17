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


	node = malloc(sizeof(binary_tree_t));
	node->parent = NULL;
	node->left = NULL;
	node->right = NULL;
	node->n = value;
	if (parent == NULL)
		return (node);
	node->parent = parent;
	return (node);
	if(parent->left)
	{
		node->left = parent->left;
		parent->left = node;
	}
	else
	{
		node->right = parent->right;
		parent->right = node;
	}
}
