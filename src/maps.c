/*
** EPITECH PROJECT, 2023
** B-PSU-100-PAR-1-1-navy-paul.parisot
** File description:
** maps
*/

#include <malloc.h>
#include "../printf/include/functions.h"
#include "../include/navy.h"

int verify_postion(const char *attack, char **map)
{
    if (map[attack[1] - '1'][attack[0] - 'A'] <= '5' &&
        map[attack[1] - '1'][attack[0] - 'A'] >= '2') {
        map[attack[1] - '1'][attack[0] - 'A'] = 'x';
        return 1;
    }
    if (map[attack[1] - '1'][attack[0] - 'A'] == '.') {
        map[attack[1] - '1'][attack[0] - 'A'] = 'o';
    }
    return 0;
}

char **setup_map(char **pos)
{
    char **map = malloc(sizeof(char *) * 9);

    if (!map)
        return NULL;
    for (int i = 0; i < 9; i++) {
        map[i] = malloc(sizeof(char *) * 9);
        if (!map[i])
            return NULL;
    }
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++)
            map[i][j] = '.';
        map[i][8] = '\0';
    }
    if (pos != NULL)
        for (int i = 0; i < 4; i++) {
            setup_boats(pos, map, i);
        }
    map[8] = NULL;
    return map;
}

int setup_boats(char **pos, char **map, int i)
{
    if (pos[i][2] == pos[i][5]) {
        for (int j = 0; j <= (pos[i][6] - pos[i][3]); j++) {
            map[j + (pos[i][3] - '0') - 1][(pos[i][2] - 'A')] = pos[i][0];
        }
    }
    if (pos[i][3] == pos[i][6]) {
        for (int j = 0; j <= (pos[i][5] - pos[i][2]); j++) {
            map[(pos[i][3] - '0') - 1][j + (pos[i][2] - 'A')] = pos[i][0];
        }
    }
    return 0;
}

int print_maps(char **amap, char **dmap)
{
    my_printf("\nmy positions:\n");
    my_printf(" |A B C D E F G H\n");
    my_printf("-+---------------\n");
    for (int i = 0; i < 8; i++) {
        my_printf("%d|%c", i + 1, amap[i][0]);
        for (int j = 1; j < 8; j++)
            my_printf(" %c", amap[i][j]);
        my_printf("\n");
    }
    my_printf("\nenemy's positions:\n");
    my_printf(" |A B C D E F G H\n");
    my_printf("-+---------------\n");
    for (int i = 0; i < 8; i++) {
        my_printf("%d|%c", i + 1, dmap[i][0]);
        for (int j = 1; j < 8; j++)
            my_printf(" %c", dmap[i][j]);
        my_printf("\n");
    }
    return 0;
}

int is_win(char **amap)
{
    int err = 0;

    for (int i = 0; !err && i < 8; i++) {
        for (int j = 0; !err && j < 8; j++) {
            err = (amap[i][j] >= '0' && amap[i][j] <= '9') ? 1 : 0;
        }
    }
    return err;
}
