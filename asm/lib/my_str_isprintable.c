/*
** EPITECH PROJECT, 2020
** my_str_isprintable
** File description:
** say if str is only compose of printable charac
*/

int my_str_isprintable(char const *str)
{
    if (*str == 0)
        return (1);
    if (*str >= 32 && *str <= 126)
        return (my_str_isprintable(str + 1));
    return (0);
}
