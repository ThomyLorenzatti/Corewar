##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile to compile the project
##

CC	=	gcc

SRC	=	src/main.c	\
		src/init_prog.c	\
		src/init_vm.c	\
		src/vm_loop.c	\
		src/op.c	\
		src/machine_code.c	\
		src/machine_code2.c	\
		src/machine_code3.c	\
		src/machine_code4.c	\
		src/machine_code5.c	\
		src/func_sti.c	\

SRC2 = src/print_vm.c

SRCB = $(SRC)	\
		../bonus/src/print_vm.c	\
		../bonus/src/init_text.c	\
		../bonus/src/change_color.c

OBJ	=	$(SRC:.c=.o)

OBJ2 =	$(SRC2:.c=.o)

OBJB	=	$(SRCB:.c=.o)

NAME	=	corewar

BONUS	=	corewar_graphique

CFLAGS	=	-W -Wall -Wextra

LINKFLAGS	=	-L./lib -lmy

BONUSFLAGS	=	-lcsfml-window -lcsfml-graphics -lcsfml-system


all: $(NAME)

$(NAME): $(OBJ) $(OBJ2)
	@make -C ./lib
	$(CC) $(OBJ) $(OBJ2) ${LINKFLAGS} -o $(NAME)
	@echo "\033[5m\033[3m\033[33mEtat for -> $(NAME) -> compile -> OK\033[0m"

bonus: $(OBJB)
	@make -C ./lib
	$(CC) $(OBJB) ${LINKFLAGS} ${BONUSFLAGS} -o $(BONUS)
	@echo "\033[5m\033[3m\033[33mEtat for -> $(BONUS) -> compile -> OK\033[0m"

clean:
	$(RM) *~
	$(RM) \#*#
	$(RM) $(OBJ)
	$(RM) $(OBJ2)
	@make clean -C ./lib
	@echo "\033[5m\033[3m\033[33mEtat for -> $(NAME) -> clean -> OK\033[0m"

fclean: clean
	@make fclean -C ./lib
	$(RM) $(NAME)
	$(RM) $(BONUS)
	@echo "\033[5m\033[3m\033[33mEtat for -> $(NAME) -> fclean -> OK\033[0m"

re:	fclean all
