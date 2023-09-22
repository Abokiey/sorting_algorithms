#include "sort.h"

/**
 * insertion_sort_list - Entry point-> It sorts doubly linked list
 * of integer using insertion sort algorithm.
 * @list: input doubly linked list
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *temp, *temp_2;

	if (!list || !(*list) || !(*list)->next)
		return;
	temp = *list;
	temp_2 = (*list)->next;

	while (temp_2)
	{
		while (temp && (temp_2->n < temp->n))
		{
			temp->next = temp_2->next;
			if (temp_2->next != NULL)
				temp_2->next->prev = temp;
			temp_2->next = temp;
			temp_2->prev = temp->prev;
			if (temp->prev != NULL)
				temp->prev->next = temp_2;
			temp->prev = temp_2;
			if (temp_2->prev == NULL)
				*list = temp_2;
			print_list(*list);
			temp = temp_2->prev;
		}
		temp = temp_2;
		temp_2 = temp_2->next;
	}
}
