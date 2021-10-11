/*
** EPITECH PROJECT, 2020
** my_strupcase
** File description:
** change every low case charac in MAJ
*/

char *my_strupcase(char *str)
{
    int i = 0;
    while (str[i] != 0) {
        if (str[i] >= 97 && str[i] <= 122) {
            str[i] = (str[i] - 32);
        }
        i = i + 1;
    }
    return (str);
}
