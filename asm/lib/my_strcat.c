/*
** EPITECH PROJECT, 2020
** my_strcat
** File description:
** copy a string after an other
*/

#include "my.h"

char *my_strcat2(char *dest, char const *src)
{
    int i = 0;
    int a = 0;

    for (; dest[i]; i++);
    for (; src[i]; i++, a++) {
        dest[i] = src[a];
    }
    return (dest);
}

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int size = 0;
    char *str = malloc(sizeof(char) * (my_strlen(dest) + my_strlen(src) + 2));

    for (; dest[size] != '\0'; size++)
        str[size] = dest[size];

    while (src[i] != '\0') {
        str[size + i] = src[i];
        i++;
    }
    str[size + i] = '\0';
    return (str);
}
