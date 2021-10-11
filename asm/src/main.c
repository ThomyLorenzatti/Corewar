/*
** EPITECH PROJECT, 2020
** lib
** File description:
** main.c
*/

#include "../include/my.h"
#include "../include/printf.h"
#include "../include/asm.h"

void do_help(void)
{
    my_printf("USAGE\n./asm file_name[.s]\nDESCRIPTION\nfile_name ");
    my_printf("file in assembly language to be converted into file_name.cor, ");
    my_printf("an executable in the Virtual Machine.\n");
}

void destroy_all(asm_t *all)
{
    for (int i = 0; all->input[i] != NULL; i++)
        free(all->input[i]);
    free(all->input);
    free(all->name);
    free(all->comment);
    char_list_destroy(&all->clist);
    obj_list_destroy(&all->list);
}

int main(int ac, char **av)
{
    asm_t all;
    all.is_name = 0;
    if (ac != 2)
        return (84);
    if (av[1][0] == '-' && av[1][1] == 'h') {
        do_help();
        return (0);
    }
    all.input = load_file(av[1]);
    if (take_info(&all) == 84)
        return (84);
    if (check_error(&all) == 84)
        return (84);
    all.fd = create_file(&all, av[1]);
    if (printer(&all) == 84)
        return (84);
    destroy_all(&all);
    return (0);
}