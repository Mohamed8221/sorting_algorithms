#ifndef _SORT_H
#define _SORT_H

#include <stdlib.h>
#include <stdio.h>

/**
* struct listint_s - Doubly linked list node
*
* @n: Integer stored in the node
* @prev: Pointer to the previous element of the list
* @next: Pointer to the next element of the list
*/
typedef struct listint_s
{
const int n;
struct listint_s *prev;
struct listint_s *next;
} listint_t;

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void heap_sort(int *array, size_t size);
void radix_sort(int *array, size_t size);
void bitonic_sort(int *array, size_t size);
void quick_sort_hoare(int *array, size_t size);
int par(int *array, int l, int h, size_t size);
void quick_sort_helper(int *array, int l, int h, size_t size);
void radix_counting_sort(int *array, size_t size, int exp);
int *copy_array(int *array, size_t size);
int count_digits(int num);
void swap(int *array, ssize_t h, ssize_t l);
int h_par(int *array, int ft, int lt, int size);
void QSorter(int *array, ssize_t ft, ssize_t lt, int size);
void swap_nodes(listint_t **node1, listint_t **node2);
void transform_to_heap(int *arr, size_t heap_size, int root, size_t arr_size);

#endif
