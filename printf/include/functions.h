/*
** EPITECH PROJECT, 2022
** B-CPE-101-PAR-1-4-myprintf-merwan.korkmaz
** File description:
** functions
*/

#include <stdarg.h>

#ifndef FUNCTIONS_H_
    #define FUNCTIONS_H_

typedef struct params_s {
    int zero;
    int minus;
    int hash;
    int plus;
    int blank;
    int precision;
    int spaces;
    char identifier;
    int written;
}params_t;

void redirect_all_std(void);

int my_putchar(char c);
int my_putstr(char const *str);
int my_put_nbr(int nb);
int my_strlen(char const *str);
int my_putnbr_base(long nb, char *base, int to_print);
int my_printf(char *str, ...);
int get_identifiers(char *str, va_list args);
int associate_identifier(char str, va_list args, params_t my_param);
int get_numbers(char *flags, int l);
int getflags(char *str, va_list arg, int *i, int charwritten);
int my_put_float(double nb, int to_print);
int identifier(char c);
int cmpstring(char *str, va_list args);
int is_num(char c);
int put_error(int count, char *str);
int manage_params(params_t my_param, va_list args);
int manage_hash(params_t my_param);
int count_hash(params_t my_param);
int manage_no_minus(params_t my_param, va_list args);
int flags_p(va_list list, params_t my_param);
int flags_b(va_list list, params_t my_param);
int flags_x(va_list list, params_t my_param);
int flags_x_maj(va_list list, params_t my_param);
int flags_o(va_list list, params_t my_param);
int flags_s(va_list list, params_t my_param);
int flags_i(va_list list, params_t my_param);
int flags_d(va_list list, params_t my_param);
int flags_c(va_list list, params_t my_param);
int flags_f(va_list list, params_t my_param);
int flags_e(va_list list, params_t my_param);
int flags_upper_e(va_list list, params_t my_param);
int flags_u(va_list list, params_t my_param);
int flags_upper_s(va_list list, params_t my_param);
int flags_upper_g(va_list list, params_t my_param);
int flags_g(va_list list, params_t my_param);
int flags_n(va_list list, params_t my_param);
int handle_e_flags(double nb, int to_print);
int display_in_scientific_notation_negative(double nb, int to_print);
int display_in_scientific_notation_positive(double nb, int to_print);
int handle_upper_e_flags(double nb, int to_print);
int display_in_scientific_notation_negative_upper(double nb, int to_print);
int display_in_scientific_notation_positive_upper(double nb, int to_print);
int display_s_flags(char const *str, int to_print);
int my_putstr_and_precision(char const *str, int to_print);
int my_intlen(unsigned int nb);
int my_put_nbr_and_precision(int nb, int to_print);
int my_put_nbr_u_and_precision(unsigned int nb, int to_print);
int my_put_decimal(int nb, int to_print);
int base_len(long nb, char *base);
int manage_space(int printed, params_t param);
int count_in_scientific_notation_positive(double nb, int to_print);
int count_in_scientific_notation_negative(double nb, int to_print);
int count_f(double nb, int to_print);
int my_count_decimal(int nb, int to_print);
int count_e(double nb, int to_print);
int count_u(unsigned int nb, int to_print);
int count_s_maj(char const *str, int to_print);
int count_nbr_base(long nb, char *base, int to_print);
int count_s(char *str, int precision);
int check_blank_plus(int d, params_t my_param);
int count_i(int nb, params_t param);
int my_flags_g(double nb, int to_print);
int my_flags_upper_g(double nb, int to_print);
int count_g(double nb, int to_print);
int count_f_g(double nb, int to_print);
int check_precision_float(int to_print, int decimals);

char *my_strncpy(char *dest, char const *src, int n);
char *my_strcpy(char *dest, char const *src);

params_t get_some_flags(char c, params_t my_param);
params_t count_identifiers_flags(char *str, params_t params,
                                int *i, int charwritten);
params_t is_n(int charwritten, params_t param);

#endif /* !FUNCTIONS_H_ */
