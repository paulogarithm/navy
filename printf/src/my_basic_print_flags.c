/*
** EPITECH PROJECT, 2022
** B-CPE-101-PAR-1-4-myprintf-merwan.korkmaz
** File description:
** functions_
*/

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include "../include/functions.h"

int flags_c(va_list list, params_t my_param)
{
    char c = va_arg(list, int);
    int printed = 0;
    if (my_param.minus == 0) {
        printed += 1;
        printed += manage_space(printed, my_param);
        my_putchar(c);
    }
    if (my_param.minus == 1) {
        printed += manage_hash(my_param);
        printed += my_putchar(c);
        printed += manage_space(printed, my_param);
    }
    return printed;
    return my_putchar(va_arg(list, int));
}

int flags_s(va_list list, params_t my_param)
{
    char *str = va_arg(list, char *);
    if (str == NULL)
        return my_putstr("(null)");
    int printed = 0;
    if (my_param.minus == 0) {
        printed += count_s(str, my_param.precision);
        printed += manage_space(printed, my_param);
        my_putstr_and_precision(str, my_param.precision);
    }
    if (my_param.minus == 1) {
        printed += manage_hash(my_param);
        printed += my_putstr_and_precision(str, my_param.precision);
        printed += manage_space(printed, my_param);
    }
    return printed;
}

int flags_d(va_list list, params_t my_param)
{
    int d = va_arg(list, int);
    int printed = 0;
    printed += check_blank_plus(d, my_param);
    if (my_param.minus == 0) {
        printed += count_i(d, my_param);
        printed += manage_space(printed, my_param);
        my_put_nbr_and_precision(d, my_param.precision);
    }
    if (my_param.minus == 1) {
        printed += manage_hash(my_param);
        printed += my_put_nbr_and_precision(d, my_param.precision);
        printed += manage_space(printed, my_param);
    }
    return printed;
}

int flags_i(va_list list, params_t my_param)
{
    int d = va_arg(list, int);
    int printed = 0;
    printed += check_blank_plus(d, my_param);
    if (my_param.minus == 0) {
        printed += count_i(d, my_param);
        printed += manage_space(printed, my_param);
        my_put_nbr_and_precision(d, my_param.precision);
    }
    if (my_param.minus == 1) {
        printed += manage_hash(my_param);
        printed += my_put_nbr_and_precision(d, my_param.precision);
        printed += manage_space(printed, my_param);
    }
    return printed;
}

int flags_f(va_list list, params_t my_param)
{
    double d = va_arg(list, double);
    int printed = 0;
    if (my_param.minus == 0) {
        printed += count_f(d, my_param.precision);
        printed += manage_space(printed, my_param);
        my_put_float(d, my_param.precision);
    }
    if (my_param.minus == 1) {
        printed += manage_hash(my_param);
        printed += my_put_float(d, my_param.precision);
        printed += manage_space(printed, my_param);
    }
    return printed;
}
