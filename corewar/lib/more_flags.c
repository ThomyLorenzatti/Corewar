/*
** EPITECH PROJECT, 2020
** my_printf
** File description:
** more_flags.c
*/

#include "my.h"
#include "printf.h"
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

struct t_variable {
    int i;
    int m;
    int temps;
    int nombre;
    int calcul;
};

void my_is_hexa_maj(va_list ap, variable_t v)
{
    struct t_variable t = {0};
    unsigned int nbr = va_arg(ap, unsigned int);
    v.len = my_unsigned_int_len(nbr);
    char *str = malloc(sizeof(char *) * nbr);
    if (v.hashtag == 1) v.hashtag = 2;
    if (v.nb < v.len) v.nb = 0;
    else v.nb = (v.nb - v.len - v.space - v.hashtag) * v.negative;
    t.calcul = (v.len + v.space + v.hashtag) * -1;
    if (v.nb > 0 || t.calcul == v.nb) my_put_spaces(v);
    if (v.hashtag == 2) v.hashtag = 3;
    my_put_hashtag(v);
    str = my_is_hexa_maj_bis(str, nbr);
    str = my_revstr(str);
    my_putstr(str);
    if (v.nb < 0 && t.calcul != v.nb) my_put_spaces(v);
    free(str);
}

void my_is_octal(va_list ap, variable_t v)
{
    struct t_variable t = {0};
    unsigned int temp = 1;
    unsigned int nbr = va_arg(ap, unsigned int);
    char *str = malloc(sizeof(char *) * nbr);
    v.len = my_unsigned_int_len(nbr);
    if (v.nb < v.len) v.nb = 0;
    else v.nb = (v.nb - v.len - v.space - v.hashtag) * v.negative;
    t.calcul = (v.len + v.space + v.hashtag) * -1;
    if (v.nb > 0 || t.calcul == v.nb) my_put_spaces(v);
    my_put_hashtag(v);
    for (; nbr > 0; t.i++) {
        temp = nbr % 8;
        str[t.i] = temp + 48;
        nbr = nbr / 8;
    }
    str[t.i] = '\0';
    my_revstr(str);
    my_putstr(str);
    if (v.nb < 0 && t.calcul != v.nb) my_put_spaces(v);
    free(str);
}

void my_is_modulo(va_list ap, variable_t v)
{
    ((void)ap);
    my_putchar('%');
}

void my_is_unsigned(va_list ap, variable_t v)
{
    int nbr = va_arg(ap, unsigned int);
    v.len = my_int_len(nbr);
    if (v.nb < v.len) v.nb = 0;
    else v.nb = (v.nb - v.len - v.space) * v.negative;
    if (v.nb > 0)
        my_put_spaces(v);
    my_put_unsigned(nbr);
    if (v.nb < 0) my_put_spaces(v);
}

void my_is_printable(va_list ap, variable_t v)
{
    struct t_variable t = {0};
    char *str = va_arg(ap, char *);
    char *src = malloc(sizeof(char *) * my_strlen(str));
    v.len = my_strlen(str);
    v = my_is_printable_bis_check(v);
    for (; str[t.i] != '\0'; t.i += 1) {
        if (str[t.i] >= 32 && str[t.i] < 127) my_putchar(str[t.i]);
        else {
            t.nombre = str[t.i];
            for (; t.nombre > 0; t.m += 1) {
                t.temps = t.nombre % 8;
                src[t.m] = t.temps + 48;
                t.nombre = t.nombre / 8;
            }
            my_is_printable_bis(src, v);
            t.m = 0;
        }
    }
    if (v.nb < 0) my_put_spaces(v);
    free(src);
}