/*
** EPITECH PROJECT, 2020
** lib
** File description:
** my_print_error.c
*/

#include "my.h"
#include <unistd.h>

void my_print_error(char *str)
{
    int s = my_strlen(str);
    write(2, str, s);
}