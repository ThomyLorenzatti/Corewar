/*
** EPITECH PROJECT, 2020
** my_printf
** File description:
** tests_even_more.c
*/

#include  <criterion/criterion.h>
#include  <criterion/redirect.h>
#include "my.h"
#include "printf.h"

void redirect_all_std(void);

Test(my_printf , simple_string9 , .init = redirect_all_std)
{
    my_printf("%u", 15);
    cr_assert_stdout_eq_str("15");
}

Test(my_printf , simple_stringa , .init = redirect_all_std)
{
    my_printf("%S", "te");
    cr_assert_stdout_eq_str("te");
}

Test(my_printf , simple_stringb , .init = redirect_all_std)
{
    my_printf("%ld", 100);
    cr_assert_stdout_eq_str("100");
}

Test(my_printf , simple_stringc , .init = redirect_all_std)
{
    my_printf("%li", 100);
    cr_assert_stdout_eq_str("100");
}

Test(my_printf , simple_stringd , .init = redirect_all_std)
{
    my_printf("%lo", 100);
    cr_assert_stdout_eq_str("144");
}