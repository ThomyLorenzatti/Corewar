/*
** EPITECH PROJECT, 2020
** corewar
** File description:
** func_sti.c
*/

#include "../include/my.h"
#include "../include/printf.h"
#include "../include/corewar.h"
#include "../include/op.h"

void get_sti_init_bis(sti_var_t *v)
{
    if (v->arg1[0] == 'f' || v->arg1[0] == 'F') {
        v->dif_F -= hex_to_int(v->arg1);
        v->dist -= v->dif_F;
    } else
        v->dist += hex_to_int(v->arg1);
    if (v->arg2[0] == 'f' || v->arg2[0] == 'F') {
        v->dif2_F -= hex_to_int(v->arg2);
        v->dist -= v->dif2_F;
    } else
        v->dist += hex_to_int(v->arg2);
    v->dist = v->dist % IDX_MOD;
}

void get_sti_init(sti_var_t *v, corewar_t *core, pc_t *pc)
{
    for (v->i = 0; v->i < v->size1 * 2 + 1; v->i++)
        v->arg1[v->i] = '\0';
    for (v->i = 0; v->i < v->size2 * 2 + 1; v->i++)
        v->arg2[v->i] = '\0';
    v->registre = hex_to_int(get_hexa(core->vm[pc->ptr + 2]));
    for (v->i = 0; v->i < v->size1; v->i++)
        v->arg1 = my_strcat(v->arg1,
        get_hexa(core->vm[cp(pc->ptr + 3 + v->i, 0)]));
    for (v->i = 0; v->i < v->size2; v->i++)
        v->arg2 = my_strcat(v->arg2,
        get_hexa(core->vm[cp(pc->ptr + 3 + v->size1 + v->i, 0)]));
    get_sti_init_bis(v);
}

void sti_set_bis(sti_var_t *v, corewar_t *core, pc_t *pc, list_prog_t *champ)
{
    v->test = core->func_info[cp(pc->ptr + v->dist + 3 - v->i, 0)].type[v->a];
    v->str = get_hexa2(champ->registre[v->registre - 1], v->test);
    v->str2[3] = '\0';
    for (v->i = 0, v->a = 0; v->i < v->test; v->i++, v->a += 2) {
        v->str2[0] = v->str[v->a];
        v->str2[1] = v->str[v->a + 1];
        core->vm[cp(pc->ptr + v->dist + v->i, 0)] = hex_to_int(v->str2);
        core->func_info[cp(pc->ptr + v->dist + v->i, 0)].id = champ->pc.id;
        v->str2[0] = '\0';
        v->str2[1] = '\0';
    }
}

void sti_set(sti_var_t *v, corewar_t *core, pc_t *pc, list_prog_t *champ)
{
    for (v->i = 0; pc->ptr + v->dist + 3 - v->i > 0; v->i++) {
        if (core->func_info[cp(pc->ptr + v->dist
        + 3 - v->i, 0)].parameter > 0) {
            v->test = core->func_info[cp(pc->ptr +
            v->dist + 3 - v->i, 0)].type[v->a] - v->i;
            for (v->a = 0; v->test < 0 && v->a <
            core->func_info[cp(pc->ptr + v->dist + 3,
            0)].parameter - 1; v->a++)
                v->test = core->func_info[cp(pc->ptr +
                v->dist + 3 - v->i, 0)].type[v->a + 1] - v->test;
            break;
        }
    }
    sti_set_bis(v, core, pc, champ);
}

void get_sti(pc_t *pc, corewar_t *core, op_t tab, list_prog_t *champ)
{
    (void)tab;
    sti_var_t v = {0, 0, 0, 0, 0, 0, NULL, NULL,
    NULL, {'\0', '\0'}, 0, 65535, 65535};
    v.size1 = core->func_info[pc->ptr].type[1];
    v.size2 = core->func_info[pc->ptr].type[2];
    v.arg1 = malloc(sizeof(char) * (v.size1 * 2) + 1);
    v.arg2 = malloc(sizeof(char) * (v.size2 * 2) + 1);
    get_sti_init(&v, core, pc);
    sti_set(&v, core, pc, champ);
    free(v.arg1);
    free(v.arg2);
    pc->ptr = change_index_pc(2 + v.size1 + v.size2, pc->ptr);
}