/*
** EPITECH PROJECT, 2020
** corewar
** File description:
** print_vm.c
*/

#include "../include/corewar.h"
#include "../include/my.h"

void print_vm(corewar_t *core)
{
    while (core->nbr_prog > 1)
        vm_loop(core);
    for (list_prog_t *champ = core->list_prog;
    champ != NULL; champ = champ->next) {
        if (champ->live == 1) {
            my_printf("The player %d(%s)has won.\n",
            champ->info.prog_number, champ->head->prog_name);
        }
    }
}