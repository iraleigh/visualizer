/******************************************************************************
*   visualizer.h
*
*   Author:     Zachary Colbert
*   Contact:    zcolbert@sfsu.edu
*
*   Description:
*       Declaration of the Visualizer class which draws data on the screen
*       in a bar graph format.
******************************************************************************/


#ifndef VISUALIZER_H
#define VISUALIZER_H


#include <SDL2/SDL.h>


class Visualizer
{
    public:
        Visualizer(
            SDL_Renderer* renderer, 
            SDL_Rect draw_area, 
            int* values, 
            SDL_Color* colors, 
            size_t num_values
        );
        void redraw();
        void draw_gridlines(size_t row_height);
        SDL_Color get_index_color(int i);
        void set_index_color(int i, SDL_Color color);
        void set_index_color(int i, int r, int g, int b, int a);

    private:
        SDL_Renderer* renderer;
        SDL_Rect draw_area;
        int* values;
        size_t num_values;
        SDL_Color* colors;
};


#endif
