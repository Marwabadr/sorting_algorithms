#include "sort.h"
/**
*insertion_sort_list - sert a trier une list doubly linked
*@list: pointeur sur la tete de la liste
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *crt, *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	crt = (*list)->next;

	while (crt != NULL)
	{
		tmp = crt;
		while (tmp->prev != NULL && tmp->n < tmp->prev->n)
		{
			if (tmp->next != NULL)
				tmp->next->prev = tmp->prev;
			tmp->prev->next = tmp->next;
			tmp->next = tmp->prev;
			tmp->prev = tmp->prev->prev;
			tmp->next->prev = tmp;

			if (tmp->prev == NULL)
				*list = tmp;
			else
				tmp->prev->next = tmp;
			print_list(*list);
		}
		crt = crt->next;
	}
}
