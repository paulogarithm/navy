/*
** EPITECH PROJECT, 2023
** navy_final
** File description:
** navy_errorcase
*/

#include <stdlib.h>

#include "../include/navy.h"

int navy_help(int ac, char **av)
{
    int n = 0;

    if (ac != 2)
        return 0;
    if (!my_compstr(av[1], "-h"))
        return 0;
    char *messages[] = {
        "\nUSAGE\n",
        "\t./navy [first_player_pid] navy_positions\n\n",
        "DESCRIPTION\n",
        "\tfirst_player_pid: only for the 2nd player. pid of the first ",
        "player.\n",
        "\tnavy_positions: file representing the positions of the ships.\n\n",
        NULL
    };
    while (messages[n] != NULL) {
        my_showstr(messages[n]);
        n += 1;
    }
    return 1;
}
