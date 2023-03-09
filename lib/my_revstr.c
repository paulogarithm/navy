/*
** EPITECH PROJECT, 2022
** my_lib
** File description:
** my_revstr
*/

int my_countstr(char *str);
char *my_dupstr(char *src);

char *my_revstr(char *origin)
{
    char *str = my_dupstr(origin);
    int i = 0;
    int j = my_countstr(str) - 1;
    while (j > i) {
        char tmp = str[i];
        str[i] = str[j];
        str[j] = tmp;
        i ++;
        j --;
    }
    return str;
}
