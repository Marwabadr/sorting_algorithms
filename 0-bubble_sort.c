#include "sort.h"

/**
*bubble_sort - triage a bulle
*@array: la table a trier
*@size: la taille de la table
*/
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int tmp;
	int swp;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		swp = 0;
		for (j = 0; j < size - 1 - i; j++)
		{
			if (array[j] > array[j + 1])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
				swp = 1;
				print_array(array, size);
			}
		}
		if (swp == 0)
			break;
	}
}
