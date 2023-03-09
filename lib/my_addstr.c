/*
** EPITECH PROJECT, 2022
** my_lib
** File description:
** my_addstr
*/

char *my_addchar(char *str, char c);
int my_countstr(char *str);

char *my_addstr(char *first, char *second)
{
    int n = 0;
    while (n < my_countstr(second)) {
        first = my_addchar(first, second[n]);
        n += 1;
    }
    return first;
}
