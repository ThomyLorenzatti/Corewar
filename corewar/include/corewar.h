/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** corewar
*/

#ifndef COREWAR_H_
#define COREWAR_H_

#include "op.h"
#define cp change_index_pc

typedef struct cor_s
{
    char **input;
    char *name;
    char *comment;
    int fd;
}cor_t;

typedef struct info_s {
    int nbr_cycle;
    int prog_number;
    unsigned int load_address;
    char *prog_name;
}info_t;

typedef struct pc_s {
    int ptr;
    int cycle;
    int id;
}pc_t;

typedef struct list_prog_s {
    header_t *head;
    info_t info;
    char *champ;
    int registre[16];
    int alive;
    int live;
    pc_t pc;
    int carry;
    struct list_prog_s *child;
    struct list_prog_s *parent;
    struct list_prog_s *next;
}list_prog_t;

typedef struct func_info_s {
    int parameter;
    int id;
    int type[3];
}func_info_t;

typedef struct sti_var_s {
    int test;
    int a;
    int i;
    int registre;
    int size1;
    int size2;
    char *arg1;
    char *arg2;
    char *str;
    char str2[3];
    int dist;
    int dif_F;
    int dif2_F;
}sti_var_t;

typedef struct corewar_s {
    char *vm;
    func_info_t func_info[MEM_SIZE];
    int nbr_prog;
    int prog_num[4];
    int cycle;
    int cycle_die;
    int live;
    list_prog_t *list_prog;
}corewar_t;

typedef struct func_t {
    void(*ptr)(pc_t *pc, corewar_t *core, op_t tab, list_prog_t *champ);
}func_t;

int binary_to_int(int bin);
void load_champ(corewar_t *core);
void init_push_back(list_prog_t **list, char *str);
void init_push_back_child(list_prog_t **list, char *str, int *registre, int p);
void pc_push_back(pc_t *pc, int ptr, int id);
int insert_list(corewar_t *core, char **av);
unsigned int lit_to_big_endian(unsigned int x);
void init_vm(corewar_t *core);
void print_vm(corewar_t *core);
void vm_loop(corewar_t *core);
int hex_to_int2(char hex);
int hex_to_int(char *hex);
char *int_binary(int nbr);
char *get_hexa2(unsigned int nbr, int size);
void get_live(pc_t *pc, corewar_t *core, op_t tab, list_prog_t *champ);
void get_ld(pc_t *pc, corewar_t *core, op_t tab, list_prog_t *champ);
void get_st(pc_t *pc, corewar_t *core, op_t tab, list_prog_t *champ);
void get_add(pc_t *pc, corewar_t *core, op_t tab, list_prog_t *champ);
void get_sub(pc_t *pc, corewar_t *core, op_t tab, list_prog_t *champ);
void get_and(pc_t *pc, corewar_t *core, op_t tab, list_prog_t *champ);
void get_or(pc_t *pc, corewar_t *core, op_t tab, list_prog_t *champ);
void get_xor(pc_t *pc, corewar_t *core, op_t tab, list_prog_t *champ);
void get_zjmp(pc_t *pc, corewar_t *core, op_t tab, list_prog_t *champ);
void get_ldi(pc_t *pc, corewar_t *core, op_t tab, list_prog_t *champ);
void get_sti(pc_t *pc, corewar_t *core, op_t tab, list_prog_t *champ);
void get_lld(pc_t *pc, corewar_t *core, op_t tab, list_prog_t *champ);
void get_lldi(pc_t *pc, corewar_t *core, op_t tab, list_prog_t *champ);
void get_fork(pc_t *pc, corewar_t *core, op_t tab, list_prog_t *champ);
void get_lfork(pc_t *pc, corewar_t *core, op_t tab, list_prog_t *champ);
void get_aff(pc_t *pc, corewar_t *core, op_t tab, list_prog_t *champ);
void change_carry(int test, list_prog_t *champ);

#endif /* !COREWAR_H_ */
