/*
** ETNA PROJECT, 15/03/2019 by [...]
** [...]
** File description:
**      [...]
*/

#include "my.h"

void    SDL_ExitWithError(const char *message)
{
    SDL_Log("ERREUR : %s > %s\n", message, SDL_GetError());
    SDL_Quit();
}

int my_rand()
{
    int random = rand();

    while (random >= 700) {
        random = random / 5;
    }
    return random;
}
