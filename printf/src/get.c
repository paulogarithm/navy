/*
** EPITECH PROJECT, 2022
** my_printf_
** File description:
** get
*/

#include "../include/functions.h"
#include "../include/associative_list.h"
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

int getflags(char *str, va_list arg, int *i, int charwritten)
{
    int count = 0;
    params_t my_params = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    my_params = count_identifiers_flags(str + 1, my_params,
                                        &count, charwritten);
    if (count == 1 && my_params.identifier != 0) {
        *i += count;
        return associate_identifier(my_params.identifier, arg, my_params);
    }
    if (count >= 2 && my_params.identifier != 0) {
        *i += count;
        return manage_params(my_params, arg);
    } else {
        put_error(count, str);
        *i += count;
        return -1;
    }
    return 0;
}

int identifier(char c)
{
    for (int i = 0; i < NB_ID; i++) {
        if (IDS[i] == c)
            return 1;
    }
    return 0;
}

int get_precision(char *str, int *i)
{
    *i += 1;
    int sum = 0;
    while (is_num(str[*i]) == 1) {
        sum = sum * 10 + (str[*i] - 48);
        *i += 1;
    }
    return sum;
}

params_t count_identifiers_flags(char *str, params_t my_param,
                                int *i, int charwritten)
{
    int l = my_strlen(str);
    while (my_param.identifier == 0 && *i < l) {
        if (identifier(str[*i]))
            my_param.identifier = str[*i];
        if (str[*i] == '0' && is_num(str[*i - 1]) == 0)
            my_param.zero = 1;
        if (str[*i] == '.') {
            my_param.precision = get_precision(str, &*i);
            *i -= 1;
        }
        if (is_num(str[*i]) == 1 && str[*i] != '0' && my_param.precision == 0)
            my_param.spaces = my_param.spaces * 10 + (str[*i] - 48);
        if (str[*i] == '0' && is_num(str[*i - 1]) == 1
            && my_param.precision == 0)
            my_param.spaces = my_param.spaces * 10;
        my_param = is_n(charwritten, my_param);
        my_param = get_some_flags(str[*i], my_param);
        *i += 1;
    }
    return my_param;
}

params_t is_n(int charwritten, params_t param)
{
    if (param.identifier == 'n') {
        param.written = charwritten;
    }
    return param;
}
