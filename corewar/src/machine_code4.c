/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** fichier4.c
*/

#include "../include/my.h"
#include "../include/printf.h"
#include "../include/corewar.h"
#include "../include/op.h"

void get_zjmp(pc_t *pc, corewar_t *core, op_t tab, list_prog_t *champ)
{
    (void)tab;
    (void)champ;
    char *tmp = malloc(sizeof(char) * 4);
    int dif_F = 65535;
    tmp = get_hexa(core->vm[pc->ptr + 1]);
    tmp = my_strcat(tmp, get_hexa(core->vm[pc->ptr + 2]));
    if (champ->carry == 0) {
        pc->ptr = cp(2, pc->ptr);
        return;
    }
    if (tmp[0] == 'F') {
        dif_F -= hex_to_int(tmp);
        pc->ptr = change_index_pc((((dif_F + 2) * - 1) % IDX_MOD), pc->ptr);
    } else
        pc->ptr = change_index_pc((hex_to_int(tmp) - 1) % IDX_MOD, pc->ptr);
    free(tmp);
}

void get_lld(pc_t *pc, corewar_t *core, op_t tab, list_prog_t *champ)
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

void lldi(corewar_t *core, pc_t *pc, list_prog_t *champ, int result)
{
    int size1 = core->func_info[pc->ptr].type[0];
    int idx_r = 0;
    int size2 = core->func_info[pc->ptr].type[1];

    result = hex_to_int(get_hexa(core->vm[cp(result, pc->ptr)]));
    idx_r = hex_to_int(get_hexa(core->vm[pc->ptr + size1 + size2 + 1]));
    change_carry(result, champ);
    champ->registre[idx_r - 1] = result;
}

void get_lldi(pc_t *pc, corewar_t *core, op_t tab, list_prog_t *champ)
{
    (void)tab;
    int size1 = core->func_info[pc->ptr].type[0];
    int size2 = core->func_info[pc->ptr].type[1];
    int size3 = core->func_info[pc->ptr].type[2];
    int dist1 = 0;
    int dist2 = 0;
    char *dist1_c = malloc(sizeof(char) * size1 * 2);
    char *dist2_c = malloc(sizeof(char) * size2 * 2);
    int result = 0;
    for (int i = 0; i < size1; i += 1)
        dist1_c = my_strcat(dist1_c, get_hexa(core->vm[pc->ptr + 2 + i]));
    for (int i = 0; i < size2; i += 1)
        dist2_c = my_strcat(dist2_c, get_hexa(core->vm[pc->ptr + 2 + i]));
    dist1 = hex_to_int(dist1_c);
    dist2 = hex_to_int(dist2_c);
    for (int i = 0; i < IND_SIZE; i += 1)
        result += hex_to_int(get_hexa(core->vm[cp(dist1, pc->ptr)]));
    result += dist2;
    lldi(core, pc, champ, result);
    pc->ptr = change_index_pc(size1 + size2 + size3 + 1, pc->ptr);
}

void get_aff(pc_t *pc, corewar_t *core, op_t tab, list_prog_t *champ)
{
    (void)tab;
    int index = 0;
    int size = core->func_info[pc->ptr].type[0];
    int car = 0;

    if (size != 1) {
        pc->ptr = cp(size + 1, pc->ptr);
        return;
    }
    index = hex_to_int(get_hexa(core->vm[pc->ptr]));
    car = champ->registre[index];
    car = car % 256;
    my_printf("%c", car);
    pc->ptr = change_index_pc(size + 1, pc->ptr);
}