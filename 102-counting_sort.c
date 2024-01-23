#include "sort.h"
/**
 *counting_sort - trier une table des entiers
 *@array: la table a trier
 *@size: la taille de la table
 */
void counting_sort(int *array, size_t size)
{
	int max;
	int *counting_array;
	size_t i, j;

	if (array == NULL || size < 2)
		return;
	max = array[0];
	for (i = 1; i < size; ++i)
	{
		if (array[i] > (int)max)
			max = array[i];
	}
	counting_array = malloc((max + 1) * sizeof(int));
	if (counting_array == NULL)
		return;

	for (i = 0; i <= (size_t)max; ++i)
		counting_array[i] = 0;
	j = 0;
	for (i = 0; i < size; ++i)
		counting_array[array[i]]++;
	for (i = 0; i <= (size_t)max; ++i)
	{
		while (counting_array[i] > 0)
		{
			array[j++] = i;
			counting_array[i]--;
		}
	}
	print_array(counting_array, max + 1);
	free(counting_array);
}
