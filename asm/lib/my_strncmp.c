/*
** EPITECH PROJECT, 2020
** my_strncmp
** File description:
** compare the first n charac of 2 string
*/

int my_strncmp(char const *s1, char const *s2, int n)
{
    if (*s1 == 0 || *s2 == 0 || n == 1)
        return (*s1 - *s2);
    if (*s1 == *s2)
        return (my_strncmp(s1 + 1, s2 + 1, n - 1));
    return (*s1 - *s2);
}