/*
** EPITECH PROJECT, 2022
** B-CPE-101-PAR-1-4-myprintf-merwan.korkmaz
** File description:
** other_flags
*/

#include "../include/functions.h"
#include <stdarg.h>
#include <stdio.h>

int flags_upper_g(va_list list, params_t my_param)
{
    int printed = 0;
    double nb = va_arg(list, double);
    if (my_param.minus == 0) {
        printed += count_g(nb, my_param.precision);
        printed += manage_space(printed, my_param);
        printed += my_flags_upper_g(nb, my_param.precision);
    }
    if (my_param.minus == 1) {
        printed += manage_hash(my_param);
        printed += my_flags_upper_g(nb, my_param.precision);
        printed += manage_space(printed, my_param);
    }
    return printed;
}

int flags_n(va_list list, params_t my_param)
{
    int *temp = va_arg(list, int *);
    temp[0] = my_param.written;
    return 0;
}
