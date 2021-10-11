/*
** EPITECH PROJECT, 2020
** my_printf
** File description:
** flags.c
*/

#include "my.h"
#include "printf.h"
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

struct t_variable {
    int calcul;
    int i;
    unsigned int temp;
};

void my_is_str(va_list ap, variable_t v)
{
    char *str = va_arg(ap, char *);
    v.len = my_strlen(str);
    if (v.nb < v.len) v.nb = 0;
    else v.nb = (v.nb - v.len - v.space) * v.negative;
    if (v.nb > 0)
        my_put_spaces(v);
    my_putstr(str);
    if (v.nb < 0)
        my_put_spaces(v);
}

void my_is_number(va_list ap, variable_t v)
{
    int nbr = va_arg(ap, int);
    v.len = my_int_len(nbr);
    if (v.nb < v.len) v.nb = 0;
    else v.nb = (v.nb - v.len - v.space) * v.negative;
    if (v.nb > 0)
        my_put_spaces(v);
    my_put_nbr(nbr);
    if (v.nb < 0)
        my_put_spaces(v);
}

void my_is_char(va_list ap, variable_t v)
{
    char c = va_arg(ap, int);
    v.len = v.len + 1;
    if (v.nb < v.len) v.nb = 0;
    else v.nb = (v.nb - v.len - v.space) * v.negative;
    if (v.nb > 0)
        my_put_spaces(v);
    write(1, &c, 1);
    if (v.nb < 0)
        my_put_spaces(v);
}

void my_is_binaire(va_list ap, variable_t v)
{
    unsigned int nbr = va_arg(ap, unsigned int);
    unsigned int i = 0;
    unsigned int temp = 0;
    char *str = malloc(sizeof(char *) * nbr);
    v.len = my_unsigned_int_len(nbr);
    if (v.nb < v.len) v.nb = 0;
    else v.nb = (v.nb - v.len - v.space) * v.negative;
    if (v.nb > 0) my_put_spaces(v);
    for (; nbr > 0; i++) {
        temp = nbr % 2;
        str[i] = temp + 48;
        nbr = nbr / 2;
    }
    my_revstr(str);
    my_putstr(str);
    if (v.nb < 0) my_put_spaces(v);
    free(str);
}

void my_is_hexa(va_list ap, variable_t v)
{
    struct t_variable t = {0};
    unsigned int nbr = va_arg(ap, unsigned int);
    char *str = malloc(sizeof(char *) * nbr);
    v.len = my_unsigned_int_len(nbr);
    if (v.hashtag == 1) v.hashtag = 2;
    if (v.nb < v.len) v.nb = 0;
    else v.nb = (v.nb - v.len - v.space - v.hashtag) * v.negative;
    t.calcul = (v.len + v.space + v.hashtag) * -1;
    if (v.nb > 0 || t.calcul == v.nb) my_put_spaces(v);
    my_put_hashtag(v);
    str = my_is_hexa_bis(str, nbr);
    str = my_revstr(str);
    my_putstr(str);
    if (v.nb < 0 && t.calcul != v.nb) my_put_spaces(v);
    free(str);
}