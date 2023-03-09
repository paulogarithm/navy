/*
** EPITECH PROJECT, 2022
** piscine-partie-2
** File description:
** my_flags_functions
*/

#include <stdarg.h>
#include <unistd.h>
#include "../include/functions.h"

int flags_b(va_list list, params_t my_param)
{
    char *base = "01";
    int d = va_arg(list, int);
    int printed = 0;
    if (my_param.minus == 0) {
        printed += manage_hash(my_param);
        printed += count_nbr_base(d, base, my_param.precision);
        printed += manage_space(printed, my_param);
        my_putnbr_base(d, base, my_param.precision);
    }
    if (my_param.minus == 1) {
        printed += manage_hash(my_param);
        printed += my_putnbr_base(d, base, my_param.precision);
        printed += manage_space(printed, my_param);
    }
    return printed;
}

int flags_x(va_list list, params_t my_param)
{
    char *base = "0123456789abcdef";
    long int d = va_arg(list, long int);
    int printed = 0;
    if (my_param.minus == 0) {
        printed += manage_hash(my_param);
        printed += count_nbr_base(d, base, my_param.precision);
        printed += manage_space(printed, my_param);
        my_putnbr_base(d, base, my_param.precision);
    }
    if (my_param.minus == 1) {
        printed += manage_hash(my_param);
        printed += my_putnbr_base(d, base, my_param.precision);
        printed += manage_space(printed, my_param);
    }
    return printed;
}

int flags_x_maj(va_list list, params_t my_param)
{
    char *base = "0123456789ABCDEF";
    int d = va_arg(list, int);
    int printed = 0;
    if (my_param.minus == 0) {
        printed += manage_hash(my_param);
        printed += count_nbr_base(d, base, my_param.precision);
        printed += manage_space(printed, my_param);
        my_putnbr_base(d, base, my_param.precision);
    }
    if (my_param.minus == 1) {
        printed += manage_hash(my_param);
        printed += my_putnbr_base(d, base, my_param.precision);
        printed += manage_space(printed, my_param);
    }
    return printed;
}

int flags_p(va_list list, params_t my_param)
{
    char *base = "0123456789abcdef";
    int d = va_arg(list, int);
    int printed = 0;
    if (my_param.minus == 0) {
        printed += 2;
        printed += count_nbr_base(d, base, my_param.precision);
        printed += manage_space(printed, my_param);
        my_putstr("0x");
        my_putnbr_base(d, base, my_param.precision);
    }
    if (my_param.minus == 1) {
        printed += manage_hash(my_param);
        printed += my_putstr("0x");
        printed += my_putnbr_base(d, base, my_param.precision);
        printed += manage_space(printed, my_param);
    }
    return printed;
}

int flags_o(va_list list, params_t my_param)
{
    char *base = "01234567";
    int d = va_arg(list, int);
    int printed = 0;
    if (my_param.minus == 0) {
        printed += manage_hash(my_param);
        printed += count_nbr_base(d, base, my_param.precision);
        printed += manage_space(printed, my_param);
        my_putnbr_base(d, base, my_param.precision);
    }
    if (my_param.minus == 1) {
        printed += manage_hash(my_param);
        printed += my_putnbr_base(d, base, my_param.precision);
        printed += manage_space(printed, my_param);
    }
    return printed;
}
