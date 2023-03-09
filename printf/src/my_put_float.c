/*
** EPITECH PROJECT, 2022
** printf
** File description:
** my_put_float
*/


#include <stdio.h>
#include "../include/functions.h"

int my_put_float(double nb, int to_print)
{
    int nb2 = 0;
    int nb3 = 0;
    int count = 0;
    int printed = 0;
    printed += my_put_nbr((int)nb);
    nb2 = nb -= (int)nb;
    printed += my_putchar('.');
    nb2 = nb *= 1000000;
    nb3 = nb2;
    if (nb3 < 0)
        nb2 = nb * -1;
    nb3 = nb2;
    while (nb3 > 0) {
        nb3 = nb3 / 10;
        count++;
    }
    for (int i = count; i < 6; i++)
        printed += my_putchar('0');
    printed += my_put_decimal((int)nb, to_print);
    return printed;
}

int my_put_decimal(int nb, int to_print)
{
    if (to_print == 0)
        to_print = 6;
    while (to_print != my_intlen(nb)) {
        if (to_print < my_intlen(nb))
            nb = (nb - (nb % 10)) / 10;
        if (to_print > my_intlen(nb))
            nb = nb * 10;
    }
    return my_put_nbr(nb);
}

int my_put_float_g(double nb, int to_print, int decimals)
{
    to_print = check_precision_float(to_print, decimals);
    int nb2 = 0;
    int nb3 = 0;
    int count = 0;
    int printed = 0;
    printed += my_put_nbr((int)nb);
    nb2 = nb -= (int)nb;
    printed += my_putchar('.');
    nb2 = nb *= 1000000;
    nb3 = nb2;
    if (nb3 < 0)
        nb2 = nb * -1;
    nb3 = nb2;
    while (nb3 > 0) {
        nb3 = nb3 / 10;
        count++;
    }
    for (int i = count; i < 6; i++)
        printed += my_putchar('0');
    return printed += my_put_decimal((int)nb, to_print);
}

int check_precision_float(int to_print, int decimals)
{
    if (to_print == 0) {
        to_print = decimals;
    }
    if (to_print > decimals) {
        to_print = decimals;
    }
    return to_print;
}
