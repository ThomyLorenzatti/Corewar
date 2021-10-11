/*
** EPITECH PROJECT, 2020
** matchstick
** File description:
** my_memset.c
*/

#include <stdlib.h>

char *my_memset(char *str, char c, int size)
{
    str = malloc(sizeof(char) * size);
    for (int i = 0; i < size; i++)
        str[i] = c;
    return (str);
}