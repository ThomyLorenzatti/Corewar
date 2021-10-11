/*
** EPITECH PROJECT, 2020
** my_strcmp
** File description:
** compare 2 string
*/

int my_strcmp(char const *s1, char const *s2)
{
    if (*s1 == '\0' || *s2 == '\0')
        return (*s1 - *s2);
    if (*s1 == *s2)
        return (my_strcmp(s1 + 1, s2 + 1));
    return (*s1 - *s2);
}
