/*
** EPITECH PROJECT, 2020
** corewar
** File description:
** my_int_str.c
*/

#include "my.h"

void int_str_bis(int p, int nb, char *str, int *m)
{
    int i = 0;

    while (p < 2) {
        if (nb / m[p] >= 0) {
            str[i] = ((nb / m[p]) + 48);
            nb = nb - (nb / m[p]) * m[p];
            i += 1;
        }
        p++;
    }
    str[i] = '\0';
}

void my_int_str(char *str, int nb, int size)
{
    int p = size;
    int tmp = 1;
    int *m = malloc(sizeof(int) * p);
    for (int a = 1; a < p; a += 1)
        tmp *= 10;
    for (int a = 0; a < p; a += 1) {
        m[a] = tmp;
        tmp = tmp / 10;
    }
    p = 0;
    int_str_bis(p, nb, str, m);
}