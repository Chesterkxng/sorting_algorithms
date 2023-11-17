#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>

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

/** printing functions **/
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

/** Bubble sort **/
void _swap(int *array, int idx1, int idx2);
void bubble_sort(int *array, size_t size);

/** insertion sort list **/
size_t dlistint_len(const listint_t *h);
void insertion_sort_list(listint_t **list);


#endif /* SORT_H */
