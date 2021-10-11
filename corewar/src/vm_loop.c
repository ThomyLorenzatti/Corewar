/*
** EPITECH PROJECT, 2020
** corewar
** File description:
** loop.c
*/

#include "../include/my.h"
#include "../include/printf.h"
#include "../include/corewar.h"
#include "../include/op.h"

static func_t func[] = {
    {get_live},
    {get_ld},
    {get_st},
    {get_add},
    {get_sub},
    {get_and},
    {get_or},
    {get_xor},
    {get_zjmp},
    {get_ldi},
    {get_sti},
    {get_fork},
    {get_lld},
    {get_lldi},
    {get_lfork},
    {get_aff}
};

void find_func(pc_t *pc, corewar_t *core, list_prog_t *champ)
{
    for (int i = 0; i < 16; i++) {
        if (my_strcmp(get_hexa(op_tab[i].code),
        get_hexa(core->vm[pc->ptr])) == 0) {
            pc->cycle = op_tab[i].nbr_cycles;
            func[i].ptr(pc, core, op_tab[i], champ);
            break;
        }
    }
}

void turn_pc_champ(pc_t *pc, corewar_t *core, list_prog_t *champ)
{
    if (champ->live == 1) {
        if (pc->cycle == 0) {
            find_func(pc, core, champ);
            pc->ptr = cp(1, pc->ptr);
        }
        pc->cycle--;
        if (pc->cycle < 0)
            pc->cycle = 0;
    }
}

void reset_live(corewar_t *core)
{
    core->cycle += 1;
    if (core->cycle >= core->cycle_die) {
        for (list_prog_t *champ = core->list_prog;
        champ != NULL; champ = champ->next) {
            if (champ->alive == 0 && champ->live == 1) {
                champ->live = 0;
                core->nbr_prog -= 1;
            } else
                champ->alive = 0;
        }
        core->cycle = 0;
    }
}

void vm_loop(corewar_t *core)
{
    if (core->nbr_prog <= 1)
        return;
    for (list_prog_t *champ = core->list_prog;
    champ != NULL; champ = champ->next) {
        turn_pc_champ(&champ->pc, core, champ);
        for (list_prog_t *child = champ->child;
        child != NULL; child = child->next)
            turn_pc_champ(&child->pc, core, child);
        if (core->live >= NBR_LIVE) {
            core->cycle_die -= CYCLE_DELTA;
            core->live = 0;
        }
    }
    reset_live(core);
}