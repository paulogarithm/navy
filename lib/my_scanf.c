/*
** EPITECH PROJECT, 2023
** my_messaging
** File description:
** my_scanf
*/

#include <stdlib.h>
#include <unistd.h>

char *my_addchar(char *str, char c);
void my_showstr(char *str);

char *my_scanf(char *what_to_say)
{
    char *buff;
    char *str = "";
    int r;

    my_showstr(what_to_say);
    while (1) {
        buff = malloc(sizeof(char) * 2);
        r = read(2, buff, 1);
        if (r < 0 || buff[0] == '\n')
            break;
        str = my_addchar(str, buff[0]);
    }
    return str;
}
