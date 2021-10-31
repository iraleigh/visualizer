#include "visualize.h"
#include <iostream>


void clear_column(SDL_Renderer* renderer, int index)
{
    SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);

    SDL_Rect rect;
    rect.w = 2;
    rect.h = SCREEN_HEIGHT;
    rect.x = index*(rect.w + (rect.w / 2));
    rect.w = 3;
    rect.y = 0;
    
    SDL_RenderFillRect(renderer, &rect);
}

void draw_gridlines(SDL_Renderer* renderer, size_t row_height)
{
    SDL_SetRenderDrawColor(renderer, 0x90, 0x90, 0x90, 0x90);
    int rows = SCREEN_HEIGHT / row_height;

    for (size_t i=SCREEN_HEIGHT; i>0; i-=row_height) {
        SDL_RenderDrawLine(renderer, 0, i, SCREEN_WIDTH, i);
    }
}

void visualize_array(int* values, SDL_Color* colors, size_t len, SDL_Renderer* renderer)
{
    const int vscale = 4;
    draw_gridlines(renderer, 10*vscale);
    //SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0x00);
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    for (size_t i=0; i<len; ++i)
    {
        SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);

        SDL_Rect rect;
        rect.w = 2;
        rect.h = values[i] * vscale;
        rect.x = i*(rect.w + (rect.w / 2));
        rect.y = SCREEN_HEIGHT - rect.h;

        
        if (values[i] > values[i+1])
        {
            SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0xFF);
        }
        else 
        {
            SDL_Color color = colors[i];
            SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
        }

        SDL_RenderDrawRect(renderer, &rect);
        SDL_RenderFillRect(renderer, &rect);
    }
}

