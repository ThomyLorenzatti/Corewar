/*
** EPITECH PROJECT, 2020
** corewar
** File description:
** converte_base.c
*/

#include "../include/my.h"

int base_power(char const *base_from, int i, char const *nbr)
{
    int len = my_strlen(base_from);
    int nb = 1;
    int p = len - i;

    while (i > 0) {
        nb *= len;
        i--;
    }
    return (nb);
}

int convert_to_dec(char const *nbr, char const *base_from, int i, int nb_d)
{
    int len_base = my_strlen(base_from);
    int len = my_strlen(nbr);
    int nb = base_power(base_from, i, nbr);
    int correct = 0;

    for (int j = 0; j < len_base; j++) {
        if (nbr[len - i - 1] == base_from[j])
            nb_d += nb * j;
    }
    return (nb_d);
}

int get_size_base(int nb_decimal, char const *base_to, int i, char *nbr_base)
{
    int len = my_strlen(base_to);
    int a = 0;
    int end = 0;

    if (nb_decimal == 0) {
        end = 1;
        return (i);
    }
    get_size_base(nb_decimal / len, base_to, i + 1, nbr_base);
}

char *go_to_base(int nb_decimal, char const *base_to, int i, char *nbr_base)
{
    int len = my_strlen(base_to);
    int a = 0;
    if (i == 0) {
        return (nbr_base);
    }
    nbr_base[i - 1] = base_to[nb_decimal % len];
    if (i > 0) {
        go_to_base(nb_decimal / len, base_to, i - 1, nbr_base);
    }
}

char *convert_base(char const *nbr, char const *bas_from, char const *bas_to)
{
    char *number = my_strdup((char *) nbr);
    int neg = nbr[0] == '-' ? 1 : 0;
    int len = my_strlen(nbr);
    int nb_decimal = 0;
    int i = neg == 1 ? 1 : 0;
    char *nbr_base = NULL;

    for (int i = 0; i < len; i++) {
        nb_decimal = convert_to_dec(number + neg, bas_from, i, nb_decimal);
    }
    i = get_size_base(nb_decimal, bas_to, i, nbr_base);
    nbr_base = malloc(sizeof(char) * (i + 1));
    nbr_base[i] = '\0';
    nbr_base = go_to_base(nb_decimal, bas_to, i, nbr_base);
    if (neg == 1) {
        nbr_base[0] = '-';
    }
    return (nbr_base);
}