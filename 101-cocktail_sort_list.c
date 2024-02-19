#include "sort.h"
/**
 * 
*/

void swap_nodes(listint_t **node1, listint_t **node2)
{
	(*node1)->next = (*node2)->next;
	(*node2)->next = *node1;
	if ((*node1)->next != NULL)
		(*node1)->next->prev = *node1;
	(*node2)->prev = (*node1)->prev;
	(*node1)->prev = *node2;
	if ((*node2)->prev != NULL)
		(*node2)->prev->next = *node2;
}
/**
 * 
*/
void cocktail_sort_list(listint_t **list)
{
    size_t sorted_flag = 0, swaped = 0;
    listint_t *node1, *node2, *list_copy_start = *list, *list_copy_end;

    if (*list == NULL || list == NULL || (*list)->next == NULL)
        return;
    
    while (sorted_flag != 1)
    {
        swaped = 0;

        /* forward iteratoin */
        while (list_copy_start->next != NULL)
        {
            if (list_copy_start->n > list_copy_start->next->n)
            {
                node1 = list_copy_start;
                node2 = list_copy_start->next;
                if (list_copy_start->prev == NULL)
                {
                    swap_nodes(&node1, &node2);
                    *list = node2;
                    list_copy_start = node2;
                }
                else
                {
                    swap_nodes(&node1, &node2);
                    /* it will be moved to next at end of the while loop , that's why it is not node1*/
                    list_copy_start = node2;
                }
                /* swaped = 1; */
                print_list(*list);
                swaped = 1;
            }
            list_copy_start = list_copy_start->next;
        }
        /*move to the last node of the list */
        list_copy_end = *list;
        while (list_copy_end->next != NULL)
        {
            list_copy_end = list_copy_end->next; /* until it reaches last node */
        }
        /* backward iteration */
        while (list_copy_end->prev != NULL)
        {
            if (list_copy_end->n < list_copy_end->prev->n)
            {
                node1 = list_copy_end->prev;
                node2 = list_copy_end;
                if (list_copy_end->prev->prev == NULL)
                {
                    swap_nodes(&node1, &node2);
                    list_copy_end = node1;
                    *list = node2;
                }
                else
                {
                    swap_nodes(&node1, &node2);
                    list_copy_end = node1;
                }
                print_list(*list);
                swaped = 1;
            }
            list_copy_end = list_copy_end->prev;
        }

            if (swaped == 0)
                sorted_flag = 1;
    }
}