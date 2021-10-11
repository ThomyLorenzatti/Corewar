/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** hex_toi_int.c
*/

#include "my.h"

int my_pow(int nb, int y)
{
    int res = 1;

    while (y > 0) {
        res *= nb;
        y -= 1;
    }
    return (res);
}

int hex_to_int(char *hex)
{
    char *str = "123456789abcdef";
    int result = 0;
    int nb = 0;
    for (nb = 0; hex[nb] != '\0'; nb += 1) {
    if (hex[nb] >= 'A' && hex[nb] <= 'F')
        hex[nb] = hex[nb] + 32;
    }
    nb -= 1;
    for (int i = 0; hex[i] != '\0'; i += 1) {
        for (int a = 0; str[a] != '\0'; a += 1) {
            if (hex[i] == str[a]) {
                result += (a + 1) * my_pow(16, nb);
            }
        }
        nb -= 1;
    }
    return (result);
}

int hex_to_int2(char hex)
{
    int y = 0;
    int dec = 0;
    int x = 0;

    if (hex >= '0' && hex <= '9')
        x = hex - '0';
    else
        x = hex - 'A' + 10;
    dec = dec + x * my_pow(16, y);
    return dec;
}