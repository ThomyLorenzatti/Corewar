/*
** EPITECH PROJECT, 2020
** lib
** File description:
** main.c
*/

#include "../include/my.h"
#include "../include/printf.h"
#include "../include/corewar.h"

void help(void)
{
    my_putstr("USAGE\n./corewar [-dump nbr_cycle] [[-n prog_number] [-a");
    my_putstr(" load_address] prog_name] ...\nDESCRIPTION\n");
    my_putstr("-dump nbr_cycle dumps the memory after the nbr_cycle ");
    my_putstr("execution (if the round isn't\nalready over) with the ");
    my_putstr("following format: 32 bytes/line\n");
    my_putstr("in hexadecimal (A0BCDEFE1DD3...)\n");
    my_putstr("-n prob_number sets the next program's number. B");
    my_putstr("y default, the first free number\nin the parameter order\n");
    my_putstr("-a load_address sets the next program's loading address. ");
    my_putstr("When no address is\nspecified, optimize the addresses");
    my_putstr(" so that the processes are as far\n");
    my_putstr("away from each other as possible. The addresses");
    my_putstr(" are MEM_SIZE modulo.\n");
}

int main(int ac, char **av)
{
    corewar_t core;
    core.vm = NULL;
    core.nbr_prog = 0;
    core.cycle = 0;
    core.cycle_die = CYCLE_TO_DIE;
    core.live = 0;
    core.list_prog = NULL;
    if (ac == 2 && my_strncmp(av[1], "-h", 2) == 0) {
        help();
        return (0);
    }
    if (ac < 3 || ac > 5)
        return (84);
    if (insert_list(&core, av) == 84)
        return (84);
    init_vm(&core);
    print_vm(&core);
    return (0);
}