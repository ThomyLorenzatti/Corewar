/*
** EPITECH PROJECT, 2020
** B-CPE-201-MPL-2-1-corewar-thomy.lorenzatti
** File description:
** list_utils.c
*/

#include "../include/my.h"
#include "../include/printf.h"
#include "../include/asm.h"

void obj_list_push_back(list_t **list, object_t value)
{
    list_t *node = malloc(sizeof(*node));
    list_t *temp;

    node->value = value;
    node->next = NULL;
    if ((*list) == NULL)
        (*list) = node;
    else {
        for (temp = (*list); temp->next != NULL; temp = temp->next);
        temp->next = node;
    }
}

void char_list_push_back(char_t **list, char *value)
{
    char_t *node = malloc(sizeof(*node));
    char_t *temp;

    node->value = value;
    node->next = NULL;
    if ((*list) == NULL)
        (*list) = node;
    else {
        for (temp = (*list); temp->next != NULL; temp = temp->next);
        temp->next = node;
    }
}

void char_list_destroy(char_t **list)
{
    char_t *node = (*list);
    char_t *tmp = NULL;

    while (node != NULL) {
        tmp = node->next;
        free(node);
        node = tmp;
    }
}

void obj_list_destroy(list_t **list)
{
    list_t *node = (*list);
    list_t *tmp = NULL;

    while (node != NULL) {
        free(node->value.elem);
        tmp = node->next;
        free(node);
        node = tmp;
    }
}