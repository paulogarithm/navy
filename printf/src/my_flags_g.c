/*
** EPITECH PROJECT, 2022
** printf
** File description:
** my_fags_g
*/

#include "../include/functions.h"

int my_flags_g(double nb, int to_print)
{
    int printed = 0;
    int count = 0;
    double nb2 = nb;
    while (nb2 > 0 && nb2 > 10) {
        nb2 /= 10;
        count++;
    }
    while (nb2 < 1) {
        nb2 *= 10;
        count++;
    }
    if (count >= 5) {
        printed += handle_e_flags(nb, to_print);
    } else {
        printed += my_put_float(nb, to_print);
    }
    return printed;
}

int my_flags_upper_g(double nb, int to_print)
{
    int printed = 0;
    int count = 0;
    double nb2 = nb;
    while (nb2 > 0 && nb2 > 10) {
        nb2 /= 10;
        count++;
    }
    while (nb2 < 1) {
        nb2 *= 10;
        count++;
    }
    if (count >= 5) {
        printed += handle_upper_e_flags(nb, to_print);
    } else {
        printed += my_put_float(nb, to_print);
    }
    return printed;
}

int count_g(double nb, int to_print)
{
    int printed = 0;
    int count = 0;
    double nb2 = nb;
    while (nb2 > 0 && nb2 > 10) {
        nb2 /= 10;
        count++;
    }
    while (nb2 < 1) {
        nb2 *= 10;
        count++;
    }
    if (count >= 5) {
        printed += count_e(nb, to_print);
    } else {
        printed += count_f_g(nb, to_print);
    }
    return printed;
}
