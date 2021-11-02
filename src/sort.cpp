/******************************************************************************
*   sort.cpp
*
*   Author:     Zachary Colbert
*   Contact:    zcolbert@sfsu.edu
*
*   Description:
*       Implementation of various sorting algorithms.
******************************************************************************/


#include "sort.h"


void bubblesort(Data data)
{
    bool sorted = false;
    int tmp;
    int max = data.length()-1;
    while (!sorted)
    {
        sorted = true;
        for (size_t i=0; i<max; ++i)
        {
            if (data.get(i) > data.get(i+1))
            {
                sorted = false;
                tmp = data.get(i);
                data.set(i, data.get(i+1));
                data.set(i+1, tmp);
            }
        }
        --max;
    }
}

