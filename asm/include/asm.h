/*
** EPITECH PROJECT, 2020
** B-CPE-201-MPL-2-1-corewar-thomy.lorenzatti
** File description:
** asm.h
*/

#ifndef __ASM_H__
#define __ASM_H__

#include "op.h"

typedef enum type_e {
    LABEL,
    DIRT,
    IND,
    REG,
    OP_CODE,
    OP_FUNC,
    FUNC,
    SEPARATOR
}type_t;

typedef struct object_s
{
    type_t type;
    char *elem;
    int nb;
    int cycle;
    char *bin;
}object_t;

typedef struct list_s
{
    object_t value;
    struct list_s *next;
}list_t;

typedef struct char_s
{
    char *value;
    struct char_s *next;
}char_t;

typedef struct asm_s
{
    char **input;
    char **file;
    char *name;
    char *comment;
    int header_end;
    int is_name;
    int is_comment;
    int fd;
    int part;
    int byte_len;
    list_t *list;
    char_t *clist;
}asm_t;

int create_file(asm_t *all, char *input_file);
char **load_file(char *filepath);
int take_info(asm_t *all);
int printer(asm_t *all);
void print_hexa(asm_t *all, int nb, int size);
int check_label(char *str);
int is_only_tab(char *str);
void format_input(asm_t *all);
void obj_list_push_back(list_t **list, object_t value);
void char_list_push_back(char_t **list, char *value);
void char_list_destroy(char_t **list);
void obj_list_destroy(list_t **list);
void analyse_elem(asm_t *all, char *elem);
int take_byte_value(asm_t *all);
char *my_strcat2(char *dest, char const *src);
long int binary_to_hex(int bin);
void calcul_op_code(asm_t *all, object_t *tmp, int a);
void calcul_op_code2(asm_t *all, int check, char *byte, object_t *tmp);
void count_length(asm_t *all, object_t *tmp, int a);
void count_byte_length(asm_t *all);
void count_length_label(asm_t *all, object_t *tmp, int a);
int check_error(asm_t *all);

#endif