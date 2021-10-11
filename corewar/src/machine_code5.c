/*
** EPITECH PROJECT, 2020
** corewar
** File description:
** machine_code5.c
*/

#include "../include/my.h"
#include "../include/printf.h"
#include "../include/corewar.h"
#include "../include/op.h"

void get_ld(pc_t *pc, corewar_t *core, op_t tab, list_prog_t *champ)
{
    (void)tab;
    int dif_F = 65535;
    int size1 = core->func_info[pc->ptr].type[0];
    int size2 = core->func_info[pc->ptr].type[1];
    char *tmp = malloc(sizeof(char) * size1 * 2);
    char *idx = malloc(sizeof(char) * size2 * 2);
    for (int i = 0; i < size1; i += 1)
        tmp = my_strcat(tmp, get_hexa(core->vm[pc->ptr + i + 2]));
    if (tmp[0] == 'F')
        dif_F -= hex_to_int(tmp);
    else
        dif_F = hex_to_int(tmp);
    for (int i = 0; i < size2; i += 1)
        idx = my_strcat(idx, get_hexa(core->vm[pc->ptr + i + size1 + 2]));
    dif_F = cp(dif_F % IDX_MOD, pc->ptr);
    for (int i = 0; i < 4; i += 1)
        tmp[i] = core->vm[dif_F + 1];
    champ->registre[hex_to_int(idx) - 1] = hex_to_int(tmp);
    change_carry(champ->registre[hex_to_int(idx) - 1], champ);
    pc->ptr = change_index_pc(size1 + size2 + 1, pc->ptr);
}

void get_fork(pc_t *pc, corewar_t *core, op_t tab, list_prog_t *champ)
{
    char *tmp = malloc(sizeof(char) * 4);
    int new_pc = 0;
    int dif_F = 65535;
    list_prog_t *temp;
    (void)tab;
    tmp = get_hexa(core->vm[pc->ptr + 1]);
    tmp = my_strcat(tmp, get_hexa(core->vm[pc->ptr + 2]));
    if (tmp[0] == 'F') {
        dif_F -= hex_to_int(tmp);
        new_pc = change_index_pc((((dif_F + 2) * - 1) % IDX_MOD), pc->ptr);
    } else
        new_pc = change_index_pc(hex_to_int(tmp) % IDX_MOD, pc->ptr);
    for (temp = champ; temp->parent != NULL; temp = temp->parent);
    init_push_back_child(&temp, champ->info.prog_name,
    champ->registre, new_pc);
    pc->ptr = change_index_pc(2, pc->ptr);
    free(tmp);
}

void get_lfork(pc_t *pc, corewar_t *core, op_t tab, list_prog_t *champ)
{
    char *tmp = malloc(sizeof(char) * 4);
    int new_pc = 0;
    int dif_F = 65535;
    list_prog_t *temp;
    (void)tab;
    tmp = get_hexa(core->vm[pc->ptr + 1]);
    tmp = my_strcat(tmp, get_hexa(core->vm[pc->ptr + 2]));
    if (tmp[0] == 'F') {
        dif_F -= hex_to_int(tmp);
        new_pc = change_index_pc((((dif_F + 2) * - 1)), pc->ptr);
    } else
        new_pc = change_index_pc(hex_to_int(tmp), pc->ptr);
    for (temp = champ; temp->parent != NULL; temp = temp->parent);
    init_push_back_child(&temp, champ->info.prog_name,
    champ->registre, new_pc);
    pc->ptr = change_index_pc(2, pc->ptr);
    free(tmp);
}