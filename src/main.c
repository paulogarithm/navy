/*
** EPITECH PROJECT, 2022
** my_lib
** File description:
** main
*/

#include <signal.h>
#include "../include/navy.h"

int main(int ac, char **av)
{
    if (navy_help(ac, av))
        return 0;
    if (ac != 2 && ac != 3)
        return 84;
    if (ac == 3 && my_convstrnb(av[1], 0) <= 0)
        return 84;
    if (ac == 3 && kill(my_convstrnb(av[1], 0), 0) == -1)
        return 84;
    return navy_connection(ac, av);
}
