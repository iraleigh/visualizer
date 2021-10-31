#include "data.h"


Data::Data(int* values, size_t len) 
    : values(values), length(len)
{}

int Data::get(int i)
{
    if (i >= 0 && i < length) 
    {
        notify(ACCESSED, i);
        return values[i];
    }
    throw std::runtime_error("Invalid index");
}

void Data::set(int i, int val) 
{
    if (i >= 0 && i < length) 
    {
        notify(MODIFIED, i);
        values[i] = val;
    }
    else 
    {
        throw std::runtime_error("Invalid index");
    }
}

void Data::attach(Observer* observer, DataEvent event)
{
    observers[event].insert(observer);
}

void Data::notify(DataEvent event, int index)
{
    std::unordered_set<Observer*> targets = observers[event];
    for (auto t: targets) {
        t->update(event, index, values[index]);
    }
}

