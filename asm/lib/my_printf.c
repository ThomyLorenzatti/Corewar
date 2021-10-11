/*
** EPITECH PROJECT, 2020
** my_printf
** File description:
** my_printf.c
*/

#include "my.h"
#include <stdarg.h>
#include <unistd.h>
#include "printf.h"
#include <stdio.h>

static array_t fonction[] = {
    {'d', my_is_number},
    {'i', my_is_number},
    {'s', my_is_str},
    {'c', my_is_char},
    {'b', my_is_binaire},
    {'x', my_is_hexa},
    {'X', my_is_hexa_maj},
    {'o', my_is_octal},
    {'%', my_is_modulo},
    {'u', my_is_unsigned},
    {'S', my_is_printable},
    {'p', my_is_ptr_address}
};

static array_t2 more_func[] = {
    {'h','d', my_is_number},
    {'h','i', my_is_number},
    {'h','o', my_is_octal},
    {'h','u', my_is_unsigned},
    {'h','x', my_is_hexa},
    {'h','X', my_is_hexa_maj},
    {'l','d', my_is_number},
    {'l','i', my_is_number},
    {'l','o', my_is_octal},
    {'l','u', my_is_unsigned},
    {'l','x', my_is_hexa},
    {'l','X', my_is_hexa_maj}
};

variable_t my_printf_more_condition(char const *text, int *i, variable_t v)
{
    if (text[*i] == '#') {
        v.hashtag = 1;
        *i += 1;
    }
    return (v);
}

variable_t my_printf_condition(char const *text, int *i, variable_t v)
{
    if (text[*i] == ' ') {
        v.space = 1;
        my_putchar(' ');
        *i += 1;
    }
    v = my_printf_more_condition(text, &*i, v);
    if (text[*i] == '-') {
        v.negative = -1;
        *i += 1;
    }
    if (text[*i] == '0') {
        v.c = '0';
        v.len = 0;
    } else v.c = ' ';
    return (v);
}

variable_t my_printf_more(char const *text, int *i)
{
    variable_t v = {1, 0};
    int len_nb = 0;
    v = my_printf_condition(text, &*i, v);
    for (int m = *i; text[m] >= 47 && text[m] <= 57; m++) {
        v.nb = (text[m] - 48) + v.nb * 10;
        *i += 1;
        v.len_nb += 1;
    }
    if (v.nb == 0) {
        return (v);
    }
    return (v);
}

int my_printf_bis(int i, char const *text, va_list ap)
{
    variable_t v;
    v = my_printf_more(text, &i);
    for (int m = 0; m < ARRAY_SIZE; m += 1) {
        if (text[i] == fonction[m].c) {
            fonction[m].ptr(ap, v);
            return (i);
        }
    }
    for (int m = 0; m < ARRAY_SIZE2; m += 1) {
        if (text[i] == more_func[m].c) {
            if (text[i + 1] == more_func[m].f && text[i + 1] != '\0') {
                more_func[m].ptr(ap, v);
                return (i + 1);
            }
        }
    }
}

int my_printf(char const *text, ...)
{
    va_list ap;
    va_start(ap, text);
    for (int i = 0; text[i] != '\0'; i += 1) {
        if (text[i] == '%' && text[i + 1] != '\0') {
            i += 1;
            i = my_printf_bis(i, text, ap);
        } else {
            my_putchar(text[i]);
        }
    }
    va_end(ap);
    return (0);
}