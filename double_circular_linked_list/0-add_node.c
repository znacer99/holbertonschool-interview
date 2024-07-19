#include "list.h"
/**
 * add_node_begin - adds a new node at the beginning of list
 * @list: head of list
 * @str: the string to copy into the new node
 * Description: adds a new node at the beginning of a list.
 * Return: address of the new element, or NULL if it failed
 */
List *add_node_begin(List **list, char *str)
{
	List *last, *node = NULL;
	/*create a new node */
	node = malloc(sizeof(List));

	if (node == NULL)
		return (NULL);
	node->str = strdup(str);
	if (!node->str)
	{
		free(node);
		return (NULL);
	}
	/*if list is empty*/
	if (*list == NULL)
	{
		node->next = node->prev = node;
		*list = node;
		return (node);
	}
	last = (*list)->prev;
	node->next = (*list);
	node->prev = last; /*(*list)->prev;*/
	/*(*list)->prev->next = node;*/
	/*(*list)->prev = node;*/
	(*list)->prev = last->next = node;
	*list = node;

	return (node);
}
/**
 * add_node_end - adds a new node at the end
 * @list: head of list
 * @str:  string to copy into the new node
 * Description: adds a new node at the end of a double linked list.
 * Return: address of the new element, or NULL if it failed
 */
List *add_node_end(List **list, char *str)
{
	List *last, *node = NULL;

	node = malloc(sizeof(List));

	if (node == NULL || str == NULL)
		return (NULL);

	node->str = strdup(str);
	if (!node->str)
	{
		free(node);
		return (NULL);
	}
	/*if list is empty*/
	if (*list == NULL)
	{
		node->next = node->prev = node;
		*list = node;
		return (node);
	}
	/*find last node*/
	last = (*list)->prev;
	/*make new node next of old last*/
	/*(*list)->prev->next = node;*/
	last->next = node;
	/*list is going to be the next of node*/
	node->next = *list;
	/*make last previous of new node*/
	node->prev = last; /*(*list)->prev;*/
	/*make node previous of list*/
	(*list)->prev = node;

	return (node);
}
