/*
** EPITECH PROJECT, 2020
** my_printf
** File description:
** tests_print.c
*/

#include  <criterion/criterion.h>
#include  <criterion/redirect.h>
#include "my.h"
#include "printf.h"

void  redirect_all_std(void);

Test(my_printf , tests_print1 , .init = redirect_all_std)
{
    my_printf("t%3ut", 30);
    cr_assert_stdout_eq_str("t 30t");
}

Test(my_printf , tests_print2 , .init = redirect_all_std)
{
    my_printf("t%3St", "\n");
    cr_assert_stdout_eq_str("t  \\012t");
}

Test(my_printf , tests_print3 , .init = redirect_all_std)
{
    my_printf("t%-3St", "\n");
    cr_assert_stdout_eq_str("t\\012    t");
}

Test(my_printf , tests_print4 , .init = redirect_all_std)
{
    int a = 1;
    char s[1000];
    sprintf(s, "%p", &a);
    my_printf("%p", &a);
    cr_assert_stdout_eq_str(s);
}

Test(my_printf , tests_print5 , .init = redirect_all_std)
{
    my_printf("t%-3bt", 12);
    cr_assert_stdout_eq_str("t1100  t");
}