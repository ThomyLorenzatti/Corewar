##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile to compile the lib
##

SRCL	=	$(wildcard *.c)

OBJ	=	$(SRCL:.c=.o)

LIB	=	libmy.a

all	:	lib

lib	:	$(OBJ)
	ar rsc $(LIB) $(OBJ)

clean	:
	rm -rf *.o
	@echo "\033[5m\033[3m\033[33mEtat for -> lib -> clean -> OK\033[0m"

fclean	:	clean
	rm -f *.a
	@echo "\033[5m\033[3m\033[33mEtat for -> lib -> fclean -> OK\033[0m"
	@echo "\033[5m\033[3m\033[33mEtat for -> include -> fclean -> OK\033[0m"

re	:	fclean all