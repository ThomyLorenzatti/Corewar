/*
** EPITECH PROJECT, 2020
** my_printf
** File description:
** tests_flags.c
*/

#include  <criterion/criterion.h>
#include  <criterion/redirect.h>
#include "my.h"
#include "printf.h"

void  redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(my_printf , simple_string , .init = redirect_all_std)
{
    my_printf("%d", 10);
    cr_assert_stdout_eq_str("10");
}

Test(my_printf , simple_string1 , .init = redirect_all_std)
{
    my_printf("%i", 10);
    cr_assert_stdout_eq_str("10");
}

Test(my_printf , simple_string2 , .init = redirect_all_std)
{
    my_printf("%s", "test");
    cr_assert_stdout_eq_str("test");
}

Test(my_printf , simple_string3 , .init = redirect_all_std)
{
    my_printf("%c", 't');
    cr_assert_stdout_eq_str("t");
}