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
    if (array == NULL || size <= 1)
        return;

    size_t i, j;
    int swapped;

    for (i = 0; i < size - 1; ++i)
    {
        swapped = 0;

        for (j = 0; j < size - i - 1; ++j)
        {
            if (array[j] > array[j + 1])
            {
                /* Swap two elements */
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;

                /* Set the flag to true since a swap occurred */
                swapped = 1;

                /* Print the array after each swap */
                print_array(array, size);
            }
        }

        /* If no two elements were swapped in the inner loop, the array is already sorted */
        if (swapped == 0)
            break;
    }
}

