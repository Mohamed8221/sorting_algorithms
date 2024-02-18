#include "sort.h"

/**
* swap - Swaps two integers
* @a: first integer
* @b: second integer
*/
void swap(int *a, int *b)
{
int t = *a;
*a = *b;
*b = t;
}

/**
* hoare_partition - Implements the Hoare partition scheme
* @array: Array to be partitioned
* @low: Starting index
* @high: Ending index
* @size: Size of the array
* Return: Index of the pivot element
*/
int hoare_partition(int *array, int low, int high, size_t size)
{
int pivot = array[high];
int i = low - 1;
int j = high + 1;

while (1)
{
do {
i++;
} while (array[i] < pivot);

do {
j--;
} while (array[j] > pivot);

if (i >= j)
return (j);

swap(&array[i], &array[j]);
print_array(array, size);
}
}

/**
* hoare_quicksort - Recursive function
* @array: Array to sort
* @low: Starting index of the array
* @high: Ending index of the array
* @size: Size of the array
*/
void hoare_quicksort(int *array, int low, int high, size_t size)
{
int pi;
if (low < high)
{
pi = hoare_partition(array, low, high, size);

hoare_quicksort(array, low, pi - 1, size);
hoare_quicksort(array, pi, high, size);
}
}

/**
* quick_sort_hoare - Quick sort algorithm
* @array: Array to sort
* @size: Size of the array
*/
void quick_sort_hoare(int *array, size_t size)
{
int low = 0;
int high = size - 1;

if (!array || size < 2)
return;

hoare_quicksort(array, low, high, size);
}
