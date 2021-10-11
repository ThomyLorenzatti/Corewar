##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile to compile the project
##

RM	=	rm -f

all: compile

compile:
	@make -C ./corewar
	@make -C ./asm
	@echo "\033[5m\033[3m\033[33mEtat for -> corewar -> compile -> OK\033[0m"

bonus:
	@make bonus -C ./corewar

tests_run :
	@make -C ./tests

clean:
	$(RM) *~
	$(RM) \#*#
	$(RM) $(OBJ)
	@make clean -C ./corewar
	@make clean -C ./asm
	@echo "\033[5m\033[3m\033[33mEtat for -> corewar -> clean -> OK\033[0m"

fclean:
	@make fclean -C ./corewar
	@make fclean -C ./asm
	@echo "\033[5m\033[3m\033[33mEtat for -> corewar -> fclean -> OK\033[0m"

re:	fclean all
