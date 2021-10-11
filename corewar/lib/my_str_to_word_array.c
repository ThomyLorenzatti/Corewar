/*
** EPITECH PROJECT, 2020
** Projets
** File description:
** my_str_to_word_array.c
*/

#include "my.h"
#include <stdlib.h>
#include <unistd.h>

struct t_variable {
    int i;
    int m;
    int a;
    int b;
    int compteur;
    int p;
    int sep;
    int test;
};

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

char **str_bis(struct t_variable *v, char **tab, const char *str)
{
    int nb = 0;
    if (v->test == 1)
        tab[v->a] = NULL;
    else {
        for (nb = 0; tab[nb][0] != '\0'; nb++);
        if (str[0] == ' ' || str[0] == '\t') nb -= 1;
        tab[nb] = NULL;
    }
}

char **my_str_to_word_array(const char *str, char *separator)
{
    struct t_variable v = {0, 0, 0, 0, 0, 0, 0, 0};
    int nb = get_nb_words(str, separator) + 1;
    char **tab = NULL;
    tab = my_init_char_tab(tab, nb + 2, my_strlen(str));
    for (; str[v.i] != '\0'; v.i++) {
        v.sep = v.compteur;
        for (v.m = 0; separator[v.m] != '\0'; v.m++)
            if (str[v.i] == separator[v.m]) v.compteur = v.compteur + 1;
        if (v.sep == v.compteur) {
            tab[v.a][v.b] = str[v.i];
            v.b = v.b + 1;
            v.test = 0;
        } else if (tab[v.a][0] != '\0' && tab[v.a] != NULL) {
            v.a = v.a + 1;
            v.b = 0;
            v.test = 1;
        }
    }
    str_bis(&v, tab, str);
    return (tab);
}