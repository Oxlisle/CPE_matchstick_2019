/*
** EPITECH PROJECT, 2020
** my_putnchar.c
** File description:
** my_putnchar
*/

#include <unistd.h>

void my_putnchar(char c, int n)
{
    for (int i = 0; i != n; i++)
        write(1, &c, 1);
}