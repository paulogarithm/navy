/*
** EPITECH PROJECT, 2022
** printf
** File description:
** my_e_flags
*/
#include "../include/functions.h"

int display_in_scientific_notation_positive(double nb, int to_print)
{
    int count = 0;
    int printed = 0;

    if (nb < 0) {
        nb = nb * - 1;
        printed += my_putchar('-');
    }
    while (nb > 0 && nb > 10) {
        nb /= 10;
        count++;
    }
    printed += my_put_float(nb, to_print);
    printed += my_putstr("e+");
    if (count < 9)
        printed += my_putchar('0');
    printed += my_put_nbr(count);
    return printed;
}

int display_in_scientific_notation_negative(double nb, int to_print)
{
    int count = 0;
    int printed = 0;
    if (nb < 0) {
        nb = nb * - 1;
        printed += my_putchar('-');
    }
    while (nb < 1) {
        nb *= 10;
        count++;
    }
    printed += my_put_float(nb, to_print);
    printed += my_putstr("e-");
    if (count < 9)
        printed += my_putchar('0');
    printed += my_put_nbr(count);
    return printed;
}

int handle_e_flags(double nb, int to_print)
{
    if (nb < 1 && nb > -1) {
        return display_in_scientific_notation_negative(nb, to_print);
    } else {
        return display_in_scientific_notation_positive(nb, to_print);
    }
    return 0;
}
