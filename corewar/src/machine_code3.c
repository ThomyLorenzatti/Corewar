/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** fichier3.c
*/

#include "../include/my.h"
#include "../include/printf.h"
#include "../include/corewar.h"
#include "../include/op.h"

void get_add(pc_t *pc, corewar_t *core, op_t tab, list_prog_t *champ)
{
    (void)tab;
    int size1 = core->func_info[pc->ptr].type[0];
    int size2 = core->func_info[pc->ptr].type[1];
    int size3 = core->func_info[pc->ptr].type[2];
    int index_one = 0;
    int index_two = 0;
    int index_three = 0;
    int tmp = 0;

    index_one = hex_to_int(get_hexa(core->vm[pc->ptr + 2]));
    index_two = hex_to_int(get_hexa(core->vm[pc->ptr + 3]));
    index_three = hex_to_int(get_hexa(core->vm[pc->ptr + 4]));
    tmp = champ->registre[index_one] + champ->registre[index_two];
    champ->registre[index_three] = tmp;
    change_carry(tmp, champ);
    pc->ptr = change_index_pc(size1 + size2 + size3 + 1, pc->ptr);
}

void get_sub(pc_t *pc, corewar_t *core, op_t tab, list_prog_t *champ)
{
    (void)tab;
    int size1 = core->func_info[pc->ptr].type[0];
    int size2 = core->func_info[pc->ptr].type[1];
    int size3 = core->func_info[pc->ptr].type[2];
    int index_one = 0;
    int index_two = 0;
    int index_three = 0;
    int tmp = 0;

    index_one = hex_to_int(get_hexa(core->vm[pc->ptr + 2]));
    index_two = hex_to_int(get_hexa(core->vm[pc->ptr + 3]));
    index_three = hex_to_int(get_hexa(core->vm[pc->ptr + 4]));
    tmp = champ->registre[index_one] - champ->registre[index_two];
    champ->registre[index_three] = tmp;
    change_carry(tmp, champ);
    pc->ptr = change_index_pc(size1 + size2 + size3 + 1, pc->ptr);
}

void get_and(pc_t *pc, corewar_t *core, op_t tab, list_prog_t *champ)
{
    (void)tab;
    (void)champ;
    int size1 = core->func_info[pc->ptr].type[0];
    int size2 = core->func_info[pc->ptr].type[1];
    int size3 = core->func_info[pc->ptr].type[2];
    pc->ptr = change_index_pc(1 + size1 + size2 + size3, pc->ptr);
}

void get_or(pc_t *pc, corewar_t *core, op_t tab, list_prog_t *champ)
{
    (void)tab;
    (void)champ;
    int size1 = core->func_info[pc->ptr].type[0];
    int size2 = core->func_info[pc->ptr].type[1];
    int size3 = core->func_info[pc->ptr].type[2];
    pc->ptr = change_index_pc(1 + size1 + size2 + size3, pc->ptr);
}

void get_xor(pc_t *pc, corewar_t *core, op_t tab, list_prog_t *champ)
{
    (void)tab;
    (void)champ;
    int size1 = core->func_info[pc->ptr].type[0];
    int size2 = core->func_info[pc->ptr].type[1];
    int size3 = core->func_info[pc->ptr].type[2];
    pc->ptr = change_index_pc(1 + size1 + size2 + size3, pc->ptr);
}