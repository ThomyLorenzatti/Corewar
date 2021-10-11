/*
** EPITECH PROJECT, 2020
** my_str_isnum
** File description:
** say if str is only compose of number
*/

int my_str_isnum(char const *str)
{
    int i = 0;
    for (i = 0; str[i] != '\n' && str[i] != '\0'; i++) {
        if (str[i] < 48 || str[i] > 57)
            return (1);
    }
    return (0);
}
