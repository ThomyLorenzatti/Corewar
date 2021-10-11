/*
** EPITECH PROJECT, 2020
** corewar
** File description:
** machine_code2.c
*/

#include "../include/my.h"
#include "../include/printf.h"
#include "../include/corewar.h"
#include "../include/op.h"

void ldi(corewar_t *core, pc_t *pc, list_prog_t *champ, int result)
{
    int size1 = core->func_info[pc->ptr].type[0];
    int idx_r = 0;
    int size2 = core->func_info[pc->ptr].type[1];

    result = hex_to_int(get_hexa(core->vm[cp(result % IDX_MOD, pc->ptr)]));
    idx_r = hex_to_int(get_hexa(core->vm[pc->ptr + size1 + size2 + 1]));
    change_carry(result, champ);
    champ->registre[idx_r - 1] = result;
}

void get_ldi(pc_t *pc, corewar_t *core, op_t tab, list_prog_t *champ)
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
        result += hex_to_int(get_hexa(core->vm[cp(dist1 % IDX_MOD, pc->ptr)]));
    result += dist2;
    ldi(core, pc, champ, result);
    pc->ptr = change_index_pc(size1 + size2 + size3 + 1, pc->ptr);
}

int do_registre(corewar_t *core, pc_t *pc, int dist)
{
    return (hex_to_int(get_hexa(core->vm[cp(dist, pc->ptr)])) - 1);
}

int do_indirect(corewar_t *core, pc_t *pc, int dist)
{
    int a = 0;
    char *temp;
    char *tmp = malloc(sizeof(char) * 5);

    for (int i = 0; i < 2; i += 1, a += 2) {
        temp = get_hexa(core->vm[cp(i + dist, pc->ptr)]);
        tmp[a] = temp[0];
        tmp[a + 1] = temp[1];
    }
    tmp[a] = '\0';
    return (hex_to_int(tmp));
}