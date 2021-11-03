/******************************************************************************
*   visualizer.cpp 
*
*   Author:     Zachary Colbert
*   Contact:    zcolbert@sfsu.edu
*
*   Description:
*       Implementation of the Visualizer class which draws data on the screen
*       in a bar graph format.
******************************************************************************/


#include <stdexcept>

#include "visualizer.h"


Visualizer::Visualizer(
    SDL_Renderer* renderer, 
    SDL_Rect draw_area, 
    int* values, 
    SDL_Color* colors, 
    size_t num_values
) :
    renderer(renderer),
    draw_area(draw_area),
    values(values),
    colors(colors),
    num_values(num_values)
{}

void Visualizer::draw_gridlines(size_t row_height)
/* Draw horizontal gridlines at a set interval */
{
    // choose a gray-ish color
    SDL_SetRenderDrawColor(renderer, 0x90, 0x90, 0x90, 0x90);

    // render each of the gridlines
    for (size_t i=draw_area.h; i>0; i-=row_height) 
    {
        SDL_RenderDrawLine(renderer, 0, i, draw_area.w, i);
    }
}

void Visualizer::redraw()
/* Render any changes and draw the current rendering context */
{
    // clear the screen to black
    SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
    SDL_RenderClear(renderer);

    const int vscale = 4;
    draw_gridlines(10*vscale);

    // render the vertical bar for each value
    for (size_t i=0; i<num_values; ++i)
    {
        // create a rect with the appropriate size and position
        SDL_Rect rect;
        rect.w = 4;
        rect.h = values[i] * vscale;
        rect.x = i*(rect.w + (rect.w / 2));
        rect.y = draw_area.h - rect.h;

        // choose the appropriate color to render the current rect 
        if (i != num_values-1 && values[i] > values[i+1])
        {
            // override color to red if the value is out-of-order with it's next neighbor
            SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0xFF);
        }
        else 
        {
            // choose the color from current position in the list of specified colors
            SDL_Color color = colors[i];
            SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
        }
        // render the current rect 
        SDL_RenderFillRect(renderer, &rect);
    }
    // draw the current rendering context
    SDL_RenderPresent(renderer);
}

void Visualizer::set_index_color(int i, SDL_Color color)
/* Set the color stored at index i */
{
    if (i >= 0 && i < num_values)
    {
        colors[i] = color; 
    }
    else 
    {
        throw std::out_of_range("Failed to set color: Invalid index.");
    }
}

void Visualizer::set_index_color(int i, int r, int g, int b, int a)
/* Set the color stored at index i */
{
    if (i >= 0 && i < num_values)
    {
        colors[i].r = r; 
        colors[i].g = g; 
        colors[i].b = b; 
        colors[i].a = a; 
    }
    else 
    {
        throw std::out_of_range("Failed to set color: Invalid index.");
    }
}

SDL_Color Visualizer::get_index_color(int i)
/* Retrieve the color stored at index i */
{
    if (i >= 0 && i < num_values)
    {
        return colors[i];
    }
    else 
    {
        throw std::out_of_range("Failed to retrieve index color: Invalid index.");
    }
}
