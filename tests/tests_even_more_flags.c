/*
** EPITECH PROJECT, 2020
** my_printf
** File description:
** tests_even_more_flags.c
*/

#include  <criterion/criterion.h>
#include  <criterion/redirect.h>
#include "my.h"
#include "printf.h"

void redirect_all_std(void);

Test(my_printf , even_more_flags1 , .init = redirect_all_std)
{
    my_printf("%d", -3);
    cr_assert_stdout_eq_str("-3");
}

Test(my_printf , even_more_flags2 , .init = redirect_all_std)
{
    my_printf("%d", -2147483648);
    cr_assert_stdout_eq_str("-2147483648");
}

Test(my_printf , even_more_flags3 , .init = redirect_all_std)
{
    my_printf("test% #otest", 45);
    cr_assert_stdout_eq_str("test 055test");
}

Test(my_printf , even_more_flags4 , .init = redirect_all_std)
{
    my_printf("test% #xtest", 45);
    cr_assert_stdout_eq_str("test 0x2dtest");
}

Test(my_printf , even_more_flags5 , .init = redirect_all_std)
{
    my_printf("test% #Xtest", 45);
    cr_assert_stdout_eq_str("test 0X2Dtest");
}