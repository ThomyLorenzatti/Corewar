/*
** EPITECH PROJECT, 2020
** B-CPE-201-MPL-2-1-corewar-thomy.lorenzatti
** File description:
** take_byte_value.c
*/

#include "../include/my.h"
#include "../include/printf.h"
#include "../include/asm.h"

int is_label_after(asm_t *all, list_t *tmp)
{
    list_t *tmp2 = tmp;

    tmp2 = tmp2->next->next;
    for (; tmp2; tmp2 = tmp2->next) {
        if (my_strncmp(tmp->value.elem + 2, tmp2->value.elem,
        my_strlen(tmp2->value.elem) - 1))
            return (1);
    }
    return (0);
}

void take_reg_code(asm_t *all, object_t *tmp, int a, int type)
{
    list_t *ltmp = all->list;
    for (int i = 0; i < a; i++, ltmp = ltmp->next);
    if (type == 1) {
        tmp->nb = my_atoi(ltmp->value.elem + 1);
        if (tmp->nb < 1 || tmp->nb > 16)
            exit(84);
    }
    if (type == 2)
        tmp->nb = my_atoi(ltmp->value.elem);
    if (type == 3) {
        if (ltmp->value.elem[1] == ':' && is_label_after(all, ltmp) == 1
        && ltmp->value.nb == 0)
            count_length(all, tmp, a);
        else if (ltmp->value.elem[1] >= '0' && ltmp->value.elem[1] <= '9')
            tmp->nb = my_atoi(ltmp->value.elem + 1);
    }
    if (type == 4) {
        count_length_label(all, tmp, a);
    }
}

int take_byte_value(asm_t *all)
{
    list_t *tmp = all->list;
    int a = 0;
    for (; tmp; tmp = tmp->next, a++) {
        for (int i = 0; op_tab[i].code != 0; i++) {
            if (my_strcmp(tmp->value.elem, op_tab[i].mnemonique) == 0)
                tmp->value.nb = op_tab[i].code;
        }
        if (tmp->value.type == OP_CODE) calcul_op_code(all, &tmp->value, a);
        if (tmp->value.type == REG) take_reg_code(all, &tmp->value, a, 1);
        if (tmp->value.type == IND) take_reg_code(all, &tmp->value, a, 2);
        if (tmp->value.type == DIRT) take_reg_code(all, &tmp->value, a, 3);
        if (tmp->value.type == LABEL) take_reg_code(all, &tmp->value, a, 4);
        if (tmp->value.type == SEPARATOR) all->part += 1;
    }
    count_byte_length(all);
    return (0);
}