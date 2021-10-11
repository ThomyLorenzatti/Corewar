/*
** EPITECH PROJECT, 2020
** my_sokoban
** File description:
** super_strlen.c
*/

#include <stdlib.h>

int super_strlen(char **str)
{
    int i = 0;
    for (i = 0; str[i] != NULL; i++);
    return (i);
}
