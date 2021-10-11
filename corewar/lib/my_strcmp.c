/*
** EPITECH PROJECT, 2020
** my_strcmp
** File description:
** compare 2 string
*/

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;
    while (s1[i] != 0 || s2[i] != 0) {
        if (s1[i] != s2[i]) {
            return (s1[i] - s2[i]);
        }
        i = i + 1;
    }
    if (s1[i] == 0 && s2[i] == 0) {
        return (s1[i] - s2[i]);
    }
    return (-1);
}
