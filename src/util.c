#include <stdio.h>
#include <stdlib.h>


void populate_array(int* arr, size_t len, int min, int max)
/* Populate the array with n=len values in range [min, max] inclusive. */
{
    for (size_t i=0; i<len; ++i) {
        arr[i] = min + random() % (max+1 - min);
    }
}

void print_array(int* values, size_t len)
{
    for (size_t i=0; i<len; ++i) {
        printf("%d ", values[i]);
    }
    putchar('\n');
}

