#include "sort.h"


/**
 * swap_ints - Interchanges two intgrs in a array.
 * @a: First integer to be interchange.
 * @b: Second integer to be interchange.
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * selection_sort - Sort  array of intgrs following the ordr
 *                  using the selection sort algorithm.
 * @array: Array of intgrs.
 * @size: The array size.
 *
 * Desc: Array is printed after each interchange.
 */
void selection_sort(int *array, size_t size)
{
	int *min;
	size_t i, j;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min = array + i;
		for (j = i + 1; j < size; j++)
			min = (array[j] < *min) ? (array + j) : min;

		if ((array + i) != min)
		{
			swap_ints(array + i, min);
			print_array(array, size);
		}
	}
}
