/*
** EPITECH PROJECT, 2020
** my_putstr_error.c
** File description:
** my_putstr_error
*/

#include <unistd.h>

void my_putstr_error(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        write(2, &str [i], 1);
}