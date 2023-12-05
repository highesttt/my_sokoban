##
## EPITECH PROJECT, 2022
## Base MakeFile
## File description:
## Makefile
##

SRC	=	src/my_sokoban.c	\
		src/count_func.c	\
		src/free.c	\
		src/key_action.c	\
		src/check_box.c		\
		src/str_to_arr.c

MAIN =	main.c

MAIN_OBJ = $(MAIN:.c=.o)

SRC_OBJ = $(SRC:.c=.o)

NAME	= my_sokoban-bonus

CPPFLAGS =	-I ./include -W -Wall -Wextra -O2 -lncurses

all:	$(NAME)

$(NAME): $(MAIN_OBJ) $(SRC_OBJ)
	gcc -o $(NAME) $(SRC_OBJ) $(MAIN_OBJ) $(CPPFLAGS)

clean:
	rm -f *~
	rm -f *#
	rm -f *.o
	rm -f src/*.o
	rm -f a.out

fclean: clean
	rm -f $(NAME)

re: fclean all

run: re
	@-make clean
	@-echo ""
	@-echo ""
	@-echo ""
	@-echo ""
	@-echo ""
	@-echo ""
	@-echo ""
	@-echo ""
	@-echo ""
	@-echo ""
	@-echo ""
	@-echo ""
	@-echo ""
	@-echo ""
	@-echo ""
	@-echo ""
	@-echo ""
	@-echo ""
	@-echo ""
	@-echo ""
	@-echo ""
	@-echo ""
	@-echo ""
	@-echo ""
	@-echo ""
	@-echo ""
	@-echo ""
	@-echo ""
	@-echo ""
	@-echo ""
	@-echo ""
	@-echo ""
	@-echo ""
	@-echo ""
	@-echo ""
	@-echo ""
	@-echo ""
	@-echo ""
	@-echo ""
	@-echo ""
	@-echo "------------------------ Running $(NAME) ------------------------"
	@-./$(NAME) maps/map

debug: CPPFLAGS += -g
debug: re

.PHONY: all clean fclean re run debug
