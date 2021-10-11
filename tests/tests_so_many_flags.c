/*
** EPITECH PROJECT, 2020
** my_printf
** File description:
** tests_so_many_flags.c
*/

#include  <criterion/criterion.h>
#include  <criterion/redirect.h>
#include "my.h"
#include "printf.h"

void  redirect_all_std(void);

Test(my_printf , simple_stringj , .init = redirect_all_std)
{
    my_printf("%ho", 10);
    cr_assert_stdout_eq_str("12");
}

Test(my_printf , simple_stringk , .init = redirect_all_std)
{
    my_printf("%hu", 20);
    cr_assert_stdout_eq_str("20");
}

Test(my_printf , simple_stringl , .init = redirect_all_std)
{
    my_printf("%hx", 47);
    cr_assert_stdout_eq_str("2f");
}

Test(my_printf , simple_stringm1 , .init = redirect_all_std)
{
    my_printf("t%-2ot", 123);
    cr_assert_stdout_eq_str("t173t");
}