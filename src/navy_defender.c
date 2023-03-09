/*
** EPITECH PROJECT, 2023
** navy_final
** File description:
** navy_defender
*/

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

#include "../include/message.h"
#include "../printf/include/functions.h"
#include "../include/navy.h"

void get_sigs_df(int signal)
{
    if (signal == SIGUSR1)
        GLOBAL = 1;
    if (signal == SIGUSR2)
        GLOBAL = 2;
}

int message_defender_send(int pid, int resp)
{
    while (!GLOBAL);
    GLOBAL = 0;
    if (kill(pid, resp ? SIGUSR1 : SIGUSR2) == -1)
        return 84;
    return 0;
}

int message_defender_get(int pid)
{
    int count = 0;
    int nb = 0;

    while (count < 3) {
        while (!GLOBAL);
        count += 1;
        nb += (GLOBAL == 1 ? 1 : 0) * my_pow(2, (3 - count));
        GLOBAL = 0;
        if (kill(pid, SIGUSR1) == -1)
            return -1;
    }
    GLOBAL = 0;
    return nb;
}

int message_defender(int pid, char **pos)
{
    int nb;
    char *str = "";
    int hit;
    int error = 0;

    GLOBAL = 0;
    if (signal(SIGUSR1, get_sigs_df) == SIG_ERR)
        return 84;
    if (signal(SIGUSR2, get_sigs_df) == SIG_ERR)
        return 84;
    my_printf("\nwaiting for enemy's attack... \n");
    if ((nb = message_defender_get(pid)) == -1)
        return 84;
    str = my_addchar(str, (char) (nb + 'A'));
    if ((nb = message_defender_get(pid)) == -1)
        return 84;
    str = my_addchar(str, (char) (nb + '1'));
    hit = verify_postion(str, pos);
    my_printf("%s: %s\n", str, hit ? "hit" : "missed");
    return (error + message_defender_send(pid, hit));
}
