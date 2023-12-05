##
## EPITECH PROJECT, 2022
## Base MakeFile
## File description:
## Makefile
##

override FLAGS 		+= 	--exclude main.c --exclude tests --branches
override CPPFLAGS	=	-I ./include -W -Wall -Wextra -O2 -lncurses

SRC	=	src/my_sokoban.c	\
		src/count_func.c	\
		src/check_args.c	\
		src/key_action.c	\
		src/free.c			\
		src/check_box.c		\
		src/str_to_arr.c

TESTSRC = tests/test_errors.c \
		  tests/test_keyactions.c \
		  tests/test_free.c \
		  tests/test_others.c

MAIN =	main.c

MAIN_OBJ = $(MAIN:.c=.o)

SRC_OBJ = $(SRC:.c=.o)

NAME	= my_sokoban


all:	$(NAME)

$(NAME): $(MAIN_OBJ) $(SRC_OBJ)
	gcc -o $(NAME) $(SRC_OBJ) $(MAIN_OBJ) $(CPPFLAGS)

clean:
	rm -f *~
	rm -f *#
	rm -f *.o
	rm -f *.gc*
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

tests_compile:  CPPFLAGS += -lcriterion --coverage
tests_compile:  re $(TESTSRC)
	gcc -o unit_tests $(TESTSRC) $(SRC) $(CPPFLAGS)

tests_display:
	./unit_tests

tests_run: tests_compile tests_display

cover:
	gcovr --exclude tests
	gcovr --exclude tests --branches
	rm -f unit_tests*

htmlcover:
	mkdir -p html
	gcovr --html-details html/$(NAME).html $(FLAGS)

.PHONY: all clean fclean re run debug tests_compile tests_display tests_run \
cover htmlcover
