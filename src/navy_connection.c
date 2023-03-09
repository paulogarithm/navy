/*
** EPITECH PROJECT, 2022
** my_navy
** File description:
** main
*/

#include <signal.h>
#include <unistd.h>

#include "../include/message.h"
#include "../include/navy.h"
#include "../printf/include/functions.h"

void connect_pid(int a, siginfo_t *info, void *b)
{
    (void)a;
    (void)b;
    GLOBAL = info->si_pid;
}

int player_hosting(void)
{
    struct sigaction action;
    action.sa_flags = SA_SIGINFO;
    action.sa_sigaction = connect_pid;
    if (sigaction(SIGUSR1, &action, NULL) == -1)
        return 84;
    my_printf("waiting for enemy connection...\n\n");
    return 1;
}

int player_joining(char *text)
{
    GLOBAL = my_convstrnb(text, 0);
    if (kill(GLOBAL, SIGUSR1) == -1)
        return -1;
    return 0;
}

int navy_connection(int ac, char **av)
{
    char *file_path = ac == 2 ? av[1] : av[2];
    char **buffer = NULL;
    int player;

    buffer = get_file(file_path);
    if (buffer == NULL)
        return 84;
    my_printf("my_pid: %d\n", getpid());
    if (ac == 2)
        player = player_hosting();
    if (ac == 3)
        player = player_joining(av[1]);
    if (player == -1)
        return 84;
    while (!GLOBAL);
    if (player)
        my_printf("enemy connected\n");
    if (!player)
        my_printf("successfully connected\n");
    return navy_game(GLOBAL, player, buffer);;
}
