/*
** EPITECH PROJECT, 2020
** my_h
** File description:
** ethrt
*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <dirent.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <grp.h>
#include <pwd.h>
#include <string.h>

#ifndef __MY_H__
#define __MY_H__

int int_len(int x);
void my_int_str(char *str, int nb, int size);
char *get_hexa(unsigned int nbr);
char **my_str_to_word_array(const char *str, char *separator);
void my_putchar(char c);
int my_char_isupper(char const c);
int my_put_nbr(int nb);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_getnbr(char const *str);
char **my_init_char_tab(char **tab, int size, int size2);
void my_free_char_tab(char **tab, int size);
void my_sort_int_array(int *tab, int size);
int my_compute_power_rec(int nb, int power);
int my_compute_square_root(int nb);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_revstr(char *str);
char *my_strstr(char *str, char const *to_find);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strupcase(char *str);
char *my_strlowcase(char *str);
char *my_strcapitalize(char *str);
int my_str_isalpha(char const *str);
int my_str_isnum(char const *str);
int my_str_islower(char const *str);
int my_str_isupper(char const *str);
int my_str_isprintable(char const *str);
char *my_strcat(char *dest, char const *src);
char *my_strncat(char *dest, char const *src, int nb);
void my_print_error(char *str);
int get_nb_words(const char *str, const char *separator);
int my_put_long(unsigned long int nb);
int my_printf(char const *text, ...);
int my_atoi(char const *str);
char *my_strdup(char *str);

#endif
