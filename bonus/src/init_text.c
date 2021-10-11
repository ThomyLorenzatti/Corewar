/*
** EPITECH PROJECT, 2020
** corewar
** File description:
** init_text.c
*/

#include "../include/bonus.h"

void text_champ(bonus_t *all)
{
    for (int i = 0; i < SIZE_CHAMP; i += 1) {
        all->inf.champ[i].text = sfText_create();
        all->inf.champ[i].str = malloc(sizeof(char) * 100);
        for (int a = 0; a < 100; a++) {
            all->inf.champ[i].str[a] = '\0';
        }
        sfText_setString(all->inf.champ[i].text, all->inf.champ[i].str);
        sfText_setFont(all->inf.champ[i].text, all->font);
        sfText_setColor(all->inf.champ[i].text, sfWhite);
        sfText_setCharacterSize(all->inf.champ[i].text, 25);
        sfText_setPosition(all->inf.champ[i].text,
        (sfVector2f) {10, 20 + (i * 2 * 20)});
    }
    all->inf.lives.text = sfText_create();
    all->inf.lives.str = malloc(sizeof(char) * 100);
    all->inf.cycle.str = malloc(sizeof(char) * 100);
    for (int a = 0; a < 100; a++) {
        all->inf.lives.str[a] = '\0';
        all->inf.cycle.str[a] = '\0';
    }
}

void cycle_text(bonus_t *all, corewar_t *core)
{
    text_champ(all);
    all->inf.cycle.text = sfText_create();
    sfText_setString(all->inf.lives.text, all->inf.lives.str);
    sfText_setFont(all->inf.lives.text, all->font);
    sfText_setColor(all->inf.lives.text, sfWhite);
    sfText_setCharacterSize(all->inf.lives.text, 25);
    sfText_setPosition(all->inf.lives.text, (sfVector2f) {1280, 50});
    sfText_setString(all->inf.cycle.text, all->inf.cycle.str);
    sfText_setFont(all->inf.cycle.text, all->font);
    sfText_setColor(all->inf.cycle.text, sfWhite);
    sfText_setCharacterSize(all->inf.cycle.text, 25);
    sfText_setPosition(all->inf.cycle.text, (sfVector2f) {1280, 100});

    modif_registre(core, all);
    modif_cycles_lives(core, all);
}

void init_text(bonus_t *all, corewar_t *core)
{
    int a = 0;
    sfVector2f pos = {65, 175};
    all->font = sfFont_createFromFile("../bonus/include/arial.ttf");

    cycle_text(all, core);
    for (int i = 0; i < MEM_SIZE; i++, a++) {
        all->vm[i].text = sfText_create();
        all->vm[i].str = get_hexa(core->vm[i]);
        sfText_setString(all->vm[i].text, all->vm[i].str);
        sfText_setFont(all->vm[i].text, all->font);
        sfText_setCharacterSize(all->vm[i].text, 11);
        color_champ(all, core, i);
        sfText_setPosition(all->vm[i].text, pos);
        pos.x += 14;
        if (i == 127 || a == 128) {
            pos.x = 65;
            pos.y += 16;
            a = 0;
        }
    }
}

void destroy_text(bonus_t *all, corewar_t *core)
{
    (void)core;
    for (int i = 0; i < MEM_SIZE; i++) {
        sfText_destroy(all->vm[i].text);
        free(all->vm[i].str);
    }
    for (int i = 0; i < SIZE_CHAMP; i += 1) {
        sfText_destroy(all->inf.champ[i].text);
        free(all->inf.champ[i].str);
    }
    sfText_destroy(all->inf.lives.text);
    sfText_destroy(all->inf.cycle.text);
    free(all->inf.lives.str);
    free(all->inf.cycle.str);
    sfFont_destroy(all->font);
}