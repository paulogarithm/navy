/*
** EPITECH PROJECT, 2022
** my_lib
** File description:
** my_crackcode
*/
#include <stdio.h>

char *my_addchar(char *str, char c);
int my_countstr(char *str);

char *my_crackcode(char *code)
{
    char *awnser = "";

    int begin = 33;
    int end = 126;

    int status = 1;

    for (int a = begin; a < end; a ++) {
        awnser = my_addchar(awnser, a);
        awnser = "";
    }

    return awnser;
}
