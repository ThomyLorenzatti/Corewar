/*
** EPITECH PROJECT, 2020
** my_sort_int_array
** File description:
** salut
*/
#include "my.h"

int my_intlen(int *tab)
{
    int i = 0;
    while (tab[i] >= 0 && tab[i] <= 9) {
        i = i + 1;
    }
    return (i);
}

void my_sort_int_array(int *tab, int size)
{
    int i = 0;
    int n = 0;
    int m = my_intlen(tab);
    if (m < size)
        size = m;
    while (i < size - 1) {
        if (tab[i] > tab[i + 1] && tab[i + 1] != '\0') {
            n = tab[i];
            tab[i] = tab[i + 1];
            tab[i + 1] = n;
            i = 0;
        } else {
            i = i + 1;
        }
    }
    return;
}