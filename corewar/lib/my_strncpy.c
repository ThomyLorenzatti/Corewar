/*
** EPITECH PROJECT, 2020
** my_strncpy.c
** File description:
** copy n character of a string into an other
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;
    while (src[i] != 0 || n > i) {
        dest[i] = src[i];
        i = i + 1;
    }
    dest[i] = 0;
    return dest;
}
