/*
** EPITECH PROJECT, 2020
** ia_turn.c
** File description:
** ia_turn
*/

#include "include.h"
#include "function.h"
#include "struct.h"

int end_ia(context_t *ctx)
{
    free_all(ctx);
    my_putstr("You win !\n");
    return (1);
}

int check_line(int line, context_t *ctx)
{
    if (!line || ctx->matches_per_line[line] == 0)
        return (0);
    return (1);
}

int check_matches(int matches, int line, context_t *ctx)
{
    if (!matches || ctx->matches_per_line[line] < matches || \
        ctx->nb_matches_max < matches)
        return (0);
    return (1);
}

int ia_turn(context_t *ctx)
{
    int line = random() % (ctx->nb_line + 1);
    int matches = random() % (ctx->lenght_line + 1);

    while (!check_line(line, ctx))
        line = random() % (ctx->nb_line + 1);
    while (!check_matches(matches, line, ctx))
        matches = random() % (ctx->lenght_line + 1);
    remove_matches(line, matches, ctx);
    ctx->matches_left -= matches;
    ctx->matches_per_line[line] -= matches;
    print_end_turn(0, line, matches);
    print_map(ctx);
    if (ctx->matches_left == 0)
        return (1);
    else
        return (0);
}