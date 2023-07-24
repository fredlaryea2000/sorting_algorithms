#include "sort.h"


/**
 * swap_ints - Interchange two integers in an array.
 * @a: The first integer to interchange.
 * @b: The second integer to interchange.
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * selection_sort - Sort an array of integers follwing the order
 *                  using the selection sort algorithm.
 * @array: An array of integers.
 * @size: The array size.
 *
 * Description: Prints the array after each interchange.
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
