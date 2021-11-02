#include "observer.h"


DataObserver::DataObserver(Visualizer* visualizer)
    :   visualizer(visualizer)
{}

void DataObserver::update(DataEvent event, int index, int value) 
{
    SDL_Color old_color = visualizer->get_index_color(index);   // capture the current color at index
    switch (event) 
    {
        case ACCESSED:
            // Set the current element color to green
            visualizer->set_index_color(index, 0x00, 0xFF, 0x00, 0xFF);
            break;
        case MODIFIED:
            // Set the accessed element color to blue
            visualizer->set_index_color(index, 0x00, 0x00, 0xFF, 0xFF);
            break;
        default:
            break;
    }
    visualizer->redraw();
    visualizer->set_index_color(index, old_color);  // restore the previous color at index
}

