#include "util.h"
#include "sort.h"

#define NUM_VALUES 10

int main(void)
{
    int values[NUM_VALUES];
    populate_array(values, NUM_VALUES, 1, 30);
    mergesort(values, 0, NUM_VALUES-1);
    print_array(values, NUM_VALUES);
}
