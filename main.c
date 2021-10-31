#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include <SDL2/SDL.h>

#include "data.h"
#include "observer.h"
#include "visualizer.h"
#include "util.h"


#define SCREEN_WIDTH 640 
#define SCREEN_HEIGHT 480
#define MIN_VALUE 10
#define MAX_VALUE 100
#define NUM_VALUES 100


void bubblesort(Data data, size_t len)
{
    bool sorted = false;
    int tmp;
    int max = len-1;
    while (!sorted)
    {
        sorted = true;
        for (size_t i=0; i<max; ++i)
        {
            if (data.get(i) > data.get(i+1))
            {
                sorted = false;
                tmp = data.get(i);
                data.set(i, data.get(i+1));
                data.set(i+1, tmp);
            }
        }
        --max;
    }
}

int main(int argc, char** argv)
{
    SDL_Window* window = NULL;
    SDL_Renderer* renderer = NULL;

    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        return 1;
    }
    else {
        window = SDL_CreateWindow(
            "Visualizer", 
            SDL_WINDOWPOS_UNDEFINED, 
            SDL_WINDOWPOS_UNDEFINED, 
            SCREEN_WIDTH, 
            SCREEN_HEIGHT, 
            SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN
        );
        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    }

    int values[NUM_VALUES];
    populate_array(values, NUM_VALUES, 1, 100);

    Data data(values, NUM_VALUES);

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

    Visualizer v(renderer, screen_rect, values, colors, NUM_VALUES);

    Observer o(&v);
    data.attach(&o, ACCESSED);
    data.attach(&o, MODIFIED);

    v.redraw();
    bubblesort(data, NUM_VALUES);
    v.redraw();


    bool quit = false;
    SDL_Event e;
    while (!quit) 
    {

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
