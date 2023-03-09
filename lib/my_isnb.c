/*
** EPITECH PROJECT, 2022
** pushwap_final
** File description:
** my_isnumber
*/

int my_isnb(char *str)
{
    int n = 0;
    while (str[n] != '\0') {
        if ((str[n] < '0' || str[n] > '9') && str[n] != '-') {
            return 0;
        }
        n += 1;
    }
    return 1;
}
