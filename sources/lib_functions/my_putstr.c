/*
** EPITECH PROJECT, 2019
** my_putstr.c
** File description:
** Displaying, one-by-one,
** the character of a string
*/

#include "function.h"

int my_putstr(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        my_putchar(str[i]);
    return (0);
}
