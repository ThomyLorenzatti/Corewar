/*
** EPITECH PROJECT, 2020
** B-CPE-201-MPL-2-1-corewar-thomy.lorenzatti
** File description:
** printer.c
*/

#include "../include/my.h"
#include "../include/printf.h"
#include "../include/asm.h"

unsigned int lit_to_big_endian(unsigned int x)
{
    return (((x >> 24) & 0x000000ff) | ((x >> 8) & 0x0000ff00) |
    ((x << 8) & 0x00ff0000) | ((x << 24) & 0xff000000));
}

void print_list2(asm_t *all, int nb)
{
    nb = lit_to_big_endian(nb);
    nb = (nb << 16) | (nb >> 16);
    write(all->fd, &nb, 2);
}

void print_list(asm_t *all)
{
    list_t *tmp = all->list;
    int count = 4;
    int total = 0;
    for (; tmp; tmp = tmp->next) {
        if (my_strcmp(tmp->value.elem, "=====") == 0) count = 4;
        if (tmp->value.cycle >= 20 &&
        (tmp->value.type == OP_FUNC || tmp->value.type == FUNC))
            count = 2;
        if (tmp->value.type == REG ||
        tmp->value.type == OP_CODE || tmp->value.type == OP_FUNC
        || tmp->value.type == FUNC) write(all->fd, &tmp->value.nb, 1);
        if (tmp->value.type == IND)
            print_list2(all, tmp->value.nb);
        if (tmp->value.type == DIRT) {
            tmp->value.nb = lit_to_big_endian(tmp->value.nb);
            if (count == 2)
                tmp->value.nb = (tmp->value.nb << 16) | (tmp->value.nb >> 16);
            write(all->fd, &tmp->value.nb, count);
        }
    }
}

int printer(asm_t *all)
{
    unsigned int magic = COREWAR_EXEC_MAGIC;
    int complete = 0;
    int test = 11;
    int byte = all->byte_len;
    magic = lit_to_big_endian(magic);
    write(all->fd, &magic, 4);
    write(all->fd, all->name, PROG_NAME_LENGTH);
    write(all->fd, &complete, 4);
    write(all->fd, &complete, 3);
    write(all->fd, &byte, 1);
    write(all->fd, all->comment, COMMENT_LENGTH);
    write(all->fd, &complete, 4);
    print_list(all);
    return (0);
}