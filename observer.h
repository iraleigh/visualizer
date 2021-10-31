#ifndef OBSERVER_H
#define OBSERVER_H

#include "dataevent.h"
#include "visualizer.h"

#include <SDL2/SDL.h>


class Observer
{
    public:
        Observer(Visualizer* visualizer);
        void update(DataEvent event, int index, int value);
        void redraw();
    private:
        Visualizer* visualizer;
};


#endif
