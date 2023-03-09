/*
** EPITECH PROJECT, 2022
** my_lib
** File description:
** my_comparestr
*/

int my_countstr(char *str);

int my_compstr(char *str1, char *str2)
{
    if (my_countstr(str1) != my_countstr(str2)) {
        return 0;
    }
    int n = 0;
    while (n < my_countstr(str1)) {
        if (str1[n] != str2[n]) {
            return 0;
        }
        n += 1;
    }
    return 1;
}
