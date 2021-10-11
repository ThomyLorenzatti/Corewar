/*
** EPITECH PROJECT, 2020
** my_printf
** File description:
** many_flags.c
*/

#include "my.h"
#include "printf.h"
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

void my_is_printable_bis(char *src, variable_t v)
{
    int p = 0;
    my_putchar('\\');
    my_revstr(src);
    p = my_strlen(src);
    for (; p < 3; p++)
        my_putchar('0');
    my_putstr(src);
    if (v.nb < 0)
        my_put_spaces(v);
}

int my_int_len(int nb)
{
    int b = 0;
    if (nb < 0)
        nb *= (-1);
    for (; nb > 0; nb /= 10)
        b += 1;
    return (b);
}

int my_unsigned_int_len(unsigned int nb)
{
    unsigned int b = 0;
    for (; nb > 1; nb /= 10)
        b += 1;
    return (b);
}

void my_put_hashtag(variable_t v)
{
    if (v.hashtag == 1)
        my_putchar('0');
    if (v.hashtag == 2)
        my_putstr("0x");
    if (v.hashtag == 3)
        my_putstr("0X");
}

void my_put_spaces(variable_t v)
{
    if (v.len == (v.nb * -1))
        return;
    if (v.len + v.space == (v.nb * -1))
        return;
    if (v.len + v.space + v.hashtag == (v.nb * -1))
        return;
    if (v.c == ' ') {
        for (;v.nb > 0; v.nb -= 1)
            my_putchar(' ');
        for (;v.nb < 0; v.nb += 1)
            my_putchar(' ');
    } else if (v.c == '0'){
        for (;v.nb > 0; v.nb -= 1)
            my_putchar('0');
    }
}