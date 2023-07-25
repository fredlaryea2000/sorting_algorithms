#include "sort.h"

void swap_ints(int *a, int *b);
int lomuto_partition(int *array, size_t size, int left, int right);
void lomuto_sort(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);


/**
 * swap_ints - two intgrs interchanges in a array.
 * @a: first integer to interchange.
 * @b: second integer to interchange.
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}


/**
 * lomuto_partition - Order subset of an array of intgrs in following
 *                    the lomuto partition scheme.
 * @array: Array of integers.
 * @size: Array size.
 * @left: Starting index of the subset to order.
 * @right: Ending indx of the subset to order.
 *
 * Return: Index of final partition.
 */
int lomuto_partition(int *array, size_t size, int left, int right)
{
	int *pivot, above, below;

	pivot = array + right;
	for (above = below = left; below < right; below++)
	{
		if (array[below] < *pivot)
		{
			if (above < below)
			{
				swap_ints(array + below, array + above);
				print_array(array, size);
			}
			above++;
		}
	}

	if (array[above] > *pivot)
	{
		swap_ints(array + above, pivot);
		print_array(array, size);
	}

	return (above);
}


/**
 * lomuto_sort - Recursion is used to implement the quicksort algorithm.
 * @array: The array of intgrs to sort.
 * @size: The array size.
 * @left: The array partition order's initial index.
 * @right: The ending index of the array partition to order.
 *
 * Desc: Uses Lomuto partition scheme.
 */
void lomuto_sort(int *array, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = lomuto_partition(array, size, left, right);
		lomuto_sort(array, size, left, part - 1);
		lomuto_sort(array, size, part + 1, right);
	}
}


/**
 * quick_sort - Sort an aray of intgrs in ascending
 *              order using the quicksort algor.
 * @array: Array of intgrs.
 * @size: The array size.
 *
 * Desc: Uses the Lomuto partition scheme. Array is printed after each swap of two elements.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
