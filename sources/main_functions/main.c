/*
** EPITECH PROJECT, 2020
** main.c
** File description:
** main
*/

#include "include.h"
#include "function.h"

int main(int ac, char **av)
{
    int result;

    srandom(time(NULL));
    if (!check_args(ac, av))
        return (84);
    result = init_game(my_getnbr(av[1]), my_getnbr(av[2]));
    if (result == 84)
        return (0);
    else
        return (result);
}