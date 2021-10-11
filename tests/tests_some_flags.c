/*
** EPITECH PROJECT, 2020
** my_printf
** File description:
** tests_some_flags.c
*/

#include  <criterion/criterion.h>
#include  <criterion/redirect.h>
#include "my.h"
#include "printf.h"

void  redirect_all_std(void);

Test(my_printf , some_flags1 , .init = redirect_all_std)
{
    my_printf("t%-5dt", 30);
    cr_assert_stdout_eq_str("t30   t");
}

Test(my_printf , some_flags2 , .init = redirect_all_std)
{
    my_printf("t%05dt", 30);
    cr_assert_stdout_eq_str("t00030t");
}

Test(my_printf , some_flags3 , .init = redirect_all_std)
{
    my_printf("t%-5Xt", 1234);
    cr_assert_stdout_eq_str("t4D2  t");
}

Test(my_printf , some_flags5 , .init = redirect_all_std)
{
    my_printf("t%-5xt", 1234);
    cr_assert_stdout_eq_str("t4d2  t");
}