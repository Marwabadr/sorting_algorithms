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
 *shell_sort - Sorts an array of integers in ascending order using Shell sort
 *algorithm with Knuth sequence.
 *@array: The array to be sorted
 *@size: The size of the array
 */
void shell_sort(int *array, size_t size)
{
	size_t gap = 1, i, j;
	int temp;

	while (gap < size / 3)
		gap = gap * 3 + 1;
	while (gap > 0)
	{
		print_array(array, size);

		for (i = gap; i < size; i++)
		{
			temp = array[i];
			for (j = i; j >= gap && array[j - gap] > temp; j -= gap)
			{
				array[j] = array[j - gap];
			}
			array[j] = temp;
		}

		gap = (gap - 1) / 3;
	}

	print_array(array, size);
}
