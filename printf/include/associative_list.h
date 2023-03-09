/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** associative_list
*/
#include <stddef.h>
#include <stdarg.h>
#include "functions.h"

#ifndef ASSOCIATIVE_LIST_H_
    #define ASSOCIATIVE_LIST_H_

typedef int (*ptr_fc_t)(va_list, params_t);
typedef int (*ptr_fc_hash_t)(char const *);

typedef struct associative_list_s {
    char identifier;
    ptr_fc_t function;
} associative_list_t;

static const associative_list_t FUNCTIONS_ASSOC[18] = {
    {'c', flags_c},
    {'d', flags_d},
    {'i', flags_i},
    {'s', flags_s},
    {'b', flags_b},
    {'o', flags_o},
    {'p', flags_p},
    {'x', flags_x},
    {'X', flags_x_maj},
    {'f', flags_f},
    {'e', flags_e},
    {'E', flags_upper_e},
    {'u', flags_u},
    {'F', flags_f},
    {'S', flags_upper_s},
    {'G', flags_upper_g},
    {'g', flags_g},
    {'n', flags_n}
};

static const int NB_ID = 19;
static const int NB_FLAGS = 15;
static const char IDS[20] = "cdisSbopxXfFeEuGgn%";
static const char FLAGS[18] = "-+#0123456789.lhL";

#endif /* !ASSOCIATIVE_LIST_H_ */
