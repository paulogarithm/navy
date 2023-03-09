##
## EPITECH PROJECT, 2022
## my_printf
## File description:
## Makefile for my_printfile
##

RM	=	rm -f

CC	=	gcc

SRC	=	./src/functions.c\
		./src/my_printf.c\
		./src/my_put_nbr.c\
		./src/my_putchar.c\
		./src/my_putstr.c\
		./src/my_lib_functions.c\
		./src/strncpy.c\
		./src/my_basic_print_flags.c\
		./src/get.c\
		./src/flags_identifiers_gestion.c\
		./src/flags_identifiers_gestion2.c\
		./src/my_put_float.c\
		./src/my_e_flags.c\
		./src/my_e_upper_flags.c\
		./src/print_flags.c\
		./src/my_flags_s_maj.c\
		./src/counters.c\
		./src/counter_u.c\
		./src/counter_s_maj.c\
		./src/my_flags_g.c\
		./src/other_flags.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-Wall -Wextra -Werror

NAME	=	libprintf.a

NAME_TESTS	=	unit_tests

UNIT_TEST_LIB	=	-lcriterion --coverage

all: $(NAME)

$(NAME): $(OBJ)
	ar rc -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)
	$(RM) *.c~
	$(RM) *.gc*

fclean: clean
	$(RM) $(NAME)
	$(RM) $(NAME_TESTS)
	$(RM) a.out

re: fclean all clean
