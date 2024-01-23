#include "sort.h"
/**
 * insertion_sort_list: sert a trier en ordre croissant une liste doublement chainee
 * @list: pointeur sur la tete de la liste doublement chainee
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *act, *pred, *tmp;

	 if (list == NULL || *list == NULL || (*list)->next == NULL)
		 return ;

	 act  = (*list)->next;

	 while (act != NULL)
	 {
		 tmp = act;
		 pred = act->prev;

		 while (pred != NULL && pred->n > tmp->n)
		 {
			 if (tmp->next != NULL)
				 tmp->next->prev = pred;
			 pred->next = tmp->next;
			 tmp->prev = pred->prev;
			 tmp->next = pred;
			 pred->prev = tmp;
			 if (tmp->prev == NULL)
				 *list = tmp;
			 print_list(*list);
			 pred = tmp->prev;
		 }
		 act = act->next;
	 }
}

