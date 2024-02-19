#include "sort.h"

/**
* transform_to_heap - Converts array into a heap
* @arr: The array to be sorted
* @heap_size: Size of the heap
* @root: Root index
* @arr_size: Size of the array
*/
void transform_to_heap(int *arr, size_t heap_size,
                       int root, size_t arr_size)
{
int max = root, temp;
int left_child = 2 * root + 1;
int right_child = 2 * root + 2;

if (left_child < (int)heap_size && arr[left_child] > arr[max])
max = left_child;

if (right_child < (int)heap_size && arr[right_child] > arr[max])
max = right_child;

if (max != root)
{
temp = arr[root];
arr[root] = arr[max];
arr[max] = temp;
print_array(arr, arr_size);
transform_to_heap(arr, heap_size, max, arr_size);
}
}

/**
* heap_sort_algorithm - Sorts an array of integers
* using the Heap sort algorithm
* @arr: The array to be sorted
* @size: Size of the array
*/
void heap_sort(int *array, size_t size)
{
int i, temp;

if (!array || size < 2)
return;

for (i = size / 2 - 1; i >= 0; i--)
transform_to_heap(array, size, i, size);

for (i = size - 1; i >= 0; i--)
{
temp = array[0];
array[0] = array[i];
array[i] = temp;
if (i != 0)
print_array(array, size);
transform_to_heap(array, i, 0, size);
}
}
