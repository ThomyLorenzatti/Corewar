/*
** EPITECH PROJECT, 2020
** B-CPE-201-MPL-2-1-corewar-thomy.lorenzatti
** File description:
** take_info.c
*/

#include "../include/my.h"
#include "../include/printf.h"
#include "../include/asm.h"

int parse_line(asm_t *all, int i)
{
    char **line_piece = my_str_to_word_array(all->input[i], '\"', '\n', '\n');
    for (int a = 0; line_piece[a] != NULL; a++) {
        if (my_strncmp(line_piece[a], ".name", 5) == 0 && line_piece[a + 1]) {
            if (my_strlen(line_piece[a + 1]) > PROG_NAME_LENGTH
            || all->is_name == 1)
                exit(84);
            all->name = my_super_strcpy(all->name, line_piece[a + 1]);
            all->is_name = 1;
        }
        if (my_strncmp(line_piece[a], ".comment", 8) == 0
        && line_piece[a + 1]) {
            if (my_strlen(line_piece[a + 1]) > COMMENT_LENGTH)
                exit (84);
            all->comment = my_super_strcpy(all->comment, line_piece[a + 1]);
        }
        free(line_piece[a]);
    }
    free(line_piece);
    return (0);
}

int take_every_bytes(asm_t *all)
{
    char_t *tmp = all->clist;
    char **arr_tmp;
    for (; tmp; tmp = tmp->next) {
        arr_tmp = my_str_to_word_array(tmp->value, '\t', ',', ' ');
        for (int i = 0; arr_tmp[i] != NULL; i++) {
            analyse_elem(all, arr_tmp[i]);
            free(arr_tmp[i]);
        }
        free(arr_tmp);
    }
    list_t *ltmp = all->list;
    for (; ltmp; ltmp = ltmp->next) {
        ltmp->value.nb = 0;
        ltmp->value.cycle = 0;
        for (int i = 0; op_tab[i].code != 0; i++) {
            if (my_strcmp(ltmp->value.elem, op_tab[i].mnemonique) == 0)
                ltmp->value.cycle = op_tab[i].nbr_cycles;
        }
    }
    return (0);
}

int take_info(asm_t *all)
{
    int i = 0;
    all->part = 0;
    all->list = NULL;
    all->clist = NULL;
    format_input(all);
    all->name = my_memset(all->name, '\0', PROG_NAME_LENGTH);
    all->comment = my_memset(all->comment, '\0', COMMENT_LENGTH);
    for (; all->input[i] != NULL; i++) {
        parse_line(all, i);
        if (all->input[i][0] != '.' &&
        all->input[i][0] != '\t' && all->input[i][0] != '\n') {
            char_list_push_back(&all->clist, all->input[i]);
            char_list_push_back(&all->clist, "=====");
        }
    }
    if (take_every_bytes(all) == 84)
        return (84);
    if (take_byte_value(all) == 84)
        return (84);
    return (0);
}