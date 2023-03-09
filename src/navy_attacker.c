/*
** EPITECH PROJECT, 2023
** navy_final
** File description:
** navy_attacker
*/

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

#include "../include/message.h"
#include "../printf/include/functions.h"
#include "../include/navy.h"

char *my_scanf(char *str);

int set_dmap(char **dmap, char *pos, int hit)
{
    if (hit == 1 && dmap[pos[1] - '1'][pos[0] - 'A'] == '.')
        dmap[pos[1] - '1'][pos[0] - 'A'] = 'x';
    if (hit == 2 && dmap[pos[1] - '1'][pos[0] - 'A'] == '.')
        dmap[pos[1] - '1'][pos[0] - 'A'] = 'o';
    return 0;
}

void get_sigs_at(int signal)
{
    if (signal == SIGUSR1)
        GLOBAL = 1;
    if (signal == SIGUSR2)
        GLOBAL = 2;
}

int message_attacker_send(int pid, int sending)
{
    char *str;

    str = my_bin_convert(sending, 3);
    for (int i = 0; i < 3; i ++) {
        GLOBAL = 0;
        if (kill(pid, str[i] == '1' ? SIGUSR1 : SIGUSR2) == -1)
            return 84;
        if (signal(SIGUSR1, get_sigs_at) == SIG_ERR)
            return 84;
        while (!GLOBAL);
    }
    GLOBAL = 0;
    return 0;
}

int message_attacker_get(int pid, char *buff, char **dmap)
{
    if (signal(SIGUSR1, get_sigs_at) == SIG_ERR)
        return 84;
    if (signal(SIGUSR2, get_sigs_at) == SIG_ERR)
        return 84;
    if (kill(pid, SIGUSR1) == -1)
        return 84;
    while (!GLOBAL);
    my_printf("%s: %s\n", buff, GLOBAL == 1 ? "hit" : "missed");
    set_dmap(dmap, buff, GLOBAL);
    GLOBAL = 0;
    return 0;
}

int message_attacker(int pid, char **dmap)
{
    GLOBAL = 0;
    char *buff = NULL;
    int letter;
    int number;
    int error = 0;
    do {
        buff = my_scanf("\nattack: ");
        letter = buff[0] - 'a';
        number = buff[1] - '1';
        letter = letter < 0 || letter > 7 ? buff[0] - 'A' : letter;
    } while (letter < 0 || letter > 7 || number < 0 || number > 7);
    error += message_attacker_send(pid, letter);
    error += message_attacker_send(pid, number);
    return (error + message_attacker_get(pid, buff, dmap));
}
