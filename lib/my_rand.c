/*
** EPITECH PROJECT, 2022
** my_lib
** File description:
** my_genrand
*/

#include <time.h>
#include <stdlib.h>

char *my_addchar(char *str, char c);

int my_randint(int a, int b)
{
    return a + (rand() % (a - b));
}

char *my_randstr(int nb)
{
    char *str = "";
    for (int n = 0; n < nb; n ++) {
        str = my_addchar(str, my_randint(33, 126));
    }
    return str;
}

void my_rand_init(void)
{
    srand(time(NULL));
    return;
}
