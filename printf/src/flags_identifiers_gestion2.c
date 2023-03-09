/*
** EPITECH PROJECT, 2022
** my_printf_
** File description:
** flags_identifiers_gestion2
*/

#include "../include/functions.h"

int count_hash(params_t my_param)
{
    if (my_param.hash == 1 && my_param.identifier == 'o')
        return 1;
    if (my_param.hash == 1 && my_param.identifier == 'x')
        return 2;
    if (my_param.hash == 1 && my_param.identifier == 'X')
        return 2;
    return 0;
}

int manage_space(int printed, params_t param)
{
    int print = 0;
    int to_print = param.spaces - printed;
    if (param.zero == 0 && param.minus == 0 && to_print > 0){
        for (int i = 0; i < to_print; i++)
            print += my_putchar(' ');
        print += manage_hash(param);
    }
    if (param.zero == 1 && param.minus == 0 && to_print > 0){
            print += manage_hash(param);
        for (int i = 0; i < to_print; i++)
            print += my_putchar('0');
    }
    if (param.zero == 0 && param.minus == 1 && to_print > 0){
        for (int i = 0; i < to_print; i++)
            print += my_putchar(' ');
    }
    return print;
}
