/*
** EPITECH PROJECT, 2020
** corewar
** File description:
** binary_hex.c
*/

#include "my.h"

int binary_to_int(int bin)
{
    int hex = 0;
    int i = 1;
    int tmp;

    while (bin != 0) {
        tmp = bin % 10;
        hex = hex + tmp * i;
        i = i * 2;
        bin = bin / 10;
    }
    return (hex);
}

char *int_binary(int nbr)
{
    unsigned int i = 0;
    unsigned int temp = 0;
    char *str = malloc(sizeof(char *) * 8);
    for (; nbr > 0; i++) {
        temp = nbr % 2;
        str[i] = temp + 48;
        nbr = nbr / 2;
    }
    if (my_strlen(str) == 7) {
        str[7] = '0';
    }
    my_revstr(str);
    if (my_strlen(str) < 8) {
        for (int i = my_strlen(str); i < 8; i++)
            str[i] = '0';
    }
    return (str);
}