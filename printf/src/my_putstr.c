/*
** EPITECH PROJECT, 2022
** my_putstr
** File description:
** shows a string
*/

#include <stdio.h>
#include "../include/functions.h"

int my_putstr(char const *str)
{
    int i = 0;
    while (str[i] != '\0') {
        my_putchar(str[i]);
        i++;
    }
    return (i);
}

int my_putstr_and_precision(char const *str, int to_print)
{
    int i = 0;
    if (to_print == 0)
        return my_putstr(str);
    while (str[i] != '\0' && i < to_print) {
        my_putchar(str[i]);
        i++;
    }
    return (i);
}
