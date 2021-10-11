/*
** EPITECH PROJECT, 2020
** my_strlen
** File description:
** return the lengh of an string
*/

int my_strlen(char const *str)
{
    int i = 0;
    for (i = 0; str[i]; i = i + 1);
    return (i);
}
