/*
** EPITECH PROJECT, 2020
** B-CPE-201-MPL-2-1-corewar-thomy.lorenzatti
** File description:
** analyse.c
*/

#include "../include/my.h"
#include "../include/printf.h"
#include "../include/asm.h"

int check_func(asm_t *all, char *elem)
{
    object_t tmp;
    char *func[4] = {"live", "fork", "lfork", "zjmp"};
    for (int i = 0; i < 4; i++) {
        if (my_strcmp(func[i], elem) == 0) {
            tmp.type = FUNC;
            tmp.elem = my_strdup(elem);
            obj_list_push_back(&all->list, tmp);
        }
    }
    if (elem[0] == 'r') {
        tmp.type = REG;
        tmp.elem = my_strdup(elem);
        obj_list_push_back(&all->list, tmp);
    }
    return (0);
}

int check_mnemonic(asm_t *all, char *elem)
{
    object_t tmp;
    char *op_func[12] = {"ld", "st", "add", "sub", "and", "or", "xor",
    "ldi", "sti", "lld", "lldi", "aff"};
    for (int i = 0; i < 12; i++) {
        if (my_strcmp(op_func[i], elem) == 0) {
            tmp.type = OP_FUNC;
            tmp.elem = my_strdup(elem);
            obj_list_push_back(&all->list, tmp);
            tmp.type = OP_CODE;
            tmp.elem = my_strdup("00");
            obj_list_push_back(&all->list, tmp);
        }
    }
    check_func(all, elem);
    if (elem[0] == '%') {
        tmp.type = DIRT;
        tmp.elem = my_strdup(elem);
        obj_list_push_back(&all->list, tmp);
    }
    return (0);
}

void analyse_elem(asm_t *all, char *elem)
{
    object_t tmp;
    check_mnemonic(all, elem);
    if (elem[0] >= '0' && elem[0] <= '9') {
        tmp.type = IND;
        tmp.elem = my_strdup(elem);
        obj_list_push_back(&all->list, tmp);
    }
    if (check_label(elem) == 0) {
        tmp.type = LABEL;
        tmp.elem = my_strdup(elem);
        obj_list_push_back(&all->list, tmp);
    }
    if (elem[0] == '=' && elem[1] == '=') {
        tmp.type = SEPARATOR;
        tmp.elem = my_strdup("=====");
        obj_list_push_back(&all->list, tmp);
    }
}