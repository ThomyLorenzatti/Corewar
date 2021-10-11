/*
** EPITECH PROJECT, 2020
** my_revstr.c
** File description:
** reverse a string
*/

char *my_revstr(char *str)
{
    int i = 0;
    int p = 0;
    int m = 0;
    while (str[i] != 0) {
        i = i + 1;
    }
    i = i - 1;
    char dest [i];
    while (str[p] != 0) {
        dest[p] = str[p];
        p = p + 1;
    }

    while (dest[i] != 0) {
        str[i] = dest[m];
        m = m + 1;
        i = i - 1;
    }
    return (str);
}
