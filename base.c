/*
** ETNA PROJECT, 15/03/2019 by [...]
** [...]
** File description:
**      [...]
*/

#include "my.h"

void    my_putchar(char c)
{
    write(1, &c, 1);
}

void    my_putstr(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar(str[i]);
        i++;
    }
}

void    my_putnbr(int nb)
{
    if (nb < 0) {
        nb = nb * (-1);
        my_putchar('-');
    }
    if (nb >= 0 && nb <= 9) {
        my_putchar(nb + 48);
    }
    if (nb > 9) {
        my_putnbr(nb % 10);
        my_putnbr(nb / 10);
    }
}

void pause_window()
{
    int continuer = 1;
    SDL_Event   event;

    while (continuer)
        {
            SDL_WaitEvent(&event);
            switch(event.type)
                {
                case SDL_QUIT:
                    continuer = 0;
                }
        }
}

void    print_time_and_money(int time, int money)
{
    my_putstr("Time : ");
    my_putnbr(time);
    my_putchar('\n');
    my_putstr("Money : ");
    my_putnbr(money);
    my_putchar('\n');
}
