#include "sort.h"
/**
 *cocktail_sort_list - Sorts a doubly linked list of integers
 *in ascending order using Cocktail shaker sort.
 *@list: Double pointer to the head of the linked list.
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped = 1;
	listint_t *start, *end;

	if (list == NULL || *list == NULL)
		return;

	while (swapped)
	{
		swapped = 0;
		for (start = *list; start->next != end; start = start->next)
		{
			if (start->n > start->next->n)
			{
				swap_nodes(list, start, start->next);
				print_list(*list);
				swapped = 1;
			}
		}

		if (!swapped)
			break;

		swapped = 0;
		end = start;

		for (start = start->prev; start->prev != NULL; start = start->prev)
		{
			if (start->n > start->next->n)
			{
				swap_nodes(list, start, start->next);
				print_list(*list);
				swapped = 1;
			}
		}
	}
}
/**
 *swap_nodes - Swaps two nodes in a doubly linked list.
 *@list: Double pointer to the head of the linked list.
 *@a: First node to be swapped.
 *@b: Second node to be swapped.
 */
void swap_nodes(listint_t **list, listint_t *a, listint_t *b)
{
	if (a->prev)
		a->prev->next = b;
	else
		*list = b;

	if (b->next)
		b->next->prev = a;

	a->next = b->next;
	b->prev = a->prev;
	a->prev = b;
	b->next = a;
}
