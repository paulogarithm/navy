##
## EPITECH PROJECT, 2022
## radar
## File description:
## Makefile
##

CC	  = gcc
RM	  = rm -rf

LIB 	= lib/my_addchar.c\
		lib/my_addstr.c\
		lib/my_compstr.c\
		lib/my_convnbstr.c\
		lib/my_convstrnb.c\
		lib/my_countnb.c\
		lib/my_countstr.c\
		lib/my_dupstr.c\
		lib/my_isnb.c\
		lib/my_rand.c\
		lib/my_revstr.c\
		lib/my_showchar.c\
		lib/my_showstr.c\
		lib/my_scanf.c\


SRC		= src/navy_parsing.c\
		src/navy_connection.c\
		src/navy_help.c\
		src/navy_game.c\
		src/navy_usefull.c\
		src/maps.c\
		src/navy_attacker.c\
		src/navy_defender.c\

MAIN	= src/main.c\

SRCOBJ  = $(SRC:.c=.o)
LIBOBJ  = $(LIB:.c=.o)

BINNAME = navy
LIBNAME = lib$(BINNAME).a

CFLAGS  = -W -Wall -Wextra

all: build

build: $(LIBOBJ) $(SRCOBJ)
	make re -C printf/
	ar rc $(LIBNAME) $(LIBOBJ)
	gcc $(CFLAGS) $(MAIN) $(SRCOBJ) printf/libprintf.a -L. -lnavy -o $(BINNAME)

clean:
	$(RM) $(SRCOBJ)
	$(RM) $(LIBOBJ)
	$(RM) $(LIBNAME)
	$(RM) *.c~
	make clean -C printf/

fclean: clean
	make fclean -C printf/
	$(RM) $(BINNAME)

re: fclean build

pol: fclean build
	make clean

.PHONY:
	clean fclean re build all pol
