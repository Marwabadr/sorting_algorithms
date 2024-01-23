#include "sort.h"
/**
 *cocktail_sort_list - Sorts a doubly linked list of integers
 *in ascending order using Cocktail shaker sort.
 *@list: Double pointer to the head of the linked list.
 */
void cocktail_sort_list(listint_t **list)
{
	int swap;
	listint_t *curr;

	if (list == NULL || *list == NULL)
		return;

	do {
		swap = 0;
		for (curr = *list; curr->next != NULL; curr = curr->next)
		{
			if (curr->n > curr->next->n)
			{
				swap_nodes(list, curr, curr->next);
				print_list(*list);
				swap = 1;
			}
		}

		if (!swap)
			break;

		swap = 0;
		for (; curr->prev != NULL; curr = curr->prev)
		{
			if (curr->n < curr->prev->n)
			{
				swap_nodes(list, curr->prev, curr);
				print_list(*list);
				swapp = 1;
			}
		}
	} while (swap);
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

