/*
** EPITECH PROJECT, 2020
** corewar
** File description:
** init_vm.c
*/

#include "../include/corewar.h"
#include "../include/my.h"

int vm_params_set(corewar_t *core, int *i, int m, int size)
{
    core->func_info[*i].type[m] = size;
    return (1);
}

void vm_params(corewar_t *core, char *bin, int *i, op_t op_tab)
{
    int a = 0;
    int total = 0;
    int param = 0;
    for (int m = 0; m < 3; m++) {
        core->func_info[*i].type[m] = 0;
        if (bin[a] == '0' && bin[a + 1] == '1')
            param += vm_params_set(core, i, m, 1);
        if (bin[a] == '1' && bin[a + 1] == '0' && op_tab.nbr_cycles < 20)
            param += vm_params_set(core, i, m, DIR_SIZE);
        if (bin[a] == '1' && bin[a + 1] == '0' && op_tab.nbr_cycles >= 20)
            param += vm_params_set(core, i, m, 2);
        if (bin[a] == '1' && bin[a + 1] == '1')
            param += vm_params_set(core, i, m, IND_SIZE);
        total += core->func_info[*i].type[m];
        a += 2;
    }
    core->func_info[*i].parameter = param;
    *i += total + 1;
}

int parse_vm_bis(corewar_t *core, int a, int *i)
{
    char *bin;
    if (my_strcmp(get_hexa(op_tab[a].code), get_hexa(core->vm[*i])) == 0) {
        if (a == 0)
            core->func_info[*i].type[0] = 4;
        if (a == 8 || a == 11 || a == 14)
            core->func_info[*i].type[0] = 2;
        if (a == 0 || a == 8 || a == 11 || a == 14) {
            core->func_info[*i].type[1] = 0;
            core->func_info[*i].type[2] = 0;
            core->func_info[*i].parameter = 1;
            *i += core->func_info[*i].type[0] + core->func_info[*i].type[1]
            + core->func_info[*i].type[2];
            return (1);
        }
        bin = int_binary(hex_to_int(get_hexa(core->vm[*i + 1])));
        vm_params(core, bin, i, op_tab[a]);
        return (1);
    }
    return (0);
}

void parse_vm(corewar_t *core)
{
    for (int i = 0; i < MEM_SIZE; i++) {
        for (int a = 0; a < 16; a++) {
            if (parse_vm_bis(core, a, &i) == 1)
                break;
        }
    }
}

void init_vm(corewar_t *core)
{
    core->cycle_die = CYCLE_TO_DIE;
    for (int p = 0; p < 4; p++)
        core->prog_num[p] = 0;
    core->vm = malloc(sizeof(char) * MEM_SIZE);
    for (int i = 0; i < MEM_SIZE; i++) {
        core->func_info[i].parameter = 0;
        core->func_info[i].id = 0;
        core->vm[i] = '\0';
    }
    load_champ(core);
    parse_vm(core);
}