/*
** EPITECH PROJECT, 2022
** my string to number
** File description:
** jahaiu
*/

int my_convstrnb(char const *str, int nb)
{
    int bin = 1;
    int final = 0;
    if (str[nb] == '-') {
        bin = -1;
        nb += 1;
    }
    while ((str[nb] >= '0' && str[nb] <= '9')) {
        final = final * 10;
        final += str[nb] - '0';
        nb += 1;
    }
    final = final * bin;
    return final;
}
