/*
** EPITECH PROJECT, 2020
** my_printf
** File description:
** my_printf.h
*/

#include <stdarg.h>

#ifndef __PRINTF_H__
#define __PRINTF_H__

#define ARRAY_SIZE 12
#define ARRAY_SIZE2 12

typedef struct variable {
    int negative;
    int len;
    int len_nb;
    int nb;
    char c;
    int space;
    int hashtag;
}variable_t;

typedef struct array_t {
    char c;
    void(*ptr)(va_list, variable_t v);
}array_t;

typedef struct array_t2 {
    char c;
    char f;
    void(*ptr)(va_list, variable_t v);
}array_t2;

int my_put_unsigned(unsigned int nb);
int my_int_len(int nb);
int my_unsigned_int_len(unsigned int nb);
int my_long_len(long int nb);
char *my_is_hexa_maj_bis(char *str, unsigned int nbr);
char *my_is_hexa_bis(char *str, unsigned int nbr);
void my_is_str(va_list ap, variable_t v);
void my_is_number(va_list ap, variable_t v);
void my_is_char(va_list ap, variable_t v);
void my_is_binaire(va_list ap, variable_t v);
void my_is_hexa(va_list ap, variable_t v);
void my_is_hexa_maj(va_list ap, variable_t v);
void my_is_octal(va_list ap, variable_t v);
void my_is_modulo(va_list ap, variable_t v);
void my_is_unsigned(va_list ap, variable_t v);
void my_is_printable(va_list ap, variable_t v);
void my_is_ptr_address(va_list ap, variable_t v);
void my_is_short_number(va_list ap, variable_t v);
void my_put_spaces(variable_t v);
variable_t my_is_printable_bis_check(variable_t v);
void my_put_hashtag(variable_t v);
void my_is_printable_bis(char *src, variable_t v);

#endif