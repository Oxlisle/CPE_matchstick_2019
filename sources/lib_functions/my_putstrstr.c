/*
** EPITECH PROJECT, 2020
** my_putstrstr.c
** File description:
** my_putstrstr
*/

#include <stddef.h>

void my_putstr(char *str);
void my_putchar(char c);

void my_putarray(char **str, int nb)
{
    for (int i = 1; i != nb + 1; i++) {
        my_putstr(str[i]);
        my_putchar('\n');
    }
}