#include "binary_trees.h"
/**
 * binary_tree_node: insert a binary tree node using max-heap 
 * @parent - parent node of tree
 * @value - data field
 * Return - node else NULL
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
    binary_tree_t *node;


    node = (binary_tree_t*)malloc(sizeof(binary_tree_t));
    node->parent = NULL;
    node->left = NULL;
    node->right = NULL;
    node->n = value;
    if(parent == NULL)
    {
        return(node);
    }
    //node takes parent
    node->parent = parent;
    if(!parent->left)
    {
        parent->left = node;
    }
    else{
        parent->right = node;
    }
    return(node);
}