/*
** EPITECH PROJECT, 2020
** my_getnbr
** File description:
** Get int from a char
*/

int extract(int r, char str, int *p_multi)
{
    if (str >= 48 && str <= 57) {
        if (*p_multi > 0) {
            r = r * 10;
        }
        r = r + (str - 48);
        *p_multi = *p_multi + 1;
    }
    return (r);
}

int my_getnbr(char const *str)
{
    int i = 0;
    int r = 0;
    int multiple = 0;
    int negative = 0;
    int *p_multi = &multiple;
    while (str[i] != 0) {
        if (r != 0 && str[i] <= 48 || r != 0 && str[i] >= 57)
            break;
        r = extract(r, str[i], p_multi);
        if (str[i] == 45)
            negative = negative + 1;
        i = i + 1;
    }
    if ((negative % 2) == 1)
        r = r * (-1);
    if (r > 2147483647 || r < -2147483647)
        return (0);
    return (r);
}
