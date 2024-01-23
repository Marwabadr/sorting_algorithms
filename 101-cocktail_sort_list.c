#include "sort.h"
/**
 *cocktail_sort_list - Sorts a doubly linked list of integers
 *in ascending order using Cocktail shaker sort.
 *@list: Double pointer to the head of the linked list.
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *noeud;
	int swapped = 1;

	if (list == '\0' || (*list) == '\0' || (*list)->next == '\0')
		return;
	noeud = *list;
	while (swapped == 1)
	{
		swapped = 0;
		while (noeud->next)
		{
			if (noeud->n > noeud->next->n)
			{
				noeud = swap_node(noeud->next, list);
				swapped = 1;
				print_list(*list);
			}
			noeud = noeud->next;
		}
		if (swapped == 0)
			break;
		swapped = 0;
		while (noeud->prev)
		{
			if (noeud->n < noeud->prev->n)
			{
				noeud = swap_node(noeud, list);
				swapped = 1;
				print_list(*list);
			}
			else
				noeud = noeud->prev;
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
