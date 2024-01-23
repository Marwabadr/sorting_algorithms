#include "sort.h"
/**
*swap - the positions of two elements into an array
*@a: Pointer to the first integer
*@b: Pointer to the second integer
*/
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
/**
 *shell_sort - Sorts an array of integers in ascending order using
 *the Shell sort algorithm with the Knuth sequence.
 *@array: The array to be sorted.
 *@size: The size of the array.
 */
void shell_sort(int *array, size_t size)
{
	size_t gap = 1, i, j;

	if (array == NULL || size < 2)
		return;

	while (gap < size / 3)
		gap = gap * 3 + 1;

	while (gap > 0)
	{
		for (i = gap; i < size; i++)
		{
			for (j = i; j >= gap && array[j - gap] > array[j]; j -= gap)
			{
				swap(&array[j], &array[j - gap]);
			}
		}

		print_array(array, size);

		gap = (gap - 1) / 3;
	}
}
