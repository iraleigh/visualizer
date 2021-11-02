#include "sort.h"

#include <stdbool.h>
#include <stdio.h>



void bubblesort(Data data, size_t len)
{
    bool sorted = false;
    int tmp;
    int max = len-1;
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

