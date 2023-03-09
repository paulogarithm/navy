/*
** EPITECH PROJECT, 2022
** my_lib
** File description:
** my_addchar
*/

#include <stdlib.h>

char *my_dupstr(char *src);
int my_countstr(char *str);

char *my_addchar(char *str, char c)
{
    char *tmp = my_dupstr(str);
    int size = my_countstr(str) + 2;

    str = malloc(sizeof(char) * size);
    if (!str)
        return NULL;
    int n = 0;
    while (tmp[n] != '\0') {
        str[n] = tmp[n];
        n += 1;
    }
    str[n] = c;
    str[n + 1] = '\0';
    free(tmp);

    return str;
}
