/*
** EPITECH PROJECT, 2020
** my_printf
** File description:
** tests_more_flags.c
*/

#include  <criterion/criterion.h>
#include  <criterion/redirect.h>
#include "my.h"
#include "printf.h"

void  redirect_all_std(void);

Test(my_printf , simple_string4 , .init = redirect_all_std)
{
    my_printf("%b", 15);
    cr_assert_stdout_eq_str("1111");
}

Test(my_printf , simple_string7 , .init = redirect_all_std)
{
    my_printf("%%");
    cr_assert_stdout_eq_str("%");
}

Test(my_printf , simple_string8 , .init = redirect_all_std)
{
    my_printf("%o", 15);
    cr_assert_stdout_eq_str("17");
}