#include "sort.h"
/**
<<<<<<< HEAD
* radix_counting_sort - counting sort function to match the radix sorting
* @array: the array to be sorted
* @size: the size of the array to be sorted
* @exp: the power
=======
* 
*/
int count_digits(int num) {
int count = 0;
while (num != 0) {
num /= 10;
count++;
}
return count;
}
/**
* radix_counting_sort - counting sort function to match the radix sorting
* @array: the array to be sorted
* @size: the size of the array to be sorted
* @exp: the power
>>>>>>> c3fcf8f7e53aa8b803ce4d28e54dd75993c820e5
*/

void radix_counting_sort(int *array, size_t size, int exp)
{
int count[10] = {0};
int *output = malloc(sizeof(int) * size);
size_t i;


for (i = 0; i < size; i++)
count[(array[i] / exp) % 10]++;


for (i = 1; i < 10; i++)
count[i] += count[i - 1];

for (i = size - 1; i < size; i--)
{
output[count[(array[i] / exp) % 10] - 1] = array[i];
count[(array[i] / exp) % 10]--;
}

for (i = 0; i < size; i++)
array[i] = output[i];

free(output);
}
/**
* copy_array - function that would copy an array
* @array: the array to bbe copied
* @size: the size of the array to bbe copied
* Return: a pointer to the copy array
*/
int *copy_array(int *array, size_t size)
{
int *array_copy;
size_t i;

array_copy = malloc(sizeof(int) * size);

for (i = 0; i < size; i++)
{
array_copy[i] = array[i];
}

return (array_copy);
}
/**
* radix_sort - the function that sorts using the radix sorting method
* @array: the array to be sorted
* @size: the size of the array to be sorted
*/
void radix_sort(int *array, size_t size)
{
float max;
size_t i, no_of_digits = 0, all_same_number = 1, j;
int *array_copy, *remainder_array, power = 1;

<<<<<<< HEAD
for (i = 0; i < size - 1; i++)
{
if (array[i] != array[i + 1])
all_same_number = 0;
}

if (all_same_number == 1) /* the array is all the same enumber */
{
print_array(array, size);
return;
}

max = array[0];
for (i = 1; i < size; i++)
{
if (array[i] > max)
max = array[i];
}

no_of_digits = log10(max) + 1; /* number of digits */

array_copy = copy_array(array, size);
remainder_array = malloc(sizeof(int) * size);

for (j = 0; j < no_of_digits; j++)
{
radix_counting_sort(array_copy, size, power);
print_array(array_copy, size);
power *= 10;
}
free(remainder_array);
free(array_copy);
=======
for (i = 0; i < size - 1; i++)
{
if (array[i] != array[i + 1])
all_same_number = 0;
}

if (all_same_number == 1) /* the array is all the same enumber */
{
print_array(array, size);
return;
}

max = array[0];
for (i = 1; i < size; i++)
{
if (array[i] > max)
max = array[i];
}

no_of_digits = count_digits(max);

array_copy = copy_array(array, size);
remainder_array = malloc(sizeof(int) * size);

for (j = 0; j < no_of_digits; j++)
{
radix_counting_sort(array, size, power);
print_array(array, size);
power *= 10;
}
free(remainder_array);
free(array_copy);
>>>>>>> c3fcf8f7e53aa8b803ce4d28e54dd75993c820e5
}