/*
** EPITECH PROJECT, 2023
** navy_pingpong
** File description:
** navy_usefull
*/

char *my_addchar(char *str, char c);

int my_pow(int nb, int p)
{
    if (p < 0)
        return 0;
    if (p == 0)
        return 1;
    if (p > 1)
        nb = nb * my_pow(nb, p - 1);
    return nb;
}

char *my_bin_convert(int nb, int bits)
{
    char *str = "";
    while (bits) {
        if (nb >= my_pow(2, bits - 1)) {
            str = my_addchar(str, '1');
            nb -= my_pow(2, bits - 1);
        } else {
            str = my_addchar(str, '0');
        }
        bits -= 1;
    }
    return str;
}
