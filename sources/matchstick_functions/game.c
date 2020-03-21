/*
** EPITECH PROJECT, 2020
** game.c
** File description:
** game
*/

#include "include.h"
#include "function.h"
#include "struct.h"

int game(context_t *ctx)
{
    int error = 0;

    print_map(ctx);
    while (1) {
        error = player_turn(ctx);
        if (error == 1)
            return (end_player(ctx));
        if (error == 84)
            return (84);
        if (ia_turn(ctx))
            return (end_ia(ctx));
    }
}