#include "binary_trees.h"

/**
 * is_leaf - checks if noe is leaf
 * node - node to check if if leaf
 * Return: 1 if node is leaf else 0
 */
size_t is_leaf(heap_t *node)
{
    if(!node->left && !node->right)
    {
        return(1);
    }
    return(0);
}
/**
 * heap_insert - insert a  node in binary tree(max-heap) 
 * root - root node of tree
 * value - data field
 * Return
 */
heap_t *heap_insert(heap_t **root, int value)
{
    heap_t *node, *sn;

    node =(heap_t*)malloc(sizeof(heap_t));
    if(node){
        node->parent = NULL;
        node->left = NULL;
        node->right = NULL;
        node->n = value;
    }
    else{
        return(NULL);
    }
    if(root == NULL || *root == NULL)
    {
        return(node);
    }
    //search node takes root node
    while(sn)
    {
        if(is_leaf(sn))
        {
            node->parent = sn;
            sn->left = node;
        }
        if(sn->right && sn->right->n >= value)
        {
            node->parent = sn;
            node->left = sn->left;
            node->right = sn->right;
            return(node);
         }
         else if(sn->left && sn->left->n >= value){
            node->parent = sn;
            node->left = sn->left;
            node ->right = sn->right;
            return(node);
         }  
         else if((sn->right - value) > (sn->left - value))
         {
            sn = sn->left;
         }
         else{
            sn = sn->right;
         }
         }
         return(node);
}