/*
** EPITECH PROJECT, 2020
** main_error.c
** File description:
** main_error
*/

void my_putstr_error(char *str);
int my_getnbr(char *str);

int check_args(int ac, char **av)
{
    if (ac < 3) {
        my_putstr_error("Too few arguments.");
        return (0);
    } else if (ac > 3) {
        my_putstr_error("Too much arguments.");
        return (0);
    } else {
        if (!my_getnbr(av[1]) || my_getnbr(av[1]) > 100 || \
        my_getnbr(av[1]) < 0) {
            my_putstr_error("Your line argument is invalid");
            return (0);
        } else if (!my_getnbr(av[2])){
            my_putstr_error("Your match argument is invalid");
            return (0);
        }
    }
    return (1);
}