#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include <SDL2/SDL.h>


#define SCREEN_WIDTH 800 
#define SCREEN_HEIGHT 480
#define MIN_VALUE 10
#define MAX_VALUE 100
#define NUM_VALUES 100


void bubblesort(int* values, size_t len)
{
    bool sorted = false;
    int tmp;
    int iters = 0;
    while (!sorted)
    {
        sorted = true;
        ++iters;
        for (size_t i=0; i<len-1; ++i)
        {
            if (values[i] > values[i+1])
            {
                sorted = false;
                tmp = values[i];
                values[i] = values[i+1];
                values[i+1] = tmp;
            }
        }
    }
    printf("Finished in %d iterations\n", iters);
}

class BubbleSort 
{
    public:
        BubbleSort(int* values, size_t len) 
            : m_values(values), 
              m_len(len), 
              m_sorted(false), 
              m_pos(0),
              m_iters(0)
        {};

        void reset() 
        {
            printf("Finished after %d iterations\n", m_iters);
            m_pos = 0;
            m_iters = 0;
            m_assume_sorted = true;
            m_sorted = false;
        }
        void step() 
        {
            if (m_pos == m_len-1) {
                m_pos = 0;
                m_sorted = m_assume_sorted;
                m_assume_sorted = true;
                ++m_iters;
            }

            if (m_values[m_pos] > m_values[m_pos+1]) 
            {
                m_assume_sorted = false;
                int tmp = m_values[m_pos];
                m_values[m_pos] = m_values[m_pos+1];
                m_values[m_pos+1] = tmp;
            }
            ++m_pos;
        }

        bool m_assume_sorted;
        bool m_sorted;
        int* m_values;
        size_t m_len;
        int m_pos;
        int m_iters;
};


void draw_gridlines(SDL_Renderer* renderer, size_t row_height)
{
    SDL_SetRenderDrawColor(renderer, 0x90, 0x90, 0x90, 0x90);
    int rows = SCREEN_HEIGHT / row_height;

    for (size_t i=SCREEN_HEIGHT; i>0; i-=row_height) {
        SDL_RenderDrawLine(renderer, 0, i, SCREEN_WIDTH, i);
    }
}

void visualize_array(int* values, size_t len, int pos, SDL_Renderer* renderer)
{
    const int vscale = 4;
    draw_gridlines(renderer, 10*vscale);
    //SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0x00);
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    for (size_t i=0; i<len; ++i)
    {
        SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
        SDL_Rect rect;
        rect.w = 5;
        rect.h = values[i] * vscale;
        rect.x = i*(rect.w + (rect.w / 2));
        rect.y = SCREEN_HEIGHT - rect.h;

        if (values[i] > values[i+1]) {
            SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0x00);
        }
        if (i == pos) {
            SDL_SetRenderDrawColor(renderer, 0x00, 0xFF, 0x00, 0x00);
        }
        SDL_RenderDrawRect(renderer, &rect);
        SDL_RenderFillRect(renderer, &rect);
    }
}

void populate_array(int* arr, size_t len, int min, int max)
/* Populate the array with n=len values in range [min, max] inclusive. */
{
    for (size_t i=0; i<len; ++i) {
        arr[i] = min + random() % (max+1 - min);
    }
}

void print_array(int* values, size_t len)
{
    for (size_t i=0; i<len; ++i)
    {
        printf("%d ", values[i]);
    }
    putchar('\n');
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

    bool quit = false;
    SDL_Event e;

    int values[NUM_VALUES];
    populate_array(values, NUM_VALUES, 1, 100);
    BubbleSort bubble(values, NUM_VALUES);
#if 0
    print_array(values, NUM_VALUES);
    putchar('\n');
    bubblesort(values, NUM_VALUES);
    print_array(values, NUM_VALUES);
#endif

    while (!quit) 
    {
        //printf("Sorted: %d\n", bubble.m_sorted);
        if (!bubble.m_sorted) {
            bubble.step();
        }
        else {
            populate_array(bubble.m_values, NUM_VALUES, 10, 100);
            bubble.reset();
        }
#if 0
        else 
        {
            populate_array(bubble.m_values, NUM_VALUES, 10, 100);
            bubble.reset();
        }
#endif
        visualize_array(bubble.m_values, NUM_VALUES, bubble.m_pos, renderer);
        SDL_RenderPresent(renderer);

        while (SDL_PollEvent(&e) != 0)
        {
            if (e.type == SDL_QUIT) {
                quit = true;
                break;
            }
        }
        SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0x00);
        SDL_RenderClear(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    return 0;
}
