#include "sort.h"
/**
 *cocktail_sort_list - Sorts a doubly linked list of integers
 *in ascending order using Cocktail shaker sort.
 *@list: Double pointer to the head of the linked list.
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped;
	listint_t *current;

	if (list == NULL || *list == NULL)
		return;

	do {
		swapped = 0;
		for (current = *list; current->next != NULL; current = current->next)
		{
			if (current->n > current->next->n)
			{
				swap_nodes(list, current, current->next);
				print_list(*list);
				swapped = 1;
			}
		}

		if (!swapped)
			break;

		swapped = 0;
		for (; current->prev != NULL; current = current->prev)
		{
			if (current->n < current->prev->n)
			{
				swap_nodes(list, current->prev, current);
				print_list(*list);
				swapped = 1;
			}
		}
	} while (swapped);
}
/**
 *swap_nodes - Swaps two nodes in a doubly linked list.
 *@list: Double pointer to the head of the linked list.
 *@a: First node to be swapped.
 *@b: Second node to be swapped.
 */
void swap_nodes(listint_t **list, listint_t *a, listint_t *b)
{
	if (a->prev != NULL)
		a->prev->next = b;
	else
		*list = b;

	if (b->next != NULL)
		b->next->prev = a;

	a->next = b->next;
	b->prev = a->prev;
	a->prev = b;
	b->next = a;
}

