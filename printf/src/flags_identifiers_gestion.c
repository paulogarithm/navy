/*
** EPITECH PROJECT, 2022
** my_printf_
** File description:
** flags_identifiers_gestion
*/

#include "../include/functions.h"

int is_num(char c)
{
    if (c >= '0' && c <= '9')
        return 1;
    else
        return 0;
}

int put_error(int count, char *str)
{
    my_putchar('%');
    for (int j = 1; j <= count; j++) {
        my_putchar(str[j]);
    }
    return 0;
}

int manage_params(params_t my_param, va_list args)
{
    int printed = 0;
    printed += associate_identifier(my_param.identifier, args, my_param);
    return printed;
}

params_t get_some_flags(char c, params_t my_param)
{
    if (c == ' ')
        my_param.blank = 1;
    if (c == '#')
        my_param.hash = 1;
    if (c == '-')
        my_param.minus = 1;
    if (c == '+')
        my_param.plus = 1;
    return my_param;
}

int manage_hash(params_t my_param)
{
    if (my_param.hash == 1 && my_param.identifier == 'o') {
        my_putchar('0');
        return 1;
    }
    if (my_param.hash == 1 && my_param.identifier == 'x') {
        my_putstr("0x");
        return 2;
    }
    if (my_param.hash == 1 && my_param.identifier == 'X') {
        my_putstr("0X");
        return 2;
    }
    return 0;
}
