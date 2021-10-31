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
{
    SDL_SetRenderDrawColor(renderer, 0x90, 0x90, 0x90, 0x90);
    int rows = draw_area.h / row_height;

    for (size_t i=draw_area.h; i>0; i-=row_height) {
        SDL_RenderDrawLine(renderer, 0, i, draw_area.w, i);
    }
}


void Visualizer::redraw()
{
    SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
    SDL_RenderClear(renderer);
    const int vscale = 4;
    draw_gridlines(10*vscale);

    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    for (size_t i=0; i<num_values; ++i)
    {
        SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);

        SDL_Rect rect;
        rect.w = 2;
        rect.h = values[i] * vscale;
        rect.x = i*(rect.w + (rect.w / 2));
        rect.y = draw_area.h - rect.h;

        if (i != num_values-1 && values[i] > values[i+1])
        {
            SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0xFF);
        }
        else 
        {
            SDL_Color color = colors[i];
            SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
        }
        SDL_RenderFillRect(renderer, &rect);
    }
    SDL_RenderPresent(renderer);
}

void Visualizer::set_index_color(int i, SDL_Color color)
{
    if (i >= 0 && i < num_values)
    {
        colors[i] = color; 
    }
    else 
    {
        throw std::runtime_error("Invalid index");
    }
}
void Visualizer::set_index_color(int i, int r, int g, int b, int a)
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
        throw std::runtime_error("Invalid index on set");
    }
}
SDL_Color Visualizer::get_index_color(int i)
{
    if (i >= 0 && i < num_values)
    {
        return colors[i];
    }
    else 
    {
        throw std::runtime_error("Invalid index");
    }
}
