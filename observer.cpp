#include "observer.h"


DataObserver::DataObserver(Visualizer* visualizer)
    :   visualizer(visualizer)
{}

void DataObserver::update(DataEvent event, int index, int value) 
{
    switch (event) 
    {
        SDL_Color old_color;
        case ACCESSED:
            old_color = visualizer->get_index_color(index);
            visualizer->set_index_color(index, 0x00, 0xFF, 0x00, 0xFF);
            visualizer->redraw();
            visualizer->set_index_color(index, old_color);
            break;
        case MODIFIED:
            old_color = visualizer->get_index_color(index);
            visualizer->set_index_color(index, 0x00, 0x00, 0xFF, 0xFF);
            visualizer->redraw();
            visualizer->set_index_color(index, old_color);
            break;
        default:
            break;
    }
}

