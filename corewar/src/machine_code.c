/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** fichier1.c
*/

#include "../include/my.h"
#include "../include/printf.h"
#include "../include/corewar.h"
#include "../include/op.h"

void live_check(corewar_t *core, int nbr)
{
    char *name;

    for (list_prog_t *tmp = core->list_prog; tmp != NULL; tmp = tmp->next) {
        if (nbr == tmp->registre[0]) {
            name = tmp->head->prog_name;
            core->live += 1;
            tmp->alive = 1;
            my_printf("The player %d(%s) is alive\n", nbr, name);
            break;
        }
    }
}

void get_live(pc_t *pc, corewar_t *core, op_t tab, list_prog_t *champ)
{
    (void)champ;
    (void)tab;
    int m = 0;
    int nbr;
    char *tmp = malloc(sizeof(char) * 10);
    char *temp;
    for (int i = 0; i < 10; i += 1)
        tmp[i] = '\0';
    for (int i = 1; i < 5; i += 1, m += 2) {
        temp = get_hexa(core->vm[pc->ptr + i]);
        tmp[m] = temp[0];
        tmp[m + 1] = temp[1];
    }
    nbr = hex_to_int(tmp);
    live_check(core, nbr);
    pc->ptr = change_index_pc(4, pc->ptr);
    free(tmp);
}

void st(char *tmp_dist, corewar_t *core, pc_t *pc, char *registre_value)
{
    int dist = 0;
    int size1 = core->func_info[pc->ptr].type[0];
    int size2 = core->func_info[pc->ptr].type[1];
    char tmp[3];

    for (int i = 0; i < size2; i += 1) {
        tmp_dist = my_strcat(tmp_dist,
        get_hexa(core->vm[i + size1 + pc->ptr + 2]));
        dist = hex_to_int(tmp_dist);
        for (int i = 0; i < size2; i += 2) {
            tmp[0] = registre_value[i];
            tmp[1] = registre_value[i + 1];
            tmp[2] = '\0';
            core->vm[cp((dist + i) % IDX_MOD, pc->ptr)] = hex_to_int(tmp);
        }
    }
}

char *registre(int value_registre, int index_registre,
list_prog_t *champ, char *registre_value)
{
    value_registre = champ->registre[index_registre - 1];
    my_int_str(registre_value, value_registre, 4);
    registre_value = convert_base(registre_value, "0123456789",
    "0123456789ABCDEF");
    return (registre_value);
}

void get_st(pc_t *pc, corewar_t *core, op_t tab, list_prog_t *champ)
{
    (void)tab;
    int size1 = core->func_info[pc->ptr].type[0];
    int size2 = core->func_info[pc->ptr].type[1];
    char *tmp_dist = malloc(sizeof(char) * size2 * 2);
    int index_registre = 0;
    int value_registre = 0;
    char *r_valu = malloc(sizeof(char) * 20);
    index_registre = hex_to_int(get_hexa(core->vm[pc->ptr + 2]));
    if (index_registre >= 16) {
        pc->ptr = change_index_pc(1 + size1 + size2, pc->ptr);
        return;
    }
    r_valu = registre(value_registre, index_registre, champ, r_valu);
    if (size2 != 1)
        st(tmp_dist, core, pc, r_valu);
    else {
        index_registre = hex_to_int(get_hexa(core->vm[pc->ptr + 3]));
        champ->registre[index_registre - 1] = value_registre;
    }
    pc->ptr = change_index_pc(1 + size1 + size2, pc->ptr);
}