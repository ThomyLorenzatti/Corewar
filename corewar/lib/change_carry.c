/*
** EPITECH PROJECT, 2020
** corewar
** File description:
** change_carry.c
*/

#include "../include/my.h"
#include "../include/corewar.h"
#include "../include/op.h"

void change_carry(int test, list_prog_t *champ)
{
    if (test == 0)
        champ->carry = 1;
    else
        champ->carry = 0;
}