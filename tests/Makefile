##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile to compile criterion tests
##

NAME_T	=	unit_tests

TESTS_SRC	=	./tests_even_more_flags.c	\
				./tests_even_more.c	\
				./tests_flags.c	\
				./tests_lib.c	\
				./tests_many_flags.c	\
				./tests_more_flags.c	\
				./tests_print.c	\
				./tests_so_many_flags.c	\
				./tests_some_flags.c	\

CC	=	gcc

RM	 =	rm -f

CFLAGS	=	-Wall -Wextra -W

TESTFLAG	=	--coverage -lcriterion -I../include -L../lib -lmy

all:	tests_run

clean:
	@echo "\033[5m\033[3m\033[33mEtat for -> $(NAME_T) -> clean -> OK\033[0m"

tests_run:
	$(CC) $(SRC_T) $(TESTS_SRC) $(CFLAGS) $(TESTFLAG) -o $(NAME_T)
	./$(NAME_T)
	@echo "\033[5m\033[3m\033[33mEtat for -> $(NAME_T) -> working -> OK\033[0m"

fclean:
	@$(RM) $(NAME_T)
	@$(RM) *.gcda *.gcno
	@echo "\033[5m\033[3m\033[33mEtat for -> $(NAME_T) -> fclean -> OK\033[0m"

re:	fclean all