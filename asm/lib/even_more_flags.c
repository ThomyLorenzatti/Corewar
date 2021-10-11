/*
** EPITECH PROJECT, 2020
** my_printf
** File description:
** even_more_flags.c
*/

#include "my.h"
#include "printf.h"
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

struct t_variable {
    long long temp;
    int i;
    int m;
    int temps;
    int nombre;
};

void my_is_ptr_address(va_list ap, variable_t v)
{
    long long nbr = va_arg(ap, long long);
    char *base = "0123456789abcdef";
    struct t_variable t = {1, 0};
    char *str = malloc(sizeof(char *) * 10);
    v.len = my_long_len(nbr);
    if (v.nb < v.len) v.nb = 0;
    else v.nb = (v.nb - v.len - v.space) * v.negative;
    if (v.nb > 0) my_put_spaces(v);
    for (; nbr >= 1 || t.i == 0; t.i += 1) {
        t.temp = nbr % 16;
        if (t.temp >= 10) str[t.i] = base[t.temp];
        else str[t.i] = base[t.temp];
        nbr = nbr / 16;
    }
    str[t.i] = '\0';
    my_putstr("0x");
    my_putstr(my_revstr(str));
    if (v.nb < 0) my_put_spaces(v);
    free(str);
}

int my_long_len(long int nb)
{
    int b = 0;
    if (nb < 0)
        nb *= (-1);
    for (; nb > 0; nb /= 10)
        b += 1;
    return (b);
}

char *my_is_hexa_maj_bis(char *str, unsigned int nbr)
{
    unsigned int temp = 0;
    int i = 0;
    for (; nbr >= 1; i += 1) {
        temp = nbr % 16;
        if (temp >= 10) str[i] = temp + 55;
        else str[i] = temp + 48;
        nbr = nbr / 16;
    }
    str[i] = '\0';
    return (str);
}

char *my_is_hexa_bis(char *str, unsigned int nbr)
{
    unsigned int temp = 0;
    int i = 0;
    for (; nbr >= 1; i += 1) {
        temp = nbr % 16;
        if (temp >= 10) str[i] = temp + 87;
        else str[i] = temp + 48;
        nbr = nbr / 16;
    }
    str[i] = '\0';
    return (str);
}

variable_t my_is_printable_bis_check(variable_t v)
{
    if (v.nb < v.len) v.nb = 0;
    else v.nb = (v.nb - v.len - v.space) * v.negative;
    if (v.nb > 0) my_put_spaces(v);
    return (v);
}