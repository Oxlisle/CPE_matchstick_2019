/*
** EPITECH PROJECT, 2020
** struct.h
** File description:
** struct
*/

#ifndef STRUCT_H_
#define STRUCT_H_

typedef struct context_s context_t;

struct context_s
{
    char **map;
    int lenght_line;
    int nb_matches_max;
    int nb_line;
    int matches_left;
    int *matches_per_line;
};

#endif /* !STRUCT_H_ */