#include "sort.h"
/**
 * insertion_sort_list - sorting algorithm
 * @list: double linked list
 */
void insertion_sort_list(listint_t **list)
{
	size_t len = dlistint_len(*list);
	listint_t *prev_2, *prev, *cursor, *temp;

	if (!list || len < 2)
		return;
	cursor = (*list)->next;
	while (cursor)
	{
		temp = cursor;
		while (cursor->prev && cursor->n < (cursor->prev)->n)
		{
			prev = cursor->prev;
			prev_2 = prev->prev;
			if (prev_2)
				prev_2->next = cursor;
			if(cursor->next)
				(cursor->next)->prev = prev;
			prev->next = cursor->next;
			prev->prev = cursor;
			cursor->next = prev;
			cursor->prev = prev_2;
			if (prev == *list)
				*list = cursor;
			print_list(*list);
		}
		cursor = temp->next;
	}
}
/**
 * dlistint_len - function that prints all the elements of a dlistint_t list.
 * @h: double linked list
 * Return: the number of node
 */
size_t dlistint_len(const listint_t *h)
{
	size_t len;

	for (len = 0; h; len++)
		h =  h->next;
	return (len);
}
