/*
** EPITECH PROJECT, 2020
** player_turn.c
** File description:
** player_turn
*/

#include "function.h"
#include "struct.h"
#include "include.h"

int end_player(context_t *ctx)
{
    free_all(ctx);
    my_putstr("You win !\n");
    return (2);
}

int check_line_arg(char *buffer, context_t *ctx)
{
    int args = my_getnbr(buffer);

    if ((buffer[0] == '0' && buffer[1] == '\n') || args > ctx->nb_line) {
        my_putstr("Error: this line is out of range\n");
        return (0);
    } if (!my_getnbr(buffer) || args < 0) {
        my_putstr("Error: invalid input (positive number expected)\n");
        return (0);
    } return (1);
}

int check_matches_arg(char *buffer, int line, context_t *ctx)
{
    int args = my_getnbr(buffer);

    if ((buffer[0] == '0' && buffer[1] == '\n')) {
        my_putstr("Error: you have to remove at least one match\n");
        return (0);
    } if (!my_getnbr(buffer) || args < 0) {
        my_putstr("Error: invalid input (positive number expected)\n");
        return (0);
    } if (args > ctx->matches_per_line[line]) {
        my_putstr("Error: not enough matches on this line\n");
        return (0);
    } if (args > ctx->nb_matches_max) {
        my_putstr("Error: you cannot remove more than ");
        my_putnbr(ctx->nb_matches_max);
        my_putstr(" matches per turn\n");
        return (0);
    }
    return (1);
}

int get_arg(char *str, int type, int line, context_t *ctx)
{
    char *buffer = NULL;
    size_t size = 0;

    my_putstr(str);
    if (getline(&buffer, &size, stdin) == -1)
        return (84);
    if (type == 1) {
        if (!check_line_arg(buffer, ctx))
            return (0);
    } else {
        if (!check_matches_arg(buffer, line, ctx))
            return (0);
    } return (my_getnbr(buffer));
}

int player_turn(context_t *ctx)
{
    int line = my_putstr("\nYour turn:\n");
    int matches = 0;

    while (!matches) {
        line = get_arg("Line: ", 1, 1, ctx);
        if (line == 84)
            return (84);
        while (!line)
            line = get_arg("Line: ", 1, 1, ctx);
        matches = get_arg("Matches: ", 2, line, ctx);
        if (matches == 84)
            return (84);
    }
    remove_matches(line, matches, ctx);
    ctx->matches_left -= matches;
    ctx->matches_per_line[line] -= matches;
    print_end_turn(1, line, matches);
    print_map(ctx);
    if (ctx->matches_left == 0)
        return (1);
    return (0);
}