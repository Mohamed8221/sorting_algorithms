#include "sort.h"

/**
* hoare_partition - Hoare partition scheme
* @array: Array to partition
* @low: Starting index
* @high: Ending index
* @size: Size of the array
* Return: Index of the pivot element
*/
int hoare_partition(int *array, int low, int high, size_t size)
{
int pivot = array[low];
int i = low - 1;
int j = high + 1;
int temp;

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

temp = array[i];
array[i] = array[j];
array[j] = temp;
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

hoare_quicksort(array, low, pi, size);
hoare_quicksort(array, pi + 1, high, size);
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
