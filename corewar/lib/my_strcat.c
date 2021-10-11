/*
** EPITECH PROJECT, 2020
** my_strcat
** File description:
** copy a string after an other
*/

char *my_strcat(char *dest, char const *src)
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
    while (p <= i) {
        dest[p + m] = src[p];
        p = p + 1;
    }
    dest[p + m] = '\0';
    return (dest);
}
