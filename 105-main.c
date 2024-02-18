#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
* main - Entry point
*
* Return: Always 0
*/
int main(void)
{
<<<<<<< HEAD
int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
size_t n = sizeof(array) / sizeof(array[0]);
=======
int array[] = {0, 0, 0};
size_t n = sizeof(array) / sizeof(array[0]);
>>>>>>> f4054e860c53ed2d3e77f1d24d81f92888edf0db

print_array(array, n);
printf("\n");
radix_sort(array, n);
printf("\n");
print_array(array, n);
return (0);
}
