/*
** EPITECH PROJECT, 2020
** corewar
** File description:
** print_vm.c
*/

#include "../include/bonus.h"

int create_window(bonus_t *all)
{
    all->window = sfRenderWindow_create
        (*sfVideoMode_getFullscreenModes(0), "Corewar", sfFullscreen, NULL);
    sfRenderWindow_setMouseCursorVisible(all->window, sfTrue);
    if (all->window == NULL)
        return (84);
    return (0);
}

void loop_bonus(corewar_t *core, bonus_t *all)
{
    for (int i = 0; i < MEM_SIZE; i++) {
            color_champ(all, core, i);
            all->vm[i].str = get_hexa(core->vm[i]);
            sfText_setString(all->vm[i].text, all->vm[i].str);
        }
    color_pc(all, core);
    check_dead(all, core);
    for (int i = 0; i < SIZE_CHAMP; i++)
        sfRenderWindow_drawText(all->window, all->inf.champ[i].text, NULL);
    sfRenderWindow_drawText(all->window, all->inf.cycle.text, NULL);
    sfRenderWindow_drawText(all->window, all->inf.lives.text, NULL);
    for (int i = 0; i < MEM_SIZE; i++)
        sfRenderWindow_drawText(all->window, all->vm[i].text, NULL);
    modif_registre(core, all);
    modif_cycles_lives(core, all);
    vm_loop(core);
}

void print_vm(corewar_t *core)
{
    bonus_t all;
    create_window(&all);
    init_text(&all, core);
    while (sfRenderWindow_isOpen(all.window) && core->nbr_prog >= 1) {
        while (sfRenderWindow_pollEvent(all.window, &all.event)) {
            if (all.event.type == sfEvtClosed)
                sfRenderWindow_close(all.window);
            if (all.event.type == sfEvtKeyPressed
            && all.event.key.code == sfKeyEscape)
                sfRenderWindow_close(all.window);
        }
        sfRenderWindow_clear(all.window, sfBlack);
        loop_bonus(core, &all);
        sfRenderWindow_display(all.window);
    }
    destroy_text(&all, core);
}

void modif_cycles_lives(corewar_t *core, bonus_t *all)
{
    char *temp = malloc(sizeof(char) * 10);
    for (int i = 0; i < 100; i += 1) {
        all->inf.cycle.str[i] = '\0';
        all->inf.lives.str[i] = '\0';
    }
    all->inf.cycle.str = strcat(all->inf.cycle.str, "Cycles: ");
    sprintf(temp, "%d", core->cycle);
    all->inf.cycle.str = strcat(all->inf.cycle.str, temp);
    all->inf.cycle.str = strcat(all->inf.cycle.str, " / ");
    sprintf(temp, "%d", core->cycle_die);
    all->inf.cycle.str = strcat(all->inf.cycle.str, temp);
    sfText_setString(all->inf.cycle.text, all->inf.cycle.str);
    all->inf.lives.str = strcat(all->inf.lives.str, "Lives: ");
    sprintf(temp, "%d", core->live);
    all->inf.lives.str = strcat(all->inf.lives.str, temp);
    all->inf.lives.str = strcat(all->inf.lives.str, "/40");
    sfText_setString(all->inf.lives.text, all->inf.lives.str);
}

void modif_registre(corewar_t *core, bonus_t *all)
{
    int i = 0;
    char *temp = malloc(sizeof(char) * 10);
    for (list_prog_t *tmp = core->list_prog; tmp != NULL; tmp = tmp->next) {
        for (int a = 0; a < 100; a++) {
            all->inf.champ[i].str[a] = '\0';
        }
        all->inf.champ[i].str = strcat(all->inf.champ[i].str,
        tmp->head->prog_name);
        all->inf.champ[i].str = strcat(all->inf.champ[i].str, " :\t");
        for (int a = 0; a < 16; a += 1) {
            all->inf.champ[i].str = strcat(all->inf.champ[i].str, "[");
            sprintf(temp, "%d", tmp->registre[a]);
            all->inf.champ[i].str = strcat(all->inf.champ[i].str, temp);
            all->inf.champ[i].str = strcat(all->inf.champ[i].str, "]");
        }
        sfText_setString(all->inf.champ[i].text, all->inf.champ[i].str);
        i += 1;
    }
}