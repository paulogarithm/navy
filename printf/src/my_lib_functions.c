/*
** EPITECH PROJECT, 2022
** B-CPE-101-PAR-1-4-myprintf-merwan.korkmaz
** File description:
** my_lib_functions
*/

#include <stdio.h>
#include <unistd.h>
#include "../include/functions.h"

char *my_strcpy(char *dest, char const *src)
{
    int a = 0;

    while (src[a] != '\0') {
        dest[a] = src[a];
        a++;
    }
    dest[a] = '\0';
    return dest;
}

int my_strlen(char const *str)
{
    int s = 0;

    while (str[s] != '\0') {
        s = s + 1;
    }
    return s;
}

int my_putnbr_base(long nb, char *base, int to_print)
{
    int k = 0;
    int length = base_len(nb, base);
    if (to_print != 0 && to_print > length) {
        for (int i = 0; i < (to_print - length); i++)
            k += my_putchar('0');
    }
    if (nb >= my_strlen(base)){
        k += my_putnbr_base(nb / my_strlen(base), base, 0);
    }
    k += my_putchar(base[nb % my_strlen(base)]);
    return k;
}

int base_len(long nb, char *base)
{
    int k = 0;
    if (nb < 0) {
        k += 1;
        nb = -(nb);
    }
    if (nb >= my_strlen(base)){
        k += base_len(nb / my_strlen(base), base);
    }
    k += 1;
    return k;
}
