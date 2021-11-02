/******************************************************************************
*   data.cpp
*
*   Author:     Zachary Colbert
*   Contact:    zcolbert@sfsu.edu
*
*   Description:
*       Implementation of Data class which will notify any observers when 
*       values are accessed or modified.
******************************************************************************/


#include "data.h"


Data::Data(int* values, size_t len) 
    : values(values), length_(len)
{}

int Data::get(int i, bool silent /* =false */)
/* Retrieve the value at index i */
{
    if (i >= 0 && i < length_) 
    {
        if (!silent) {
            notify(ACCESSED, i);
        }
        return values[i];
    }
    throw std::out_of_range("Invalid index");
}

void Data::set(int i, int val, bool silent /* =false */) 
/* Set the value at index i */
{
    if (i >= 0 && i < length_) 
    {
        if (!silent) {
            notify(MODIFIED, i);
        }
        values[i] = val;
    }
    else 
    {
        throw std::out_of_range("Invalid index");
    }
}

void Data::attach(DataObserver* observer, DataEvent event)
/* Attach an observer to watch for event */
{
    observers[event].insert(observer);
}

void Data::notify(DataEvent event, int index)
/* Notify all observers of this event */
{
    std::unordered_set<DataObserver*> targets = observers[event];
    for (auto t: targets) 
    {
        t->update(event, index, values[index]);
    }
}

size_t Data::length() const 
/* Return number of values in data */
{
    return length_;
}
