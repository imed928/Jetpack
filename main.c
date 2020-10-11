/*
** ETNA PROJECT, 15/03/2019 by [...]
** [...]
** File description:
**      [...]
*/

#include "my.h"

#define WINDOW_HEIGHT 700
#define WINDOW_WIDTH 700

SDL_Window  *window;
SDL_Renderer    *renderer;
SDL_Surface *image;
SDL_Texture *texture;
SDL_Surface *tapis;
SDL_Texture *tex;
SDL_Rect    rect = {50, 10, 100, 45};
SDL_bool    program_launched;
SDL_bool    kaaris;
SDL_Surface *background;
SDL_Texture *tex_back;
SDL_Rect    rec = {0, 0, 12992, 700};
SDL_Rect    rectangle = {0, 0, 700, 700};
SDL_Rect    r = {50, 50, 50, 50};
SDL_Surface *ennemi;
SDL_Texture *tex_ennemi;
SDL_Rect    rect_ennemi = {500, 50, 100, 45};
SDL_Surface *background_replay;
SDL_Texture *tex_replay;
SDL_Rect    rect_replay = {0, 0, 700, 700};
SDL_Surface *dirham;
SDL_Texture *tex_dirham;
SDL_Rect    rect_dirham = {200, 100, 100, 100};
int money = 0;
unsigned int    lastTime = 0, currentTime;
int continuer = 0;

void    move_down_automatic()
{
    if (rect.y <= 700) {
        rect.y += 5;
        SDL_RenderCopy(renderer, tex_back, NULL, &rec);
        SDL_RenderCopy(renderer, tex_ennemi, NULL, &rect_ennemi);
        SDL_RenderCopy(renderer, tex, NULL, &rect);
        SDL_RenderPresent(renderer);
    }
}

void    move_down()
{
    if (rect.y <= (WINDOW_HEIGHT - 90)) {
        rect.y += 20;
        SDL_RenderCopy(renderer, tex_back, NULL, &rec);
        SDL_RenderCopy(renderer, tex_ennemi, NULL, &rect_ennemi);
        SDL_RenderCopy(renderer, tex, NULL, &rect);
        SDL_RenderPresent(renderer);
    }
}

void    move_up()
{
    if (rect.y >= (0 + 60)) {
        rect.y -= 50;
        SDL_RenderCopy(renderer, tex_back, NULL, &rec);
        SDL_RenderCopy(renderer, tex_ennemi, NULL, &rect_ennemi);
        SDL_RenderCopy(renderer, tex, NULL, &rect);
        SDL_RenderPresent(renderer);
    }
}

void    the_condition()
{
    if (rect_ennemi.x == rectangle.x)
        program_launched = SDL_FALSE;
    rect_ennemi.x -= 15;
    if (rec.x == 12992)
        rec.x = rec.x - 12000;
    rec.x -= 4;
    SDL_RenderCopy(renderer, tex_back, NULL, &rec);
    SDL_RenderCopy(renderer, tex_ennemi, NULL, &rect_ennemi);
    SDL_RenderCopy(renderer, tex, NULL, &rect);
    SDL_RenderPresent(renderer);
    SDL_Delay(25);
}

int    laucher()
{
    while (program_launched) {
        currentTime = SDL_GetTicks();
        if (currentTime > lastTime + 1000)
            lastTime = currentTime;
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_Event   event;
        SDL_RenderClear(renderer);
        if (rect_ennemi.x <= 20) {
            rect_ennemi.x += 600;
            rect_ennemi.y = my_rand();
        }
        the_condition();
        if (rect.x <= rect_ennemi.x && rect.x >= rect_ennemi.x - 100 && rect.y >= rect_ennemi.y && rect.y <= rect_ennemi.y + 45) {
            SDL_DestroyRenderer(renderer);
            SDL_DestroyWindow(window);
            SDL_Quit();
            print_time_and_money(lastTime / 1000, money);
            return 1;
        }
        move_down_automatic();
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
            case SDL_QUIT:
                program_launched = SDL_FALSE;
                break;
            case SDL_KEYDOWN:
                switch (event.key.keysym.sym) {
                case SDLK_ESCAPE:
                    program_launched = SDL_FALSE;
                    SDL_DestroyRenderer(renderer);
                    SDL_DestroyWindow(window);
                    SDL_Quit();
                    break;
                case SDLK_DOWN:
                    move_down();
                    break;
                case SDLK_UP:
                    move_up();
                    break;
                }
            default:
                break;
            }
        }
    }
    return 0;
}

int main()
{
    window = NULL;
    renderer= NULL;
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
        SDL_ExitWithError("Initialisation SDL");
    if (SDL_CreateWindowAndRenderer(WINDOW_WIDTH, WINDOW_HEIGHT, 0, &window, &renderer) != 0)
        SDL_ExitWithError("Impossible de creer la fenetre et le rendu !");
    image = SDL_LoadBMP("menu_jetpack_vrai.bmp");
    texture = SDL_CreateTextureFromSurface(renderer, image);
    SDL_FreeSurface(image);
    if (check_surface(image) == (-1) || check_texture(texture) == (-1))
        return EXIT_SUCCESS;
    tapis = SDL_LoadBMP("tapiss.bmp");
    tex = SDL_CreateTextureFromSurface(renderer, tapis);
    SDL_FreeSurface(tapis);
    rect.y = (WINDOW_HEIGHT - rect.h) / 2;
    if (check_querytexture(texture, rectangle, renderer, window) == -1 || check_copy(texture, rectangle, renderer, window) == -1)
        return EXIT_SUCCESS;
    program_launched = SDL_TRUE;
    kaaris = SDL_TRUE;
    if (menu(renderer, tex, rect) == 1)
        return EXIT_SUCCESS;
    background = SDL_LoadBMP("level_1.bmp");
    tex_back = SDL_CreateTextureFromSurface(renderer, background);
    SDL_FreeSurface(background);
    if (check_surface(background) == (-1) || check_texture(tex_back) == (-1))
        return EXIT_SUCCESS;
    if (check_querytexture(tex_back, rec, renderer, window) == -1 || check_copy(tex_back, rec, renderer, window) == -1)
        return EXIT_SUCCESS;
    SDL_RenderPresent(renderer);
    ennemi = SDL_LoadBMP("méchant.bmp");
    tex_ennemi = SDL_CreateTextureFromSurface(renderer, ennemi);
    SDL_FreeSurface(ennemi);
    dirham = SDL_LoadBMP("dirham.bmp");
    tex_dirham = SDL_CreateTextureFromSurface(renderer, dirham);
    SDL_FreeSurface(dirham);
    if (check_querytexture(tex_dirham, rect_dirham, renderer, window) == -1 || check_copy(tex_dirham, rect_dirham, renderer, window) == -1)
        return EXIT_SUCCESS;
    if (check_querytexture(tex, rect_ennemi, renderer, window) == -1 || check_copy(tex, rect_ennemi, renderer, window) == -1)
        return EXIT_SUCCESS;
    if (laucher() == 1)
        return EXIT_SUCCESS;
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return EXIT_SUCCESS;
}
