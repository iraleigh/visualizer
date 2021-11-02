#ifndef DATAOBSERVER_H
#define DATAOBSERVER_H

#include "dataevent.h"
#include "visualizer.h"

#include <SDL2/SDL.h>


class DataObserver
{
    public:
        DataObserver(Visualizer* visualizer);
        virtual void update(DataEvent event, int index, int value);
    private:
        Visualizer* visualizer;
};


#endif
