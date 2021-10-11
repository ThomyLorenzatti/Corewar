/*
** EPITECH PROJECT, 2020
** my_atoi
** File description:
** my_atoi
*/

#include "my.h"

int my_atoi(char const *str)
{
    int i = 0;
    int negative = 0;
    while (*str) {
        if (*str >= '0' && *str <= '9') {
            i = i * 10;
            i = i + (*str - '0');
        } else if (*str == '-') {
            negative = 1;
        } else {
            return (i);
        }
        str++;
    }
    if (negative == 1)
        return (i * -1);
    return (i);
}