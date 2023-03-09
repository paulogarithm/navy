/*
** EPITECH PROJECT, 2022
** printf
** File description:
** my_flags_S
*/

#include "../include/functions.h"

int display_s_flags(char const *str, int to_print)
{
    int i = 0;
    int printed = 0;
    if (to_print == 0) {
        to_print = my_strlen(str);
    }
    while (str[i] != '\0' && i < to_print) {
        if (str[i] >= 32 && str[i] < 127) {
            printed += my_putchar(str[i]);
        }
        if (str[i] < 32){
            printed += my_putstr("\\0");
            printed += my_putnbr_base(str[i], "01234567", 0);
        } if (str[i] >= 127) {
            printed += my_putstr("\\");
            printed += my_putnbr_base(str[i], "01234567", 0);
        }
        i++;
    }
    return (printed);
}
