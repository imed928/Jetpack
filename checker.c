/*
** ETNA PROJECT, 15/03/2019 by [...]
** [...]
** File description:
**      [...]
*/

#include "my.h"

int check_surface(SDL_Surface *background)
{
    if (!background) {
        my_putstr("Erreur de chargement de l'image\n");
        return -1;
    }
    return 0;
}

int check_texture(SDL_Texture *texture)
{
    if (!texture) {
        my_putstr("Erreur de chargement de la texture\n");
        return -1;
    }
    return 0;
}

int check_querytexture(SDL_Texture *texture, SDL_Rect rectangle, SDL_Renderer *renderer, SDL_Window *window)
{
    if (SDL_QueryTexture(texture, NULL, NULL, &rectangle.w, &rectangle.h) != 0) {
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_ExitWithError("Impossible is not imed !");
        return -1;
    }
    return 0;
}

int check_copy(SDL_Texture *texture, SDL_Rect rectangle, SDL_Renderer *renderer, SDL_Window *window)
{
    if (SDL_RenderCopy(renderer, texture, NULL, &rectangle) != 0) {
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_ExitWithError("Impossible is not imed !");
        return -1;
    }
    return 0;
}

int menu(SDL_Renderer *renderer, SDL_Texture *tex, SDL_Rect rect)
{
    int i = 1;
    int j = 0;

    SDL_RenderPresent(renderer);
    while (i) {
        SDL_Event   event;
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
            case SDL_QUIT:
                j = 1;
                i = 0;
                break;
            case SDL_KEYDOWN:
                switch (event.key.keysym.sym) {
                case SDLK_ESCAPE:
                    j = 1;
                    i = 0;
                    break;
                case SDLK_RETURN:
                    SDL_RenderClear(renderer);
                    SDL_RenderPresent(renderer);
                    SDL_RenderCopy(renderer, tex, NULL, &rect);
                    j = 0;
                    i = 0;
                    break;
                default:
                    break;
                }
            default:
                break;
            }
        }
    }
    return j;
}
