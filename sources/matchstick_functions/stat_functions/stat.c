/*
** EPITECH PROJECT, 2020
** stat.c
** File description:
** stat
*/

#include "function.h"
#include "include.h"
#include "struct.h"

void get_total_matches(context_t *ctx)
{
    ctx->matches_left = 0;
    for (int i = 1; i != (ctx->nb_line + 1); i++)
        ctx->matches_left = ctx->matches_left + ctx->matches_per_line[i];
}

void get_matches_per_line(context_t *ctx)
{
    int a = 1;

    ctx->matches_per_line = malloc(sizeof(int) * (ctx->nb_line + 1));
    for (int i = 1; i < (ctx->nb_line + 1); i++, a += 2)
        ctx->matches_per_line[i] = a;
}

void fill_map(int lenght_line, int nb_line, context_t *ctx)
{
    int spaces = lenght_line / 2;
    int stick = 1;
    int j = 0;

    ctx->map = malloc(sizeof(char *) * nb_line);
    for (int i = 1; i != nb_line; i++)
        ctx->map[i] = malloc(sizeof(char) * lenght_line);
    for (int k = 1; k != nb_line; k++, stick += 2, spaces--, j = 0) {
        for (int a = 0; a != spaces; a++, j++)
            ctx->map[k][j] = ' ';
        for (int b = 0; b != stick; b++, j++)
            ctx->map[k][j] = '|';
        for (int a = 0; a != spaces; a++, j++)
            ctx->map[k][j] = ' ';
    }
}

void calc_lenght(int nb_line, context_t *ctx)
{
    ctx->lenght_line = 1;
    for (int i = 1; i != nb_line; i++, ctx->lenght_line +=2);
}

int init_game(int nb_line, int nb_matches_max)
{
    context_t ctx;

    ctx.nb_matches_max = nb_matches_max;
    ctx.nb_line = nb_line;
    calc_lenght(nb_line, &ctx);
    fill_map(ctx.lenght_line, (nb_line + 1), &ctx);
    get_matches_per_line(&ctx);
    get_total_matches(&ctx);
    return (game(&ctx));
}