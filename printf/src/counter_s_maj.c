/*
** EPITECH PROJECT, 2022
** B-CPE-101-PAR-1-4-myprintf-merwan.korkmaz
** File description:
** counter_s_maj
*/

#include "../include/functions.h"
#include <stdio.h>

int count_s_maj(char const *str, int to_print)
{
    int i = 0;
    int printed = 0;
    if (to_print == 0) {
        to_print = my_strlen(str);
    }
    while (str[i] != '\0' && i < to_print) {
        if (str[i] >= 32 && str[i] < 127) {
            printed += 1;
        }
        if (str[i] < 32){
            printed += 2;
            printed += count_nbr_base(str[i], "01234567", 0);
        } if (str[i] >= 127) {
            printed += 1;
            printed += count_nbr_base(str[i], "01234567", 0);
        }
        i++;
    }
    return (printed);
}

int count_nbr_base(long nb, char *base, int to_print)
{
    int k = 0;
    int length = base_len(nb, base);
    if (to_print != 0 && to_print > length) {
        for (int i = 0; i < (length - to_print); i++)
            k += 1;
    }
    if (nb >= my_strlen(base)){
        k += count_nbr_base(nb / my_strlen(base), base, 0);
    }
    k += 1;
    return k;
}

int count_s(char *str, int precision)
{
    int to_print = 0;
    if (precision < my_strlen(str) && precision != 0)
        to_print += precision;
    if (precision > my_strlen(str) && precision != 0)
        to_print += my_strlen(str);
    if (precision == 0)
        to_print += my_strlen(str);
    return to_print;
}

int check_blank_plus(int d, params_t my_param)
{
    int i = 0;
    if (d > 0) {
        if (my_param.plus == 1) {
            i += my_putchar('+');
            my_param.blank = 0;
        }
        if (my_param.blank == 1)
            i += my_putchar(' ');
    }
    return i;
}
