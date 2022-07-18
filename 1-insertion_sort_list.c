#include "sort.h"
#include <stdio.h>
/**
 * swap_consec_node - orders linked list with insertion
 * @temp: current pointer to list
 * @list: doble pointer to head
 * Return: swaps two consecutive nodes
 */
void swap_consec_node(listint_t *temp, listint_t **list)
{
	listint_t *uno, *uno_next, *uno_prev = NULL;
	listint_t *dos, *dos_next = NULL, *dos_prev;

	uno = temp;
	dos = temp->next;
	uno_next = uno->next;
	if (uno->prev)
		uno_prev = uno->prev;
	else
		uno_prev = NULL;
	if (dos->next)
		dos_next = dos->next;
	else
		dos_next = NULL;
	dos_prev = dos->prev;
	if (uno_prev)
		uno_prev->next = uno_next;
	else
		*list = dos;
	if (dos_next)
		dos_next->prev = dos_prev;
	uno->next = dos_next;
	uno->prev = dos;
	dos->next = uno;
	dos->prev = uno_prev;
}
/**
 * insertion_sort_list - orders linked list with insertion
 * @list: doble pointer to node list
 * Return: linked list ordered
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *temp, *temp_rev;
	int flag = 0, flag_rev = 0;

	if (!list)
		return;
	temp = *list;
	while (temp->next)
	{
		if (temp->n > temp->next->n)
		{
			swap_consec_node(temp, list);
			print_list(*list);
			flag = 1;
			temp_rev = temp->prev;

			while (temp_rev->prev)
			{
				if (temp_rev->prev->n > temp_rev->n)
				{
					swap_consec_node(temp_rev->prev, list);
					print_list(*list);
					flag_rev = 1;
				}
				else
					break;
				if (!flag_rev)
					temp_rev = temp_rev->prev;
				flag_rev = 0;
			}
		}
		if (!flag)
		temp = temp->next;
		flag = 0;
	}
}
