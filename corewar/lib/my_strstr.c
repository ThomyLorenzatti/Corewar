/*
** EPITECH PROJECT, 2020
** my_strstr
** File description:
** search an string into an other
*/

#include <stddef.h>

int my_strncmp(char const *s1, char const *to_find, int n);

int my_strlen(char const *str);

char *my_strstr(char *str, char const *to_find)
{
    if (*str == 0)
        return (NULL);
    if (my_strncmp(str, to_find, my_strlen(to_find) - 1) == 0)
        return (str);
    return (my_strstr(&str[1], to_find));
}