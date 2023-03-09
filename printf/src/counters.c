/*
** EPITECH PROJECT, 2022
** B-CPE-101-PAR-1-4-myprintf-merwan.korkmaz
** File description:
** counters
*/

#include "../include/functions.h"
#include <stdio.h>

int count_e(double nb, int to_print)
{
    int count = 0;
    if (nb < 1 && nb > -1) {
        count += count_in_scientific_notation_negative(nb, to_print);
    } else {
        count += count_in_scientific_notation_positive(nb, to_print);
    }
    return count;
}

int count_in_scientific_notation_positive(double nb, int to_print)
{
    int count = 0;
    int printed = 0;

    if (nb < 0) {
        nb = nb * - 1;
        printed += 1;
    }
    while (nb > 0 && nb > 10) {
        nb /= 10;
        count++;
    }
    printed += count_f(nb, to_print);
    return printed;
}

int count_in_scientific_notation_negative(double nb, int to_print)
{
    int count = 0;
    int printed = 0;
    if (nb < 0) {
        nb = nb * - 1;
        printed += 1;
    }
    while (nb < 1) {
        nb *= 10;
        count++;
    }
    printed += count_f(nb, to_print);
    return printed;
}

int count_f(double nb, int to_print)
{
    int nb2 = 0;
    int nb3 = 0;
    int count = 0;
    int printed = 0;
    printed += my_intlen((int)nb);
    nb2 = nb -= (int)nb;
    printed += 1;
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
        printed += 1;
    printed += my_count_decimal((int)nb, to_print);
    return printed;
}

int count_f_g(double nb, int to_print)
{
    int nb2 = 0;
    int nb3 = 0;
    int count = 0;
    int printed = 0;
    printed += my_intlen((int)nb);
    nb2 = nb -= (int)nb;
    printed += 1;
    nb2 = nb *= 1000000;
    nb3 = nb2;
    if (nb3 < 0)
        nb2 = nb * -1;
    nb3 = nb2;
    while (nb3 > 0) {
        nb3 = nb3 / 10;
        count++;
    }
    printed += my_count_decimal((int)nb, to_print);
    return printed;
}
