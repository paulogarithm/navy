/*
** EPITECH PROJECT, 2022
** my_lib
** File description:
** my_countstr
*/

int my_countstr(char *str)
{
    int n = 0;
    while (str[n] != '\0') n += 1;
    return n;
}
