#include <stdlib.h>
#include <SDL.h>
#include <unistd.h>

int check_surface(SDL_Surface *background);
int check_texture(SDL_Texture *texture);
int check_querytexture(SDL_Texture *texture, SDL_Rect rectangle, SDL_Renderer *renderer, SDL_Window *window);
int check_copy(SDL_Texture *texture, SDL_Rect rectangle, SDL_Renderer *renderer, SDL_Window *window);
int menu(SDL_Renderer *renderer, SDL_Texture *tex, SDL_Rect rect);
void    my_putchar(char c);
void    my_putstr(char *str);
void    my_putnbr(int nb);
void pause_window();
void    print_time_and_money(int time, int money);
void    SDL_ExitWithError(const char *message);
int my_rand();
void    move_down_automatic();
void    move_down();
void    move_up();
void    the_condition();
int    laucher();
