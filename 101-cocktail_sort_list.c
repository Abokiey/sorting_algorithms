#include "sort.h"

void swap(int *first, int *second);

/**
 * cocktail_sort_list - Entry point-> It sorts a doubly linked list of integers
 * in ascending order using cocktail shaker sort algorithm.
 * @list: input doubly linked list
*/
void cocktail_sort_list(listint_t **list)
{
	listint_t *temp;
	int swap;

	if (!list || !*list || !(*list)->next)
		return;

	while (swap != 0)
	{
		swap = 0;
		temp = *list;
		while (temp->next != NULL)
		{
			if (temp->n > temp->next->n)
			{
				if (temp->prev != NULL)
					temp->prev->next = temp->next;
				temp->next->prev = temp->prev;
				if (temp->next->next != NULL)
					temp->next->next->prev = temp;
				temp->prev = temp->next;
				temp->next = temp->prev->next;
				temp->prev->next = temp;
				if (temp->prev == NULL)
					*list = temp;
				temp = temp->prev;
				print_list(*list);
				swap = 1;
			}
			temp = temp->next;
		}
		temp = temp->prev;

		while (temp->prev != NULL)
		{
			if (temp->prev->n > temp->n)
			{
				temp->next->prev = temp->prev;
				temp->prev->next = temp->next;
				if (temp->prev->prev != NULL)
					temp->prev->prev->next = temp;
				temp->next = temp->prev;
				temp->prev = temp->next->prev;
				temp->next->prev = temp;
				if (temp->prev == NULL)
					*list = temp;
				temp = temp->next;
				print_list(*list);
				swap = 1;
			}
			else if (temp->prev != NULL)
				temp = temp->prev;
		}
		temp = temp->next;
	}
}

/**
 * swap - Entry point-> It swaps two integers.
 * @first: input first integer
 * @second: input second integer
*/
void swap(int *first, int *second)
{
	int temp = *first;

	*first = *second;
	*second = temp;
}
