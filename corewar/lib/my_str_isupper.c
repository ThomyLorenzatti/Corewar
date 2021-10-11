/*
** EPITECH PROJECT, 2020
** my_str_isupper
** File description:
** say if str is only compose of MAJ
*/

int my_str_isupper(char const *str)
{
    if (*str == 0)
        return (1);
    if (*str >= 65 && *str <= 90)
        return (my_str_isupper(str + 1));
    return (0);
}

int my_char_isupper(char const c)
{
    if (c >= 65 && c <= 90)
        return (1);
    return (0);
}