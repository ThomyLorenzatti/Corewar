/*
** EPITECH PROJECT, 2020
** BSQ
** File description:
** get_nb_words.c
*/

#include "my.h"

int check(const char str, const char *separator)
{
    int m = 0;
    int i = 0;
    for (;separator[i] != '\0'; i++) {
        if (str == separator[i])
            m = m + 1;
    }
    return (m);
}

int get_nb_words(const char *str, const char *separator)
{
    int i = 0;
    int m = 0;
    int compteur = 0;
    for (; str[i] != '\0'; i++) {
        for (m = 0; separator[m] != '\0'; m++) {
            if (str[i] == separator[m] && (check(str[i-1], separator) == 0))
                compteur = compteur + 1;
        }
    }
    return (compteur);
}