/*
** EPITECH PROJECT, 2020
** B-CPE-201-MPL-2-1-corewar-thomy.lorenzatti
** File description:
** error.c
*/

#include "../include/my.h"
#include "../include/printf.h"
#include "../include/asm.h"

int check_label_error(asm_t *all, object_t *tmp)
{
    list_t *ltmp = all->list;
    for (; ltmp; ltmp = ltmp->next) {
        if (my_strcmp(ltmp->value.elem, tmp->elem) == 0)
            break;
    }
    ltmp = ltmp->next;
    for (; ltmp; ltmp = ltmp->next) {
        if (my_strcmp(ltmp->value.elem, tmp->elem) == 0)
            exit (84);
    }
}

int check_quote(char *str)
{
    int nb = 0;
    for (int i = 0; str[i]; i++) {
        if (str[i] == '"')
            nb += 1;
    }
    if (nb != 2)
        return (84);
    return (0);
}

int check_intstruction_before_b(asm_t *all)
{
    int name_pass = 0;
    int com_pass = 0;
    for (int i = 0; all->input[i] != NULL; i++) {
        if (my_strncmp(all->input[i], ".name", 5) == 0)
            name_pass = 1;
        if (my_strncmp(all->input[i], ".comment", 8) == 0)
            com_pass = 1;
        if (name_pass == 0 && com_pass == 1)
            return (84);
    }
    return (0);
}

int check_instruction_before(asm_t *all)
{
    int name_pass = 0;
    int com_pass = 0;
    com_pass = (all->is_comment == 0) ? 1 : 0;
    for (int i = 0; all->input[i] != NULL; i++) {
        if (all->input[i][0] == '#')
            continue;
        if (my_strncmp(all->input[i], ".name", 5) == 0)
            name_pass = 1;
        if (my_strncmp(all->input[i], ".comment", 8) == 0)
            com_pass = 1;
        if (all->input[i][0] != '.' && all->input[i][0] != ' '
        && all->input[i][0] != '\t' && all->input[i][0] != '\n'
        && (name_pass == 0 || com_pass == 0))
            return (84);
    }
    if (check_intstruction_before_b(all) == 84)
        return (84);
}

int check_error(asm_t *all)
{
    all->is_comment = 0;
    if (all->is_name == 0)
        exit (84);
    for (int i = 0; all->input[i] != NULL; i++) {
        if ((my_strncmp(all->input[i], ".name", 5) == 0 ||
        my_strncmp(all->input[i], ".comment", 8) == 0) &&
        all->input[i][my_strlen(all->input[i]) - 2] != '"')
            return (84);
        if ((my_strncmp(all->input[i], ".name", 5) == 0 ||
        my_strncmp(all->input[i], ".comment", 8) == 0) &&
        check_quote(all->input[i]) == 84)
            return (84);
        if (my_strncmp(all->input[i], ".comment", 8) == 0)
            all->is_comment = 1;
    }
    if (check_instruction_before(all) == 84)
        return (84);
    return (0);
}