/*
** EPITECH PROJECT, 2020
** B-CPE-201-MPL-2-1-corewar-thomy.lorenzatti
** File description:
** tools.c
*/

#include "../include/my.h"
#include "../include/printf.h"
#include "../include/asm.h"

long int binary_to_hex(int bin)
{
    long int hex = 0;
    int i = 1;
    long int tmp;

    while (bin != 0) {
        tmp = bin % 10;
        hex = hex + tmp * i;
        i = i * 2;
        bin = bin / 10;
    }
    return (hex);
}

int check_label(char *str)
{
    int is_point = 0;
    int is_modulo = 0;
    int exist = 0;
    for (int i = 0; str[i]; i++) {
        if (str[i] == ':')
            is_point = 1;
        if (str[i] == '%')
            is_modulo = 1;
    }
    if (is_modulo == 1 || is_point == 0)
        return (1);
    for (int i = 0; str[i]; i++) {
        for (int a = 0; LABEL_CHARS[a]; a++) {
            if (str[i] == LABEL_CHARS[a])
                exist = 1;
            if (LABEL_CHARS[a + 1] == '\0' && exist == 0)
                exit(84);
        }
    }
    return (0);
}

int is_only_tab(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != '\t' && str[i] != '\n' && str[i] != ' ')
            return (0);
    }
    return (1);
}

char *format_str(char *str)
{
    int a = 0;
    int i = 0;
    char *dest = malloc(sizeof(char) * my_strlen(str) + 1);
    for (; str[i] == ' ' || str[i] == '\t' || str[i] == '\n'; i++);
    for (; str[i] != '\0'; i++, a++)
        dest[a] = str[i];
    dest[a] = 0;
    return (dest);
}

void format_input(asm_t *all)
{
    int i = 0;
    for (; all->input[i] != NULL; i++) {
        if (is_only_tab(all->input[i]) == 1)
            continue;
        all->input[i] = format_str(all->input[i]);
    }
}