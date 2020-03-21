/*
** EPITECH PROJECT, 2020
** stat2.c
** File description:
** stat2
*/

#include "struct.h"
#include "include.h"
#include "function.h"

void free_all(context_t *ctx)
{
    for (int i = 1; i != (ctx->nb_line + 1); i++)
        free(ctx->map[i]);
    free(ctx->map);
    free(ctx->matches_per_line);
}

void remove_matches(int line, int matches, context_t *ctx)
{
    for (int i = ctx->lenght_line; matches > 0; i--)
        if (ctx->map[line][i] == '|') {
            ctx->map[line][i] = ' ';
            matches--;
        }
}

void print_end_turn(int stat, int line, int matches)
{
    if (stat)
        my_putstr("Player removed ");
    else
        my_putstr("\nAI's turn...\nAI removed ");
    my_putnbr(matches);
    my_putstr(" match(es) from line ");
    my_putnbr(line);
    my_putchar('\n');
}

void print_map(context_t *ctx)
{
    my_putnchar('*', ctx->lenght_line + 2);
    my_putchar('\n');
    for (int i = 1; i != ctx->nb_line + 1; i++) {
        my_putchar('*');
        my_putstr(ctx->map[i]);
        my_putstr("*\n");
    }
    my_putnchar('*', ctx->lenght_line + 2);
    my_putchar('\n');
}