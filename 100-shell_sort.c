#include "sort.h"
/**
 * shell_sort - function that sorts usuing the shell sort
 * @array: the array to be sorted
 * @size: size of the array to be sorted
*/

void shell_sort(int *array, size_t size)
{
    size_t i, sorted_flag = 0, swaped = 0, tmp = 0;

    while (sorted_flag != 1)
    {
        swaped = 0;
        for (i = 0; i < size - 1; i++)
        {
            if (array[i] > array[i + 1])
            {
                tmp = array[i];
                array[i] = array [i + 1];
                array[i + 1] = tmp;
                swaped = 1;
                print_array(array, size);
            }
            
        }

        for (i = size - 1 ; i > 0 ; i--)
        {
            if (array[i] < array[i - 1])
            {
                tmp = array[i];
                array[i] = array [i - 1];
                array[i - 1] = tmp;
                swaped = 1;
                print_array(array, size);
            }
        }

        if (swaped == 0)
            sorted_flag = 1;
    }
}
