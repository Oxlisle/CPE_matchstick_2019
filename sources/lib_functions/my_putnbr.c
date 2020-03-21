/*
** EPITECH PROJECT, 2019
** my_put_nbr
** File description:
** Displaying the number given as a parameter
*/

#include "function.h"

void my_putnbr(int nb)
{
    int modulo;

    if (nb < 0) {
        nb = nb * -1;
        my_putchar('-');
    }
    if (nb > 0) {
        if (nb >= 10) {
            modulo = nb%10;
            nb = nb / 10;
            my_putnbr(nb);
            my_putchar(modulo + '0');
        }
        else {
            my_putchar(nb + '0');
        }
    }
}