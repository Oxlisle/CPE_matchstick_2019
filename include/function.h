/*
** EPITECH PROJECT, 2020
** function.h
** File description:
** All the function for matchstick
*/

#include "struct.h"

#ifndef FUNCTION_H_
#define FUNCTION_H_

void free_all(context_t *ctx);
int end_player(context_t *ctx);
int end_ia(context_t *ctx);
int ia_turn(context_t *ctx);
void remove_matches(int line, int matches, context_t *ctx);
void print_end_turn(int stat, int line, int matches);
int player_turn(context_t *ctx);
int game(context_t *ctx);
void print_map(context_t *ctx);
int check_args(int ac, char **av);
int init_game(int nb_line, int nb_matches_max);
void my_putarray(char **str, int nb);
void my_putstr_error(char *str);
void my_putnchar(char c, int n);
int my_getnbr(char const *str);
int my_putstr(char *str);
void my_putchar(char c);
void my_putnbr(int nb);

#endif /* !FUNCTION_H_ */