/*
** EPITECH PROJECT, 2022
** B-CPE-101-PAR-1-4-myprintf-merwan.korkmaz
** File description:
** my_put_nbr
*/

#include <stdio.h>
#include <unistd.h>
#include "../include/functions.h"

int my_put_nbr(int nb)
{
    int count = 0;
    if (nb == -2147483648) {
        write(1, "-2147483648", 11);
        return 11;
    }
    if (nb < 0) {
        write(1, "-", 1);
        nb = -(nb);
        count += 1;
    }
    if (nb >= 10)
        count += my_put_nbr(nb / 10);
    count += my_putchar(nb % 10 + '0');
    return count;
}

int my_intlen(unsigned int nb)
{
    int i = 0;
    while (nb != 0) {
        nb = nb / 10;
        i += 1;
    }
    return i;
}

int my_put_nbr_and_precision(int nb, int to_print)
{
    int count = 0;
    if (my_intlen(nb) < to_print && to_print != 0){
        for (int i = 0; i < (to_print - my_intlen(nb)); i++)
            count += my_putchar('0');
    }
    if (nb == -2147483648) {
        write(1, "-2147483648", 11);
        return 11;
    }
    if (nb < 0) {
        write(1, "-", 1);
        nb = -(nb);
        count += 1;
    }
    if (nb >= 10)
        count += my_put_nbr(nb / 10);
    count += my_putchar(nb % 10 + '0');
    return count;
}

int my_put_nbr_u_and_precision(unsigned int nb, int to_print)
{
    int count = 0;
    if (my_intlen(nb) < to_print){
        for (int i = 0; i < (my_intlen(nb) - to_print); i++)
            count += my_putchar('0');
    }
    if (nb >= 10)
        count += my_put_nbr(nb / 10);
    count += my_putchar(nb % 10 + '0');
    return count;
}
