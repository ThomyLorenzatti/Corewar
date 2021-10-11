/*
** EPITECH PROJECT, 2020
** my_strcapitalize
** File description:
** put in MAJ first letters of each words
*/

char *my_strlowcase(char *str);

int extra(char str)
{
    if (str >= 91 && str <= 96)
        return (1);
    return (0);
}

char *my_strcapitalize(char *str)
{
    int i = 0;
    my_strlowcase(str);
    while (str[i] != 0) {
        if (str[i] >= 97 && str[i] <= 122) {
            if (str[i - 1] <= 64 || str[i - 1] >= 122
                || extra(str[i-1] == 1))
                str[i] = (str[i] - 32);
        }
        i = i + 1;
    }
    return (str);
}
