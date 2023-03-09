/*
** EPITECH PROJECT, 2022
** my_lib
** File description:
** my_showstr
*/

void my_showchar(char c);

void my_showstr(char *str)
{
    int n = 0;
    while (str[n] != '\0') {
        my_showchar(str[n]);
        n += 1;
    }
    return;
}
