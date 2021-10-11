/*
** EPITECH PROJECT, 2020
** my_putstr
** File description:
** display char[]
*/

void my_putchar(char);

int my_putstr(char const *str)
{
    int i = 0;
    while (str[i]) {
        my_putchar(str[i]);
        i = i + 1;
    }
    return 0;
}
