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
    listint_t *node1, *node2, *list_copy;

    while (sorted_flag != 1)
    {
        swaped = 0;
        list_copy = *list;
        while ((*list)->next != NULL)
        {
            if ((*list)->n > (*list)->next->n)
            {
                node1 = *list_copy.n;
                node2 = (*list)->next;
                swap_nodes(&node1, &node2);
                swaped = 1;
                print_list(*list);
            }
            *list = (*list)->next;
        }
        while ((*list)->prev != NULL)
        {
            if ((*list)->n < (*list)->prev->n)
            {
                node1 = *list;
                node2 = (*list)->prev;
                swap_nodes(&node1, &node2);
                swaped = 1;
                print_list(*list);
            }
            *list = (*list)->prev;
        }

        if (swaped == 0)
            sorted_flag =1;
    }  
}