#include "lists.h"
#include <stdlib.h>
/**
 * insert_node - insert a node in a sortedlist
 * @head: head of list
 * @number: data
 * Return: node if success else NULL 
 */
listint_t *insert_node(listint_t **head, int number)
{
    listint_t *p, *node;


    node = (listint_t *)malloc(sizeof(listint_t));
    if(node)
    {
        node->n = number;
        node->next = NULL;
    }
    else
    {
        return(NULL);
    }
    if(head == NULL || *head == NULL ||!number)
    {
        return NULL;
    }
    p = *head;
    if(p->n > number)
    {
        node->next = p;
        *head = node;
        return(*head);
    }
    while(p->next)
    {
        if(number >= p->n && number < p->next->n)
        {
            node->next = p->next;
            p->next = node;
            return(node);
        }
        p = p->next;
    }
    p->next = node;
    return(node);
}