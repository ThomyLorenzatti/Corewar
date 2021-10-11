/*
** EPITECH PROJECT, 2020
** corewar
** File description:
** push_back.c
*/

#include "../include/corewar.h"
#include "../include/my.h"

void init_push_back(list_prog_t **list, char *str)
{
    list_prog_t *node = malloc(sizeof(*node));
    list_prog_t *temp;
    int i = 1;

    for (int a = 0; a < 16; a++)
        node->registre[a] = 0;
    node->info.prog_name = str;
    node->carry = 0;
    node->child = NULL;
    if ((*list) == NULL) {
        node->registre[0] = i;
        (*list) = node;
    } else {
        for (temp = (*list); temp->next != NULL; temp = temp->next, i++);
        node->registre[0] = i + 1;
        temp->next = node;
    }
}

void back_child_bis(list_prog_t *node, list_prog_t **list, char *str, int p)
{
    for (int a = 0; a < 16; a++)
        node->registre[a] = 0;
    node->info.prog_name = str;
    node->pc.ptr = p;
    node->pc.id = (*list)->pc.id;
    node->pc.cycle = 0;
    node->live = 1;
    node->parent = (*list);
    node->next = NULL;
    node->carry = 0;
}

void init_push_back_child(list_prog_t **list, char *str, int *registre, int p)
{
    list_prog_t *node = malloc(sizeof(*node));
    list_prog_t *temp;
    int i = 1;

    back_child_bis(node, list, str, p);
    for (int a = 0; a < 16; a += 1)
        node->registre[a] = registre[a];
    if ((*list)->child == NULL)
        (*list)->child = node;
    else {
        for (temp = (*list)->child; temp->next != NULL; temp = temp->next, i++);
        temp->next = node;
    }
}

void pc_push_back(pc_t *pc, int ptr, int id)
{
    pc->id = id;
    pc->ptr = ptr;
    pc->cycle = 0;
}