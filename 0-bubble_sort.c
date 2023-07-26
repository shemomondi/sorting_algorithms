#include <stdio.h>
#include "sort.h"

/**
 * bubble_sort - Sorts an array of integers in ascending order using Bubble sort
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void bubble_sort(int *array, size_t size)
{
    size_t i, j;
    int temp;

    if (size < 2)
	    return;

    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                /* Swap the elements */
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;

                /* Print the array after each swap */
                print_array(array, size);
            }
        }
    }
}

