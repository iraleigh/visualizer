#include <SDL2/SDL.h>

#define SCREEN_WIDTH 800 
#define SCREEN_HEIGHT 480

void clear_column(SDL_Renderer* renderer, int index);
void draw_gridlines(SDL_Renderer* renderer, size_t row_height);
void visualize_array(int* values, SDL_Color* colors, size_t len, SDL_Renderer* renderer);
