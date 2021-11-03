/******************************************************************************
*   observer.h
*
*   Author:     Zachary Colbert
*   Contact:    zcolbert@sfsu.edu
*
*   Description:
*       Declaration of an Observer class that may subscribe to any
*       publisher of DataEvents.
******************************************************************************/


#ifndef DATAOBSERVER_H
#define DATAOBSERVER_H

#include "dataevent.h"
#include "visualizer.h"

#include <SDL2/SDL.h>


class DataObserver
{
    public:
        DataObserver(Visualizer* visualizer);
        void update(DataEvent event, int index, int value);
    private:
        Visualizer* visualizer;
};


#endif
