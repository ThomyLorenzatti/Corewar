/*
** EPITECH PROJECT, 2020
** my_compute_square_root
** File description:
** find the square root of an number
*/

int my_compute_square_root(int nb)
{
    int i = 0;
    int root;
    while (i < 46341) {
        root = i * i;
        if (root == nb) {
            return (i);
        }
        i = i + 1;
    }
    return (0);
}
