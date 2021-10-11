/*
** EPITECH PROJECT, 2021
** bonus corewar
** File description:
** bonus for the vm
*/

#ifndef BONUS_H_
#define BONUS_H_

#include <stdio.h>
#include <SFML/Graphics.h>
#include <SFML/Config.h>
#include <SFML/System/Export.h>
#include <SFML/System/Time.h>
#include <SFML/System/Types.h>
#include <SFML/Window.h>
#include "../../corewar/include/op.h"
#include "../../corewar/include/my.h"
#include "../../corewar/include/printf.h"
#include "../../corewar/include/corewar.h"

#define SIZE_CHAMP 4

typedef struct text_s {
    char *str;
    sfText *text;
    sfVector2f position;
}text_t;

typedef struct info_b_s {
    text_t champ[SIZE_CHAMP];
    text_t lives;
    text_t cycle;
}info_b_t;

typedef struct pause_s {
    int pause;
}pause_t;

typedef struct bonus_s {
    info_b_t inf;
    text_t vm[MEM_SIZE];
    sfFont *font;
    sfRenderWindow *window;
    sfEvent event;
}bonus_t;

void check_dead(bonus_t *all, corewar_t *core);
void color_champ(bonus_t *all, corewar_t *core, int i);
void color_pc(bonus_t *all, corewar_t *core);
void init_text(bonus_t *all, corewar_t *core);
void destroy_text(bonus_t *all, corewar_t *core);
int create_window(bonus_t *all);
void modif_registre(corewar_t *core, bonus_t *all);
void modif_cycles_lives(corewar_t *core, bonus_t *all);

#endif /* !BONUS_H_ */
