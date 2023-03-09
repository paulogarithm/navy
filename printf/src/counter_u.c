/*
** EPITECH PROJECT, 2022
** B-CPE-101-PAR-1-4-myprintf-merwan.korkmaz
** File description:
** counter_u
*/

#include <stdio.h>
#include "../include/functions.h"

int my_count_decimal(int nb, int to_print)
{
    if (to_print == 0)
        to_print = 6;
    while (to_print != my_intlen(nb)) {
        if (to_print < my_intlen(nb))
            nb = (nb - (nb % 10)) / 10;
        if (to_print > my_intlen(nb))
            nb = nb * 10;
    }
    return my_intlen(nb);
}

int count_u(unsigned int nb, int to_print)
{
    int count = 0;
    if (my_intlen(nb) < to_print){
        for (int i = 0; i < (my_intlen(nb) - to_print); i++)
            count += 1;
    }
    if (nb >= 10)
        count += my_intlen(nb / 10);
    count += 1;
    return count;
}

int count_i(int nb, params_t param)
{
    int print = 0;
    if (param.precision > my_intlen(nb) && param.precision != 0) {
        print += param.precision;
    }
    if (param.precision < my_intlen(nb) && param.precision != 0) {
        print += my_intlen(nb);
    }
    if (param.precision == 0)
        print += my_intlen(nb);
    return print;
}
