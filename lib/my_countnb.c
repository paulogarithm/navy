/*
** EPITECH PROJECT, 2022
** my_lib
** File description:
** my_countnb
*/

int my_countnb(int nb)
{
    int res = 0;
    while (nb > 0) {
        nb = nb - (nb % 10);
        nb = nb / 10;
        res += 1;
    }
    return res;
}
