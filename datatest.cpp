#include <iostream>

#include "data.h"
#include "util.h"



int main()
{
    int values[100];
    populate_array(values, 100, 10, 100);
    Data data(values, 100);

    Observer o;
    data.attach(&o, ACCESSED);
    data.attach(&o, MODIFIED);

    for (size_t i=0; i<data.length; ++i)
    {
        data.get(12);
    }
    data.set(99, 99);

    return 0;
}
