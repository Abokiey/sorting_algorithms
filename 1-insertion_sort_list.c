#include "sort.h"

/**
 * swap_node - swaps nodes
 * node_1: first node
 * node_2: second node
 * @head: head of the list
 */
void swap_node(listint_t **head, listint_t *node_1, listint_t *node_2)
{
	listint_t *prev, *next;

	prev = node_1->prev;
	next = node_2->next;

	if (prev != NULL)
		prev->next = node_2;
	else
		*head = node_2;

	node_1->prev = node_2;
	node_1->next = next;
	node_2->prev = prev;
	node_2->next = node_1;
	if (next)
		next->prev = node_1;
}

/**
 *
 * insertion_sort_list - insertion sort
 *
 * @list: doubly linked list
 */
 void insertion_sort_list(listint_t **list)
{
	listint_t *node, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (node = (*list)->next; node && node->prev; node = node->next)
	{
		for (; node && node->prev && node->n < node->prev->n;
			 node = node->prev)
		{
			tmp = node->prev;
			swap_node(list, temp, node);
			print_list(*list);
			node = node->next;
		}
	}

}
