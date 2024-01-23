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
				noeud = swap_nodes(list, noeud->next);
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
				noeud = swap_nodes(list, noeud);
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
 *@noeud: node to be swapped
 */
listint_t *swap_nodes(listint_t **list, listint_t *noeud)
{
	listint_t *prec = noeud->prev, *actuel = noeud;

	prec->next = actuel->next;
	if (actuel->next)
		actuel->next->prev = prec;
	actuel->next = prec;
	actuel->prev = prec->prev;
	prec->prev = actuel;
	if (actuel->prev)
		actuel->prev->next = actuel;
	else
		*list = actuel;
	return (actuel);
}
