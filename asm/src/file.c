/*
** EPITECH PROJECT, 2020
** B-CPE-201-MPL-2-1-corewar-thomy.lorenzatti
** File description:
** file.c
*/

#include "../include/my.h"
#include "../include/printf.h"
#include "../include/asm.h"

char **load_file(char *filepath)
{
    int i = 0;
    char *line;
    char **content = malloc(sizeof(char *) * 100);
    FILE *fp;
    unsigned long int size = 0;
    if (filepath[my_strlen(filepath) - 1] != 's')
        exit(84);
    fp = fopen(filepath, "r");
    if (fp == NULL)
        return (NULL);
    for (; getline(&line, &size, fp) != -1; i++)
        content[i] = my_strdup(line);
    content[i] = NULL;
    free(line);
    return (content);
}

char *take_file_name(asm_t *all, char *input_file)
{
    char *tmp;
    int i = 0;
    int a = 0;
    int len = 0;

    for (; input_file[i]; i++);
    i -= 3;
    for (; i != 0 && input_file[i - 1] != '/'; i--, len++);
    len += 1;
    tmp = malloc(sizeof(char) * len + 1);
    for (; a != len; i++, a++)
        tmp[a] = input_file[i];
    tmp[a] = '\0';
    return (tmp);
}

int create_file(asm_t *all, char *input_file)
{
    int fd = 0;
    char *cor_name = take_file_name(all, input_file);
    char *tmp = my_strcat(cor_name, ".cor");

    free(cor_name);
    fd = open(tmp, O_WRONLY | O_CREAT | O_TRUNC, 0677);
    if (fd < 0)
        return (84);
    free(tmp);
    return (fd);
}