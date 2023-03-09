/*
** EPITECH PROJECT, 2023
** B-PSU-100-PAR-1-1-navy-paul.parisot
** File description:
** parsing.c
*/

#include "../include/navy.h"
#include "../printf/include/functions.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

char **get_file(char *path)
{
    const int to_read = 8;
    char **map = malloc(4 * sizeof (char));
    ssize_t err;
    int fd = open(path, O_RDONLY);

    if (fd == -1 || !map)
        return NULL;
    for (int i = 0; i < 4; i++) {
        map[i] = malloc(sizeof (char) * to_read);
        if (!map[i])
            return NULL;
        err = read(fd, map[i], to_read);
        if (err != to_read && err != 7 && err != 0)
            return NULL;
        err = (err == to_read) ? err - 1 : err;
        map[i][err] = '\0';
        if (!verify_line(map[i]))
            return NULL;
    }
    return map;
}

int verify_line(char *line)
{
    static int sizes[4] = {0, 0, 0, 0};
    int boat_size = line[0] - '0';

    if (sizes[0] && sizes[1] && sizes[2] && sizes[3])
        return 0;
    if (boat_size < 2 || boat_size > 5)
        return 0;
    for (int i = 0; i < 4; i++) {
        if (boat_size == i + 2 && sizes[i])
            return 0;
        if (boat_size == i + 2 && !sizes[i] && verify_position(line))
            sizes[i] = 1;
        if (boat_size == i + 2 && !sizes[i] && !verify_position(line))
            return 0;
    }
    return 1;
}

int verify_position(const char *line)
{
    if (line[2] < 'A' || line[2] > 'H' || line[5] < 'A' || line[5] > 'H')
        return 0;
    if (line[6] < '0' || line[6] > '8' || line[3] < '0' || line[3] > '8')
        return 0;
    if (line[2] == line[5] && (line[6] - line[3]) + 1 == line[0] - '0')
        return 1;
    if (line[3] == line[6] && line[5] - line[2] + 1 == line[0] - '0')
        return 1;
    return 0;
}
