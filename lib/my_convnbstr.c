/*
** EPITECH PROJECT, 2022
** my_lib
** File description:
** my_convnbstr
*/

char *my_addchar(char *str, char c);
char *my_revstr(char *str);
int my_countnb(int nb);

char *my_convnbstr(int nb)
{
    char *str = "";
    int neg = 0;

    if (nb == 0) return "0";
    if (nb < 0) {
        neg = 1;
        nb *= -1;
    }
    int tmp = nb;
    for (int i = 0; i < my_countnb(tmp); i ++) {
        str = my_addchar(str, nb % 10 + '0');
        nb = nb / 10;
    }
    if (neg) str = my_addchar(str, '-');
    str = my_revstr(str);
    return str;
}
