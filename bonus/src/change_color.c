/*
** EPITECH PROJECT, 2020
** corewar
** File description:
** change_color.c
*/

#include "../include/bonus.h"

void check_dead(bonus_t *all, corewar_t *core)
{
    for (list_prog_t *champ = core->list_prog;
    champ != NULL; champ = champ->next) {
        if (champ->live == 0) {
            sfText_setColor(all->inf.champ[champ->pc.id - 1].text, sfRed);
        }
    }
}

void color_pc_bis(bonus_t *all, corewar_t *core, list_prog_t *tmp)
{
    if (core->prog_num[0] == tmp->pc.id)
        sfText_setFillColor(all->vm[tmp->pc.ptr].text,
        (sfColor) {35, 188, 250, 255});
    if (core->prog_num[1] == tmp->pc.id)
        sfText_setFillColor(all->vm[tmp->pc.ptr].text,
        (sfColor) {255, 131, 77, 255});
    if (core->prog_num[2] == tmp->pc.id)
        sfText_setFillColor(all->vm[tmp->pc.ptr].text,
        (sfColor) {255, 250, 84, 255});
    if (core->prog_num[3] == tmp->pc.id)
        sfText_setFillColor(all->vm[tmp->pc.ptr].text, sfGreen);
}

void color_pc(bonus_t *all, corewar_t *core)
{
    for (list_prog_t *tmp = core->list_prog; tmp != NULL; tmp = tmp->next) {
        color_pc_bis(all, core, tmp);
        for (list_prog_t *child = tmp->child;
        child != NULL; child = child->next) {
            color_pc_bis(all, core, child);
        }
    }
}

void color_champ(bonus_t *all, corewar_t *core, int i)
{
    if (core->func_info[i].id != 0) {
        if (core->prog_num[0] == core->func_info[i].id)
            sfText_setFillColor(all->vm[i].text, sfBlue);
        if (core->prog_num[1] == core->func_info[i].id)
            sfText_setFillColor(all->vm[i].text, (sfColor) {203, 48, 44, 255});
        if (core->prog_num[2] == core->func_info[i].id)
            sfText_setFillColor(all->vm[i].text, (sfColor) {197, 200, 0, 255});
        if (core->prog_num[3] == core->func_info[i].id)
            sfText_setFillColor(all->vm[i].text, (sfColor) {43, 142, 53, 255});
    } else
        sfText_setFillColor(all->vm[i].text, sfWhite);
}