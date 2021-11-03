/******************************************************************************
*   util.c
*
*   Author:     Zachary Colbert
*   Contact:    zcolbert@sfsu.edu
*
*   Description:
*       Implementation of various utilities for working with arrays. 
******************************************************************************/


#include <stdio.h>
#include <stdlib.h> // random


void populate_array(int* arr, size_t len, int min, int max)
/* Populate the array with n=len values in range [min, max] inclusive. */
{
    for (size_t i=0; i<len; ++i) 
    {
        arr[i] = min + random() % (max+1 - min);
    }
}

void print_array(int* values, size_t len)
/* Print the contents of an array */
{
    for (size_t i=0; i<len-1; ++i) 
    {
        printf("%d ", values[i]);
    }
    printf("%d\n", values[len-1]);  // print the last value without a trailing space
}

