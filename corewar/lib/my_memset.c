/*
** EPITECH PROJECT, 2020
** matchstick
** File description:
** my_memset.c
*/

void my_memset(char **src, int x, int y, char c)
{
    for (int i = 0; i < x; i++) {
        for (int a = 0; a < y; a++)
            src[i][a] = c;
    }
}