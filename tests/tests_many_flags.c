/*
** EPITECH PROJECT, 2020
** my_printf
** File description:
** tests_many_flags.c
*/

#include  <criterion/criterion.h>
#include  <criterion/redirect.h>
#include "my.h"
#include "printf.h"

void  redirect_all_std(void);

Test(my_printf , simple_stringe , .init = redirect_all_std)
{
    my_printf("%lu", 150);
    cr_assert_stdout_eq_str("150");
}

Test(my_printf , simple_stringf , .init = redirect_all_std)
{
    my_printf("%lx", 47);
    cr_assert_stdout_eq_str("2f");
}

Test(my_printf , simple_stringh , .init = redirect_all_std)
{
    my_printf("%hd", 100);
    cr_assert_stdout_eq_str("100");
}

Test(my_printf , simple_stringi , .init = redirect_all_std)
{
    my_printf("%hi", 15);
    cr_assert_stdout_eq_str("15");
}