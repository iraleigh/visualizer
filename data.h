/******************************************************************************
*   data.h
*
*   Author:     Zachary Colbert
*   Contact:    zcolbert@sfsu.edu
*
*   Description:
*       Declaration of Data class 
******************************************************************************/


#ifndef DATA_H
#define DATA_H

#include <unordered_map>
#include <unordered_set>

#include "observer.h"
#include "dataevent.h"


class Data
{
    public:
        Data(int* values, size_t len);

        int get(int i, bool silent=false);
        void set(int i, int val, bool silent=false);

        void attach(Observer* o, DataEvent e);
        void notify(DataEvent e, int index);

        size_t length() const;

        int* values;

    private:
        size_t length_;
        std::unordered_map<DataEvent, std::unordered_set<Observer*>> observers;
};


#endif
