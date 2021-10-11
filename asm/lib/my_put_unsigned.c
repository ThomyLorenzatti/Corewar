/*
** EPITECH PROJECT, 2020
** my_printf
** File description:
** my_put_unsigned.c
*/

#include "my.h"
#include <unistd.h>

int my_put_unsigned(unsigned int nb)
{
    if (nb > 9) {
        my_put_unsigned(nb / 10);
        my_put_unsigned(nb % 10);
    } else
        my_putchar(nb + '0');
    return (0);
}
