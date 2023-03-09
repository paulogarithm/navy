/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** my_printf
*/

#include <stdio.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>
#include "../include/associative_list.h"

int associate_identifier(char str, va_list args, params_t my_param)
{
    int printed = 0;
    if (str == '%') {
        printed += my_putchar('%');
    }
    for (int i = 0; i < NB_ID; i++) {
        if (FUNCTIONS_ASSOC[i].identifier == str) {
            printed += FUNCTIONS_ASSOC[i].function(args, my_param);
        }
    }
    return printed;
}

int check_char(char *tmp, int *i, int *charwritten, va_list args)
{
    if (tmp[*i] != '%' && tmp[*i] != '\0') {
        my_putchar(tmp[*i]);
        *charwritten += 1;
    }
    if (tmp[*i] == '%') {
        int n = getflags((tmp + (*i)), args, &*i, *charwritten);
        if (n == -1)
            *charwritten = -1;
        else
            *charwritten += n;
    }
    return 0;
}

int cmpstring(char *str, va_list args)
{
    int charwritten = 0;
    int len = my_strlen(str);
    int error = 0;
    for (int i = 0; i <= len; i++) {
        check_char(str, &i, &charwritten, args);
        if (charwritten == -1)
            error = 1;
    }
    if (error == 1)
        charwritten = 84;
    return charwritten;
}

int my_printf(char *str, ...)
{
    va_list args;
    va_start(args, str);
    int length = my_strlen(str);
    int c = 0;

    if (length == 0)
        return 0;
    if (length == 1) {
        my_putchar(str[0]);
        return 1;
    }
    c = cmpstring(str, args);
    va_end(args);
    return c;
}
