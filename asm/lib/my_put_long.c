/*
** EPITECH PROJECT, 2020
** Boostrap_my_ls
** File description:
** my_put_long.c
*/

#include <unistd.h>
#include "my.h"

int my_put_long(unsigned long int nb)
{
    if (nb > 9) {
        my_put_nbr(nb / 10);
        my_put_nbr(nb % 10);
    } else
        my_putchar(nb + '0');
    return (0);
}