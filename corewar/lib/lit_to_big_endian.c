/*
** EPITECH PROJECT, 2021
** lit_to_big_endian
** File description:
** convert
*/

unsigned int lit_to_big_endian(unsigned int x)
{
    return (((x >> 24) & 0x000000ff) | ((x >> 8) & 0x0000ff00) |
    ((x << 8) & 0x00ff0000) | ((x << 24) & 0xff000000));
}