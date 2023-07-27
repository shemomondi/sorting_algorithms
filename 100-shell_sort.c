#include <stdio.h>
#include "sort.h"

/**
 * shell_sort - Sorts an array of integers in ascending order using Shell sort
 *              algorithm with Knuth sequence
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void shell_sort(int *array, size_t size)
{
    size_t gap = 1;
    size_t i, j;
    int temp;

    /* Calculate the initial gap using the Knuth sequence */
    while (gap < size)
    {
        gap = gap * 3 + 1;
    }
    gap = (gap - 1) / 3;

    /* Start the sorting process with decreasing gap */
    while (gap > 0)
    {
        for (i = gap; i < size; i++)
        {
            temp = array[i];
            j = i;

            /* Insertion sort within the current gap */
            while (j >= gap && array[j - gap] > temp)
            {
                array[j] = array[j - gap];
                j -= gap;
            }

            array[j] = temp;
        }

        /* Print the array after each decrease in the gap */
        print_array(array, size);

        /* Update the gap using Knuth sequence */
        gap = (gap - 1) / 3;
    }
}
