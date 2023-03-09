/*
** EPITECH PROJECT, 2022
** B-CPE-101-PAR-1-4-myprintf-merwan.korkmaz
** File description:
** print_flags
*/

#include "../include/functions.h"
#include <stdarg.h>
#include <stdio.h>

int flags_e(va_list list, params_t my_param)
{
    double nb = va_arg(list, double);
    int printed = 0;
    if (my_param.minus == 0 && my_param.spaces > 0) {
        printed += count_e(nb, my_param.precision);
        printed += manage_space(printed, my_param);
        handle_e_flags(nb, my_param.precision);
    }
    if (my_param.minus == 1 && my_param.spaces > 0) {
        printed += handle_e_flags(nb, my_param.precision);
        printed += manage_space(printed, my_param);
    }
    if (my_param.spaces == 0) {
        printed += manage_hash(my_param);
        printed += handle_e_flags(nb, my_param.precision);
    }
    return printed;
}

int flags_upper_e(va_list list, params_t my_param)
{
    int printed = 0;
    double nb = va_arg(list, double);
    if (my_param.minus == 0) {
        printed += count_e(nb, my_param.precision);
        printed += manage_space(printed, my_param);
        handle_upper_e_flags(nb, my_param.precision);
    }
    if (my_param.minus == 1) {
        printed += manage_hash(my_param);
        printed += handle_upper_e_flags(va_arg(list, double),
                                        my_param.precision);
        printed += manage_space(printed, my_param);
    }
    return printed;
}

int flags_u(va_list list, params_t my_param)
{
    int printed = 0;
    int nb = va_arg(list, unsigned int);
    if (my_param.minus == 0) {
        printed += count_u(nb, my_param.precision);
        printed += manage_space(printed, my_param);
        my_put_nbr_u_and_precision(nb, my_param.precision);
    }
    if (my_param.minus == 1) {
        printed += manage_hash(my_param);
        printed += my_put_nbr_u_and_precision(nb, my_param.precision);
        printed += manage_space(printed, my_param);
    }
    return printed;
}

int flags_upper_s(va_list list, params_t my_param)
{
    char *str = va_arg(list, char*);
    int printed = 0;
    if (my_param.minus == 0) {
        printed += count_s_maj(str, my_param.precision);
        printed += manage_space(printed, my_param);
        display_s_flags(str, my_param.precision);
    }
    if (my_param.minus == 1) {
        printed += manage_hash(my_param);
        printed += display_s_flags(str, my_param.precision);
        printed += manage_space(printed, my_param);
    }
    return printed;
}

int flags_g(va_list list, params_t my_param)
{
    int printed = 0;
    double nb = va_arg(list, double);
    if (my_param.minus == 0) {
        printed += count_g(nb, my_param.precision);
        printed += manage_space(printed, my_param);
        printed += my_flags_g(nb, my_param.precision);
    }
    if (my_param.minus == 1) {
        printed += manage_hash(my_param);
        printed += my_flags_g(nb, my_param.precision);
        printed += manage_space(printed, my_param);
    }
    return 0;
}
