/*
** EPITECH PROJECT, 2020
** my_str_isalpha
** File description:
** say if a string only content letters
*/

int my_str_isalpha(char const *str)
{
    if (*str == 0)
        return (1);
    if (*str >= 65 && *str <= 90)
        return (my_str_isalpha(str + 1));
    if (*str >= 97 && *str <= 122)
        return (my_str_isalpha(str + 1));
    return (0);
}
