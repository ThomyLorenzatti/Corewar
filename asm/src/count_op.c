/*
** EPITECH PROJECT, 2020
** B-CPE-201-MPL-2-1-corewar-thomy.lorenzatti
** File description:
** count_op.c
*/

#include "../include/my.h"
#include "../include/printf.h"
#include "../include/asm.h"

void calcul_op_code2(asm_t *all, int check, char *byte, object_t *tmp)
{
    if (check == 1) {
        byte = my_strcat(byte, "00");
        byte = my_strcat(byte, "00");
        byte = my_strcat(byte, "00");
    }
    if (check == 2) {
        byte = my_strcat(byte, "00");
        byte = my_strcat(byte, "00");
    }
    if (check == 3)
        byte = my_strcat(byte, "00");
    tmp->nb = binary_to_hex(my_atoi(byte));
    free(byte);
}

void calcul_op_code(asm_t *all, object_t *tmp, int a)
{
    list_t *ltmp = all->list;
    char *byte = my_memset(byte, '\0', 8);
    int check = 0;
    for (int i = 0; i <= a; i++, ltmp = ltmp->next);
    for (; ltmp; ltmp = ltmp->next) {
        if (my_strcmp(ltmp->value.elem, "=====") == 0) break;
        if (ltmp->value.type == REG) {
            byte = my_strcat(byte, "01");
            check += 1;
        }
        if (ltmp->value.type == IND) {
            byte = my_strcat(byte, "11");
            check += 1;
        }
        if (ltmp->value.type == DIRT) {
            byte = my_strcat(byte, "10");
            check += 1;
        }
    }
    calcul_op_code2(all, check, byte, tmp);
}