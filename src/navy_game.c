/*
** EPITECH PROJECT, 2023
** B-PSU-100-PAR-1-1-navy-paul.parisot
** File description:
** game.c
*/

#include <unistd.h>
#include <signal.h>
#include "../include/message.h"
#include "../printf/include/functions.h"
#include "../include/navy.h"

void my_sig(int sig)
{
    if (sig == SIGUSR1)
        GLOBAL = 1;
    if (sig == SIGUSR2)
        GLOBAL = 2;
}

int my_get(void)
{
    int saved;

    if (signal(SIGUSR1, my_sig) == SIG_ERR ||
        signal(SIGUSR2, my_sig) == SIG_ERR)
        return 84;
    while (!GLOBAL);
    saved = GLOBAL;
    GLOBAL = 0;
    return saved;
}

int message_status(int status, int pid, char **amap, char **dmap)
{
    int ret = 0;

    GLOBAL = 0;
    if (status) {
        ret += message_attacker(pid, dmap);
        ret += message_defender(pid, amap);
        ret += my_get();
        if (kill(pid, is_win(amap) ? SIGUSR1 : SIGUSR2) == -1)
            return 84;
    } else {
        ret += message_defender(pid, amap);
        ret += message_attacker(pid, dmap);
        if (kill(pid, is_win(amap) ? SIGUSR1 : SIGUSR2) == -1)
            return 84;
        ret += my_get();
    }
    GLOBAL = 0;
    return ret;
}

int navy_game(int pid, int attacker, char **pos)
{
    char **amap = setup_map(pos);
    char **dmap = setup_map(NULL);
    int playing = 1;

    if (!amap || !dmap)
        return 84;
    while (playing) {
        print_maps(amap, dmap);
        if (attacker)
            playing = message_status(1, pid, amap, dmap);
        else
            playing = message_status(0, pid, amap, dmap);
        if (playing != 1 && playing != 2)
            return 84;
        playing = is_win(amap) && ((playing == 2) ? 0 : 1);
    }
    return 0;
}
