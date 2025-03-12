#include <iostream>
#include <SDL2/SDL.h>

int main() {
    const int SCREEN_WIDTH = 640;
    const int SCREEN_HEIGHT = 480;

    SDL_Window* window = NULL;
    SDL_Renderer* renderer = NULL;

    // init library
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "Error: SDL could not initialize. SDL_Error: " << SDL_GetError() << "\n";
        return 1;
    }

    // create window and frame render
    window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
               SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == NULL) {
        std::cerr << "Error: window could not be created. SDL_Error: " << SDL_GetError() << "\n";
        return 1;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if(renderer == NULL ) {
        std::cerr << "Error: renderer could not be created. SDL Error: " << SDL_GetError() << "\n";
        return 1;
    }

    // clear frame
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderClear(renderer);

    // render red filled rect
    SDL_Rect fill_rect = { SCREEN_WIDTH / 4, SCREEN_HEIGHT / 4, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 };
    SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0xFF);
    SDL_RenderFillRect(renderer, &fill_rect);

    // draw blue horizontal line
    SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0xFF, 0xFF);
    SDL_RenderDrawLine(renderer, 0, SCREEN_HEIGHT / 2, SCREEN_WIDTH, SCREEN_HEIGHT / 2);

    // draw vertical line of yellow dots
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0x00, 0xFF);
    for(int i = 0; i < SCREEN_HEIGHT; i += 4) {
        SDL_RenderDrawPoint(renderer, SCREEN_WIDTH / 2, i);
    }

    // update window
    SDL_RenderPresent(renderer);

    // pause for 2 sec (2000 msec)
    SDL_Delay(2000);

    // delete everything
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}

