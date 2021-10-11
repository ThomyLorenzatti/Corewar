/*
** EPITECH PROJECT, 2020
** my_strncat
** File description:
** put n character of a str after an other
*/

char *my_strncat(char *dest, char const *src, int nb)
{
    int i = 0;
    int m = 0;
    int p = 0;
    while (dest[m] != 0) {
        m = m + 1;
    }
    while (src[i] != 0) {
        i = i + 1;
    }
    while (p < nb) {
        dest[p + m] = src[p];
        p = p + 1;
    }
    dest[p + m] = '\0';
    return dest;
}
