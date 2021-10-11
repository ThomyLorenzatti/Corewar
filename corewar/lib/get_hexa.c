/*
** EPITECH PROJECT, 2020
** corewar
** File description:
** get_hexa.c
*/

#include "my.h"

char *get_hexa(unsigned int nbr)
{
    unsigned int temp = 0;
    char *str = malloc(sizeof(char) * 3);

    if (nbr == 0) {
        str[0] = '0';
        str[1] = '0';
    }
    if (nbr < 16) {
        str[1] = '0';
    }
    for (int i = 0; nbr >= 1; i += 1) {
        temp = nbr % 16;
        if (temp >= 10) str[i] = temp + 55;
        else str[i] = temp + 48;
        nbr = nbr / 16;
    }
    str[2] = '\0';
    my_revstr(str);
    return (str);
}

void get_hexa2_bis(unsigned int nbr, char *str)
{
    if (nbr == 0) {
        str[0] = '0';
        str[1] = '0';
    }
    if (nbr < 16) {
        str[1] = '0';
    }
}

char *get_hexa2(unsigned int nbr, int size)
{
    unsigned int temp = 0;
    char *str = malloc(sizeof(char) * (size * 2));
    int i = 0;

    get_hexa2_bis(nbr, str);
    for (i = 0; nbr >= 1; i += 1) {
        temp = nbr % 16;
        if (temp >= 10) str[i] = temp + 55;
        else str[i] = temp + 48;
        nbr = nbr / 16;
    }
    if (my_strlen(str) < size * 2) {
        for (; i < size * 2; i++)
            str[i] = '0';
    }
    str[i] = '\0';
    my_revstr(str);
    return (str);
}