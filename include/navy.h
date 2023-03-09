/*
** EPITECH PROJECT, 2023
** B-PSU-100-PAR-1-1-navy-paul.parisot
** File description:
** navy.h
*/

#ifndef B_PSU_100_PAR_1_1_NAVY_PAUL_PARISOT_NAVY_H
    #define B_PSU_100_PAR_1_1_NAVY_PAUL_PARISOT_NAVY_H

int my_convstrnb(char const *str, int nb);
int my_countstr(char *str);
void my_showstr(char *str);
int my_compstr(char *str1, char *str2);
char *my_dupstr(char *);
char *my_addchar(char *str, char c);
char **get_file(char *path);
int verify_position(const char *line);
int verify_line(char *line);
int navy_connection(int ac, char **av);
int navy_help(int ac, char **av);
int navy_game(int pid, int player, char **pos);

int message_attacker(int pid, char **dmap);
int message_defender(int pid, char **pos);

char *my_bin_convert(int nb, int bits);
int my_pow(int nb, int p);
int verify_postion(const char *attack, char **positions);
char **setup_map(char **pos);
int setup_boats(char **pos, char **map, int i);
int print_maps(char **, char **);
int is_win(char **amap);

#endif //B_PSU_100_PAR_1_1_NAVY_PAUL_PARISOT_NAVY_H
