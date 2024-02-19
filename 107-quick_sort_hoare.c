#include "sort.h"
/**
*swap - the positions of two elements into an array
*@array: array
*@h: array element
*@l: array element
*/
void swap(int *array, ssize_t h, ssize_t l)
{
	int tmp;

	tmp = array[h];
	array[h] = array[l];
	array[l] = tmp;
}
/**
 *h_par - hoare partition sorting
 *@array: array
 *@ft: first array element
 *@lt: last array element
 *@size: size array
 *Return: return the place of the last element sorted
 */
int h_par(int *array, int ft, int lt, int size)
{
	int here = ft - 1, finder = lt + 1;
	int pivot = array[lt];

	while (1)
	{

		do {
			here++;
		} while (array[here] < pivot);
		do {
			finder--;
		} while (array[finder] > pivot);
		if (here >= finder)
			return (here);
		swap(array, here, finder);
		print_array(array, size);
	}
}
/**
 *QSorter - qucksort algorithm implementation
 *@array: array
 *@ft: first array element
 *@lt: last array element
 *@size: array size
 */
void QSorter(int *array, ssize_t ft, ssize_t lt, int size)
{
	ssize_t p = 0;

	if (ft < lt)
	{
		p = h_par(array, ft, lt, size);
		QSorter(array, ft, p - 1, size);
		QSorter(array, p, lt, size);
	}
}
/**
 *quick_sort_hoare - prepare the terrain to quicksort algorithm
 *@array: array
 *@size: array size
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	QSorter(array, 0, size - 1, size);
}
