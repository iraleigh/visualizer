/******************************************************************************
*   Program:    Algorithm Visualizer
*
*   Author:     Zachary Colbert
*   Contact:    zcolbert@sfsu.edu
*
*   Description:
*       Display an animation of various sorting algorithms.
******************************************************************************/


#include <stdio.h>
#include <stdlib.h>

#include <SDL2/SDL.h>

#include "data.h"
#include "observer.h"
#include "sort.h"
#include "util.h"
#include "visualizer.h"


#define SCREEN_WIDTH 640 
#define SCREEN_HEIGHT 480

#define MIN_VALUE 10
#define MAX_VALUE 100
#define NUM_VALUES 100


int main(int argc, char** argv)
{
    SDL_Window* window = NULL;
    SDL_Renderer* renderer = NULL;

    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) 
    {
        return -1;
    }
    else {
        window = SDL_CreateWindow(
            "Algorithm Visualizer",                 // Window title
            SDL_WINDOWPOS_UNDEFINED,                // Initial X position
            SDL_WINDOWPOS_UNDEFINED,                // Initial Y postion
            SCREEN_WIDTH,                           // Window width
            SCREEN_HEIGHT,                          // Window height
            SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN    // Rendering flags
        );
        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    }

    SDL_Color colors[NUM_VALUES];
    for (int i=0; i<NUM_VALUES; ++i)
    {
        SDL_Color color;
        color.r = 0xFF;
        color.g = 0xFF;
        color.b = 0xFF;
        color.a = 0xFF;
        colors[i] = color;
    }

    SDL_Rect screen_rect;
    screen_rect.x = 0;
    screen_rect.y = 0;
    screen_rect.w = SCREEN_WIDTH;
    screen_rect.h = SCREEN_HEIGHT;

    int values[NUM_VALUES];
    Data data(values, NUM_VALUES);

    Visualizer v(renderer, screen_rect, values, colors, NUM_VALUES);

    DataObserver o(&v);
    data.attach(&o, ACCESSED);
    data.attach(&o, MODIFIED);

    bool quit = false;
    SDL_Event e;
    while (!quit) 
    {
        populate_array(values, NUM_VALUES, 1, 100);

        v.redraw();         // draw the initial data
        bubblesort(data);   // sort and draw each step
        v.redraw();         // draw the sorted data

        while (SDL_PollEvent(&e) != 0)
        {
            if (e.type == SDL_QUIT) {
                quit = true;
                break;
            }
        }
        SDL_Delay(16);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    return 0;
}
