#include "sort.h"
#include <stdbool.h>

/**
 * insertion_sort_list - Sort a doubly linked list of integers in ascending order
 *                       using the Insertion sort algorithm.
 *
 * @list: Double pointer to the head of the list.
 */
void insertion_sort_list(listint_t **list)
{
    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    listint_t *sorted = NULL;
    listint_t *current = *list;

    while (current != NULL)
    {
        listint_t *next = current->next;
        listint_t *tail = sorted;

        if (sorted == NULL || sorted->n >= current->n)
        {
            current->next = sorted;
            current->prev = NULL;
            if (sorted)
                sorted->prev = current;
            sorted = current;
        }
        else
        {
            while (tail->next != NULL && tail->next->n < current->n)
                tail = tail->next;

            current->next = tail->next;
            if (tail->next)
                tail->next->prev = current;
            tail->next = current;
            current->prev = tail;
        }

        current = next;
        print_list(*list);
    }

    *list = sorted;
}

