/*
** EPITECH PROJECT, 2020
** B-CPE-201-MPL-2-1-corewar-thomy.lorenzatti
** File description:
** direct.c
*/

#include "../include/my.h"
#include "../include/printf.h"
#include "../include/asm.h"

void count_length(asm_t *all, object_t *tmp, int a)
{
    int count = 4;
    int total = 0;
    int part = 0;
    list_t *ltmp = all->list;
    for (; part < all->part; ltmp = ltmp->next) {
        if (my_strcmp(ltmp->value.elem, "=====") == 0) part += 1;
    }
    for (int i = 0; ltmp; ltmp = ltmp->next, i++) {
        if (my_strncmp(tmp->elem + 2, ltmp->value.elem,
        my_strlen(ltmp->value.elem) - 1) == 0 &&
        ltmp->value.elem[my_strlen(ltmp->value.elem) - 1] == ':')
            break;
        if ((ltmp->value.type == OP_FUNC || ltmp->value.type == FUNC)
        && ltmp->value.cycle >= 20) count = 2;
        if (ltmp->value.type == DIRT) total += count;
        else if (ltmp->value.type != SEPARATOR && ltmp->value.type != LABEL)
            total += 1;
        if (ltmp->value.type == SEPARATOR) count = 4;
    }
    tmp->nb = total;
}

int part_of_label(asm_t *all, list_t *tmp, object_t *obj)
{
    list_t *tmp2 = tmp;
    tmp2 = tmp2->next;
    for (; tmp2; tmp2 = tmp2->next) {
        if (my_strncmp(tmp2->value.elem + 2, obj->elem,
        my_strlen(obj->elem) - 1) == 0)
            return (1);
        if (tmp2->value.type == SEPARATOR)
            break;
    }
    return (0);
}

int count_length_label2(object_t *tmp, object_t ltmp, int *count, int *total)
{
    if ((ltmp.type == OP_FUNC || ltmp.type == FUNC)
    && ltmp.cycle >= 20)
        *count = 2;
    if (ltmp.type == DIRT)
        *total += *count;
    else if (ltmp.type != SEPARATOR &&
    ltmp.type != LABEL && ltmp.type != IND)
        *total += 1;
    if (ltmp.type == IND)
        *total += 2;
    if (ltmp.type == SEPARATOR)
        *count = 4;
    return (0);
}

void count_length_label(asm_t *all, object_t *tmp, int a)
{
    int count = 4;
    int total = 0;
    list_t *ltmp = all->list;
    int part = 0;
    for (; part < all->part; ltmp = ltmp->next) {
        if (my_strcmp(ltmp->value.elem, "=====") == 0)
            part += 1;
    }
    check_label_error(all, tmp);
    for (int i = 0; ltmp; ltmp = ltmp->next, i++) {
        if (ltmp->value.type == SEPARATOR && part_of_label(all, ltmp, tmp) == 1)
            break;
        count_length_label2(tmp, ltmp->value, &count, &total);
    }
    for (int i = 0; ltmp; ltmp = ltmp->next, i++) {
        if (my_strncmp(ltmp->value.elem + 2, tmp->elem,
        my_strlen(tmp->elem) - 1) == 0) {
            ltmp->value.nb = total * -1;
        }
    }
}

void count_byte_length(asm_t *all)
{
    list_t *tmp = all->list;
    int count = 4;
    int total = 0;
    for (; tmp; tmp = tmp->next) {
        if (my_strcmp(tmp->value.elem, "=====") == 0)
            count = 4;
        if (tmp->value.cycle >= 20 &&
        (tmp->value.type == OP_FUNC || tmp->value.type == FUNC))
            count = 2;
        if (tmp->value.type == REG
        || tmp->value.type == OP_CODE || tmp->value.type == OP_FUNC
        || tmp->value.type == FUNC)
            total += 1;
        if (tmp->value.type == IND)
            total += 2;
        if (tmp->value.type == DIRT)
            total += count;
    }
    all->byte_len = total;
}