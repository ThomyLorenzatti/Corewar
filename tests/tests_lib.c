/*
** EPITECH PROJECT, 2020
** lib
** File description:
** tests_lib.c
*/

#include  <criterion/criterion.h>
#include  <criterion/redirect.h>
#include "my.h"
#include "printf.h"

void redirect_all_std(void);

Test(my_str_isalpha, test_alpha)
{
    int i = my_str_isalpha("gezfr");
    cr_assert_eq(i, 1);
}

Test(my_strcpy, copy_in_empty_array)
{
    char dest[6] = {0};
    my_strcpy(dest, "Hello");
    cr_assert_str_eq(dest, "Hello");
}

Test(my_strstr, search_an_str_in_str)
{    char *str = "helloz";
    char *to_find = my_strstr(str, "lo");
    cr_assert_str_eq(to_find, "lloz");
}

Test(my_putstr , a_simple_string , .init = redirect_all_std)
{
    my_putstr("hey");
    cr_assert_stdout_eq_str("hey");
}

Test(my_strncmp, compare_n_char)
{
    char *s1 = "hello";
    char *s2 = "hello";
    int i = my_strncmp(s1, s2, 3);
    cr_assert_eq(i, 0);
}

Test(my_strncmp, compare_n_char2)
{
    char *s1 = "hbllo";
    char *s2 = "hallo";
    int i = my_strncmp(s1, s2, 3);
    cr_assert_eq(i, 1);
}

Test(my_strncpy, copy_n_char_empty_array)
{
    char dest[6] = {0};
    my_strncpy(dest, "Hello", 3);
    cr_assert_str_eq(dest, "Hello");
}

Test(my_strncat, concat_n_char)
{
    char *result = malloc(sizeof(char) * 6);
    result[0] = 'a';
    result[6] = '\0';
    result = my_strncat(result, "Hello", 5);
    cr_assert_str_eq(result, "aHello");
    free(result);
}

Test(my_strlowcase, return_char_in_lowercase)
{
    char dest[6];
    dest[0] = 'H';
    dest[1] = 'E';
    dest[2] = 'L';
    dest[3] = 'L';
    dest[4] = 'O';
    dest[5] = '\0';
    my_strlowcase(dest);
    cr_assert_str_eq(dest, "hello");
}

Test(my_strlen, return_len_of_char)
{
    int i = my_strlen("hey");
    cr_assert_eq(i, 3);
}

Test(my_strdup, return_duplicate_of_char)
{
    char *str = "hey";
    char *dest = my_strdup(str);
    cr_assert_str_eq(dest, "hey");
    free(dest);
}

Test(my_strcmp, compare_char)
{
    char *s1 = "hello";
    char *s2 = "hello";
    int i = my_strcmp(s1, s2);
    cr_assert_eq(i, 0);
}

Test(my_strcmp, compare_char2)
{
    char *s1 = "hbllo";
    char *s2 = "hallo";
    int i = my_strcmp(s1, s2);
    cr_assert_eq(i, 1);
}

Test(my_strcat, concat_char)
{
    char *result = malloc(sizeof(char) * 6);
    result[0] = 'a';
    result[1] = '\0';
    result[6] = '\0';
    result = my_strcat(result, "Hello");
    cr_assert_str_eq(result, "aHello");
    free(result);
}

Test(my_strcapitalize, return_first_letter_in_uppercase)
{
    char dest[6];
    dest[0] = 'h';
    dest[1] = 'e';
    dest[2] = 'l';
    dest[3] = 'l';
    dest[4] = 'o';
    dest[5] = '\0';
    char *str = my_strcapitalize(dest);
    cr_assert_str_eq(str, "Hello");
}

Test(my_str_to_word_array, return_char)
{
    char **dest = my_str_to_word_array("hello you", " ");
    cr_assert_str_eq(dest[1], "you");
    free(dest[1]);
    free(dest[0]);
    free(dest);
}

Test(my_str_isupper, check_str_isuppercase)
{
    char *dest = "HELLO";
    int i = my_str_isupper(dest);
    cr_assert_eq(i, 1);
}

Test(my_str_isupper, check_str_isuppercase2)
{
    char *dest = "hello";
    int i = my_str_isupper(dest);
    cr_assert_eq(i, 0);
}

Test(my_char_isupper, check_char_isuppercase)
{
    int i = my_str_isupper("A");
    cr_assert_eq(i, 1);
}

Test(my_char_isupper, check_char_isuppercase2)
{
    int i = my_str_isupper("a");
    cr_assert_eq(i, 0);
}

Test(my_char_isprintable, check_char_isprintable)
{
    int i = my_str_isprintable("hey");
    cr_assert_eq(i, 1);
}

Test(my_char_isnum, check_char_isnum)
{
    int i = my_str_isnum("123");
    cr_assert_eq(i, 1);
}

Test(my_char_islower, check_char_islower)
{
    int i = my_str_islower("hey");
    cr_assert_eq(i, 1);
}

Test(my_char_isalpha, check_char_isalpha)
{
    int i = my_str_isalpha("heY");
    cr_assert_eq(i, 1);
}

Test(my_sort_int_array, sort_array_int)
{
    int i[3];
    i[0] = 2;
    i[1] = 1;
    i[2] = 3;
    my_sort_int_array(i, 3);
    cr_assert_eq(i[0], 1);
}

Test(my_revstr, reverse_an_str)
{
    char dest[6];
    dest[0] = 'H';
    dest[1] = 'E';
    dest[2] = 'L';
    dest[3] = 'L';
    dest[4] = 'O';
    dest[5] = '\0';
    my_revstr(dest);
    cr_assert_str_eq(dest, "OLLEH");
}

Test(my_getnbr, get_int_from_str)
{
    int i = my_getnbr("42");
    cr_assert_eq(i, 42);
}

Test(my_getnbr, get_int_from_str2)
{
    int i = my_getnbr("-42");
    cr_assert_eq(i, -42);
}

Test(my_getnbr, get_int_from_str3)
{
    int i = my_getnbr("2147483648");
    cr_assert_eq(i, 0);
}

Test(my_compute_square_root, return_square_root)
{
    int i = my_compute_square_root(81);
    cr_assert_eq(i, 9);
}

Test(my_compute_square_root, return_square_root2)
{
    int i = my_compute_square_root(2);
    cr_assert_eq(i, 0);
}

Test(my_compute_power_rec, return_power_of_int)
{
    int i = my_compute_power_rec(2, 2);
    cr_assert_eq(i, 4);
}

Test(my_compute_power_rec, return_power_of_int2)
{
    int i = my_compute_power_rec(2, -1);
    cr_assert_eq(i, 0);
}

Test(my_atoi, get_int_from_char)
{
    int i = my_atoi("4");
    cr_assert_eq(i, 4);
}

Test(my_atoi, get_int_from_char2)
{
    int i = my_atoi("-7");
    cr_assert_eq(i, -7);
}