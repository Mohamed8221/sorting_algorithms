#include "sort.h"

/**
 * merge - Merges two subarrays of arr[].
 * @array: Array
 * @temp: Temp array
 * @start: Starting index
 * @mid: Middle index
 * @end: Ending index
 */
void merge(int *array, int *temp, int start, int mid, int end)
{
    int i = start;
    int j = mid;
    int k = start;

    printf("Merging...\n");
    printf("[left]: ");
    print_array(array + start, mid - start);
    printf("[right]: ");
    print_array(array + mid, end - mid);

    /* Merge the temp arrays back into array[start..end]*/
    while (i < mid && j < end)
    {
        if (array[i] < array[j])
            temp[k++] = array[i++];
        else
            temp[k++] = array[j++];
    }

    /* Copy the remaining elements of left subarray, if there are any */
    while (i < mid)
        temp[k++] = array[i++];

    /* Copy the remaining elements of right subarray, if there are any */
    while (j < end)
        temp[k++] = array[j++];

    /* Copy the merged temp array back into the original array */
    for (i = start; i < end; i++)
        array[i] = temp[i];

    printf("[Done]: ");
    print_array(array + start, end - start);
}

/**
 * merge_sort_helper - Helper function to sort and merge an array
 * @array: The array to be sorted
 * @temp: Temp array
 * @start: Starting index
 * @end: Ending index
 */
void merge_sort_helper(int *array, int *temp, int start, int end)
{
    int mid;

    if (end - start > 1)
    {
        mid = start + (end - start) / 2;

        merge_sort_helper(array, temp, start, mid);
        merge_sort_helper(array, temp, mid, end);

        merge(array, temp, start, mid, end);
    }
}

/**
 * merge_sort - Sorts an array of integers in ascending order
 *              using the Merge sort algorithm
 * @array: The array to be sorted
 * @size: The size of the array
 */
void merge_sort(int *array, size_t size)
{
    int *temp;

    if (array == NULL || size < 2)
        return;

    temp = malloc(sizeof(int) * size);
    if (temp == NULL)
        return;

    merge_sort_helper(array, temp, 0, size);

    free(temp);
}
