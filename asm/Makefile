##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile to compile the project
##

CC	=	gcc

RM	=	rm -f

SRC	=	src/main.c	\
		src/file.c \
		src/take_info.c \
		src/printer.c \
		src/tools.c \
		src/list_utils.c \
		src/op.c \
		src/analyse.c \
		src/take_byte_value.c \
		src/count_op.c \
		src/direct_label.c \
		src/error.c \

OBJ	=	$(SRC:.c=.o)

NAME	=	asm

CFLAGS	=	-W -Wall -Wextra -w

LINKFLAGS	=	-L./lib -lmy

all: $(NAME)

$(NAME): $(OBJ)
	@make -C ./lib
	$(CC) $(OBJ) ${LINKFLAGS} -o $(NAME)
	@echo "\033[5m\033[3m\033[33mEtat for -> $(NAME) -> compile -> OK\033[0m"

clean:
	$(RM) *~
	$(RM) \#*#
	$(RM) $(OBJ)
	@make clean -C ./lib
	@echo "\033[5m\033[3m\033[33mEtat for -> $(NAME) -> clean -> OK\033[0m"

fclean: clean
	@make fclean -C ./lib
	$(RM) $(NAME)
	@echo "\033[5m\033[3m\033[33mEtat for -> $(NAME) -> fclean -> OK\033[0m"

re:	fclean all
