/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** change_pc.c
*/

#include "../include/my.h"
#include "../include/printf.h"
#include "../include/corewar.h"
#include "../include/op.h"

int change_index_pc(int diff, int pc)
{
    pc += diff;
    if (pc < 0)
        pc = MEM_SIZE - (pc * -1);

    if (pc > MEM_SIZE)
        pc = 0 + (pc - MEM_SIZE);

    return (pc);
}