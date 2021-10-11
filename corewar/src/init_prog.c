/*
** EPITECH PROJECT, 2020
** corewar
** File description:
** init_prog.c
*/

#include "../include/corewar.h"
#include "../include/my.h"

int open_prog(list_prog_t *list, char *buff, int number)
{
    int fd;

    list->head = malloc(sizeof(header_t));
    fd = open(buff, O_RDONLY);
    if (read(fd, list->head, sizeof(header_t)) == -1)
        return (84);
    list->head->prog_size = lit_to_big_endian(list->head->prog_size);
    list->champ = malloc(sizeof(char) * list->head->prog_size);
    if (read(fd, list->champ, list->head->prog_size) == -1)
        return (84);
    list->info.prog_name = list->head->prog_name;
    list->info.prog_number = number;
    list->live = 1;
    list->child = NULL;
    list->parent = NULL;
    close(fd);
    return (0);
}

int insert_list(corewar_t *core, char **av)
{
    int number = 1;

    core->list_prog = NULL;
    for (int i = 1; av[i] != NULL; i++)
        init_push_back(&core->list_prog, av[i]);
    for (list_prog_t *tmp = core->list_prog; tmp != NULL; tmp = tmp->next) {
        if (open_prog(tmp, tmp->info.prog_name, number) == 84)
            return (84);
        core->nbr_prog++;
        number++;
    }
    return (0);
}

void load_champ(corewar_t *core)
{
    int sep = 0;
    int i = 0;
    int a = 0;
    int m = 0;

    for (list_prog_t *tmp = core->list_prog; tmp != NULL; tmp = tmp->next)
        sep += tmp->head->prog_size;
    sep = (MEM_SIZE - sep) / core->nbr_prog;
    for (list_prog_t *tmp = core->list_prog; tmp != NULL; tmp = tmp->next) {
        tmp->info.load_address = core->vm[i + a];
        core->prog_num[m] = tmp->registre[0];
        for (a = 0; a < tmp->head->prog_size; a++) {
            core->vm[i + a] = tmp->champ[a];
            core->func_info[i + a].id = tmp->registre[0];
            if (a == 0)
                pc_push_back(&tmp->pc, i + a, tmp->registre[0]);
        }
        m++;
        i += a + sep;
    }
}