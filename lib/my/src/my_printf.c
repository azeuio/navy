/*
** EPITECH PROJECT, 2021
** my_printf
** File description:
** tests my_printf
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <criterion/logging.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include "../include/my.h"

void redirect_stdout(void)
{
    cr_redirect_stdout();
}

Test(my_printf, str, .init=redirect_stdout)
{
    my_printf("Hello World!\n");
    cr_assert_stdout_eq_str("Hello World!\n");
}

Test(my_printf, str_modulo, .init=redirect_stdout)
{
    my_printf("Hello %%!");
    cr_assert_stdout_eq_str("Hello %!");
}

Test(my_printf, str_char, .init=redirect_stdout)
{
    my_printf("Hello %c!", 'a');
    cr_assert_stdout_eq_str("Hello a!");
}

Test(my_printf, str_digit, .init=redirect_stdout)
{
    my_printf("Hello %d!", 42);
    cr_assert_stdout_eq_str("Hello 42!");
}

Test(my_printf, str_digit_inf, .init=redirect_stdout)
{
    my_printf("Hello %d!", 2147483648);
    cr_assert_stdout_eq_str("Hello -2147483648!");
}

Test(my_printf, str_int, .init=redirect_stdout)
{
    my_printf("Hello %i!", 42);
    cr_assert_stdout_eq_str("Hello 42!");
}

Test(my_printf, str_int_inf, .init=redirect_stdout)
{
    my_printf("Hello %i!", 2147483648);
    cr_assert_stdout_eq_str("Hello -2147483648!");
}

Test(my_printf, str_octal, .init=redirect_stdout)
{
    my_printf("Hello %o!", 8);
    cr_assert_stdout_eq_str("Hello 10!");
}

Test(my_printf, str_octal_inf, .init=redirect_stdout)
{
    my_printf("Hello %o!", 4294967295);
    cr_assert_stdout_eq_str("Hello 37777777777!");
}

Test(my_printf, str_str, .init=redirect_stdout)
{
    my_printf("Hello %s!", "World");
    cr_assert_stdout_eq_str("Hello World!");
}

Test(my_printf, str_unsigned, .init=redirect_stdout)
{
    unsigned int n = 2147483650;

    my_printf("Hello %u!", n);
    cr_assert_stdout_eq_str("Hello 2147483650!");
}

Test(my_printf, str_hex, .init=redirect_stdout)
{
    my_printf("Hello %x!", 4294967295);
    cr_assert_stdout_eq_str("Hello ffffffff!");
}

Test(my_printf, str_HEX, .init=redirect_stdout)
{
    my_printf("Hello %X!", 4294967295);
    cr_assert_stdout_eq_str("Hello FFFFFFFF!");
}

Test(my_printf, str_str_hex, .init=redirect_stdout)
{
    my_printf("Hello %S", "World\n!");
    cr_assert_stdout_eq_str("Hello World\\12!");
}

Test(my_printf, str_bin, .init=redirect_stdout)
{
    my_printf("Hello %b!", -6);
    cr_assert_stdout_eq_str("Hello 11111111111111111111111111111010!");
}

Test(my_printf, str_multiple, .init=redirect_stdout)
{
    my_printf("Hello %s! %d", "World", 42);
    cr_assert_stdout_eq_str("Hello World! 42");
}

Test(my_printf, str_short_digit, .init=redirect_stdout)
{
    int n = 2147483547;
    char expected[30];

    my_printf("%hd", n);
    sprintf(expected, "%hd", n);
    cr_assert_stdout_eq_str(expected);
}

Test(my_printf, str_short_int, .init=redirect_stdout)
{
    int n = 2147483547;
    char expected[30];

    my_printf("%hi", n);
    sprintf(expected, "%hi", n);
    cr_assert_stdout_eq_str(expected);
}

Test(my_printf, str_short_octal, .init=redirect_stdout)
{
    int n = 2147483547;
    char expected[30];

    my_printf("%ho", n);
    sprintf(expected, "%ho", n);
    cr_assert_stdout_eq_str(expected);
}

Test(my_printf, str_short_hex, .init=redirect_stdout)
{
    int n = 2147483547;
    char expected[30];

    my_printf("%hx", n);
    sprintf(expected, "%hx", n);
    cr_assert_stdout_eq_str(expected);
}

Test(my_printf, str_short_HEX, .init=redirect_stdout)
{
    int n = 2147483547;
    char expected[30];

    my_printf("%hX", n);
    sprintf(expected, "%hX", n);
    cr_assert_stdout_eq_str(expected);
}

Test(my_printf, str_long_digit, .init=redirect_stdout)
{
    long n = 2147483999;
    char expected[30];

    my_printf("%ld", n);
    sprintf(expected, "%ld", n);
    cr_assert_stdout_eq_str(expected);
}

Test(my_printf, str_long_int, .init=redirect_stdout)
{
    long n = 2147483999;
    char expected[30];

    my_printf("%li", n);
    sprintf(expected, "%li", n);
    cr_assert_stdout_eq_str(expected);
}

Test(my_printf, str_long_octal, .init=redirect_stdout)
{
    long n = 2147483999;
    char expected[30];

    my_printf("%lo", n);
    sprintf(expected, "%lo", n);
    cr_assert_stdout_eq_str(expected);
}

Test(my_printf, str_long_hex, .init=redirect_stdout)
{
    long n = 2147483999;
    char expected[30];

    my_printf("%lx", n);
    sprintf(expected, "%lx", n);
    cr_assert_stdout_eq_str(expected);
}

Test(my_printf, str_long_HEX, .init=redirect_stdout)
{
    long n = 2147483999;
    char expected[30];

    my_printf("%lX", n);
    sprintf(expected, "%lX", n);
    cr_assert_stdout_eq_str(expected);
}

Test(my_printf, str_long_b, .init=redirect_stdout)
{
    long n = 2147483999;
    char *expected = "10000000000000000000000101011111";

    my_printf("%lb", n);
    cr_assert_stdout_eq_str(expected);
}

char *get_stdout_100(void)
{
    FILE *fd = cr_get_redirected_stdout();
    char *result = malloc(sizeof(char) * 101);

    result[fread(result, sizeof(char), 100, fd)] = '\0';
    cr_log_error("%s",result);
    return result;
}

Test(my_printf, str_justified_d, .init=redirect_stdout)
{
    my_printf("Hello %3d!", 10);
    cr_assert_stdout_eq_str("Hello  10!");
}

Test(my_printf, str_justified_i, .init=redirect_stdout)
{
    my_printf("Hello %3i!", 10);
    cr_assert_stdout_eq_str("Hello  10!");
}

Test(my_printf, str_justified_x, .init=redirect_stdout)
{
    my_printf("Hello %3x!", 16);
    cr_assert_stdout_eq_str("Hello  10!");
}

Test(my_printf, str_justified_X, .init=redirect_stdout)
{
    my_printf("Hello %3X!", 16);
    cr_assert_stdout_eq_str("Hello  10!");
}

Test(my_printf, str_justified_o, .init=redirect_stdout)
{
    my_printf("Hello %4o!", 64);
    cr_assert_stdout_eq_str("Hello  100!");
}

Test(my_printf, str_justified_b, .init=redirect_stdout)
{
    my_printf("Hello %4b!", 5);
    cr_assert_stdout_eq_str("Hello  101!");
}

Test(my_printf, str_hash_d, .init=redirect_stdout)
{
    my_printf("Hello %#d!", 10);
    cr_assert_stdout_eq_str("Hello 10!");
}

Test(my_printf, str_hash_i, .init=redirect_stdout)
{
    my_printf("Hello %#i!", 10);
    cr_assert_stdout_eq_str("Hello 10!");
}

Test(my_printf, str_hash_x, .init=redirect_stdout)
{
    my_printf("Hello %#x!", 16);
    cr_assert_stdout_eq_str("Hello 0x10!");
}

Test(my_printf, str_hash_X, .init=redirect_stdout)
{
    my_printf("Hello %#X!", 16);
    cr_assert_stdout_eq_str("Hello 0X10!");
}

Test(my_printf, str_hash_o, .init=redirect_stdout)
{
    my_printf("Hello %#o!", 64);
    cr_assert_stdout_eq_str("Hello 0100!");
}

Test(my_printf, str_hash_zero_x, .init=redirect_stdout)
{
    my_printf("Hello %#x!", 0);
    cr_assert_stdout_eq_str("Hello 0!");
}

Test(my_printf, str_hash_zero_X, .init=redirect_stdout)
{
    my_printf("Hello %#X!", 0);
    cr_assert_stdout_eq_str("Hello 0!");
}

Test(my_printf, str_hash_zero_o, .init=redirect_stdout)
{
    my_printf("Hello %#o!", 0);
    cr_assert_stdout_eq_str("Hello 0!");
}

Test(my_printf, str_hash_b, .init=redirect_stdout)
{
    my_printf("Hello %#b!", 5);
    cr_assert_stdout_eq_str("Hello 101!");
}

Test(my_printf, str_combinaison_hash_5_o, .init=redirect_stdout)
{
    my_printf("Hello %#5o!", 8);
    cr_assert_stdout_eq_str("Hello   010!");
}

Test(my_printf, str_justified_zero_d, .init=redirect_stdout)
{
    my_printf("Hello %04d!", 10);
    cr_assert_stdout_eq_str("Hello 0010!");
}

Test(my_printf, str_justified_zero_i, .init=redirect_stdout)
{
    my_printf("Hello %04i!", 10);
    cr_assert_stdout_eq_str("Hello 0010!");
}

Test(my_printf, str_justified_zero_x, .init=redirect_stdout)
{
    my_printf("Hello %04x!", 16);
    cr_assert_stdout_eq_str("Hello 0010!");
}

Test(my_printf, str_justified_zero_X, .init=redirect_stdout)
{
    my_printf("Hello %04X!", 16);
    cr_assert_stdout_eq_str("Hello 0010!");
}

Test(my_printf, str_justified_zero_o, .init=redirect_stdout)
{
    my_printf("Hello %04o!", 64);
    cr_assert_stdout_eq_str("Hello 0100!");
}

Test(my_printf, str_justified_zero_b, .init=redirect_stdout)
{
    my_printf("Hello %04b!", 5);
    cr_assert_stdout_eq_str("Hello 0101!");
}
Test(my_printf, str_justified_zero_precision_d, .init=redirect_stdout)
{
    my_printf("Hello %04.3d!", 10);
    cr_assert_stdout_eq_str("Hello  010!");
}

Test(my_printf, str_justified_zero_precision_i, .init=redirect_stdout)
{
    my_printf("Hello %04.3i!", 10);
    cr_assert_stdout_eq_str("Hello  010!");
}

Test(my_printf, str_justified_zero_precision_x, .init=redirect_stdout)
{
    my_printf("Hello %04.3x!", 16);
    cr_assert_stdout_eq_str("Hello  010!");
}

Test(my_printf, str_justified_zero_precision_X, .init=redirect_stdout)
{
    my_printf("Hello %04.3X!", 16);
    cr_assert_stdout_eq_str("Hello  010!");
}

Test(my_printf, str_justified_zero_precision_o, .init=redirect_stdout)
{
    my_printf("Hello %04.3o!", 64);
    cr_assert_stdout_eq_str("Hello  100!");
}

Test(my_printf, str_justified_zero_precision_b, .init=redirect_stdout)
{
    my_printf("Hello %04.3b!", 5);
    cr_assert_stdout_eq_str("Hello  101!");
}

Test(my_printf, str_justified_zero_space_d, .init=redirect_stdout)
{
    my_printf("Hello %010.4d!", 10);
    cr_assert_stdout_eq_str("Hello       0010!");
}

Test(my_printf, str_justified_zero_space_i, .init=redirect_stdout)
{
    my_printf("Hello %010.4i!", 10);
    cr_assert_stdout_eq_str("Hello       0010!");
}

Test(my_printf, str_justified_zero_space_x, .init=redirect_stdout)
{
    my_printf("Hello %010.4x!", 16);
    cr_assert_stdout_eq_str("Hello       0010!");
}

Test(my_printf, str_justified_zero_space_X, .init=redirect_stdout)
{
    my_printf("Hello %010.4X!", 16);
    cr_assert_stdout_eq_str("Hello       0010!");
}

Test(my_printf, str_justified_zero_space_o, .init=redirect_stdout)
{
    my_printf("Hello %010.4o!", 64);
    cr_assert_stdout_eq_str("Hello       0100!");
}

Test(my_printf, str_justified_zero_space_b, .init=redirect_stdout)
{
    my_printf("Hello %010.4b!", 5);
    cr_assert_stdout_eq_str("Hello       0101!");
}

Test(my_printf, str_justified_hash_d, .init=redirect_stdout)
{
    my_printf("Hello %#4d!", 10);
    cr_assert_stdout_eq_str("Hello   10!");
}

Test(my_printf, str_justified_hash_i, .init=redirect_stdout)
{
    my_printf("Hello %#4i!", 10);
    cr_assert_stdout_eq_str("Hello   10!");
}

Test(my_printf, str_justified_hash_x, .init=redirect_stdout)
{
    my_printf("Hello %#5x!", 16);
    cr_assert_stdout_eq_str("Hello  0x10!");
}

Test(my_printf, str_justified_hash_X, .init=redirect_stdout)
{
    my_printf("Hello %#5X!", 16);
    cr_assert_stdout_eq_str("Hello  0X10!");
}

Test(my_printf, str_justified_hash_o, .init=redirect_stdout)
{
    my_printf("Hello %#4o!", 16);
    cr_assert_stdout_eq_str("Hello  020!");
}

Test(my_printf, str_justified_hash_b, .init=redirect_stdout)
{
    my_printf("Hello %#4b!", 5);
    cr_assert_stdout_eq_str("Hello  101!");
}

Test(my_printf, str_justified_hash_zero_d, .init=redirect_stdout)
{
    my_printf("Hello %#04d!", 10);
    cr_assert_stdout_eq_str("Hello 0010!");
}

Test(my_printf, str_justified_hash_zero_i, .init=redirect_stdout)
{
    my_printf("Hello %#04i!", 10);
    cr_assert_stdout_eq_str("Hello 0010!");
}

Test(my_printf, str_justified_hash_zero_x, .init=redirect_stdout)
{
    my_printf("Hello %#05x!", 16);
    cr_assert_stdout_eq_str("Hello 0x010!");
}

Test(my_printf, str_justified_hash_zero_X, .init=redirect_stdout)
{
    my_printf("Hello %#05X!", 16);
    cr_assert_stdout_eq_str("Hello 0X010!");
}

Test(my_printf, str_justified_hash_zero_o, .init=redirect_stdout)
{
    my_printf("Hello %#04o!", 64);
    cr_assert_stdout_eq_str("Hello 0100!");
}

Test(my_printf, str_justified_hash_zero_b, .init=redirect_stdout)
{
    my_printf("Hello %#04b!", 5);
    cr_assert_stdout_eq_str("Hello 0101!");
}

Test(my_printf, str_justified_hash_zero_space_d, .init=redirect_stdout)
{
    my_printf("Hello %#010.4d!", 10);
    cr_assert_stdout_eq_str("Hello       0010!");
}

Test(my_printf, str_justified_hash_zero_space_i, .init=redirect_stdout)
{
    my_printf("Hello %#010.4i!", 10);
    cr_assert_stdout_eq_str("Hello       0010!");
}

Test(my_printf, str_justified_hash_zero_space_x, .init=redirect_stdout)
{
    my_printf("Hello %#010.4x!", 16);
    cr_assert_stdout_eq_str("Hello     0x0010!");
}

Test(my_printf, str_justified_hash_zero_space_X, .init=redirect_stdout)
{
    my_printf("Hello %#010.4X!", 16);
    cr_assert_stdout_eq_str("Hello     0X0010!");
}

Test(my_printf, str_justified_hash_zero_space_o, .init=redirect_stdout)
{
    my_printf("Hello %#010.4o!", 64);
    cr_assert_stdout_eq_str("Hello      00100!");
}

Test(my_printf, str_justified_hash_zero_space_b, .init=redirect_stdout)
{
    my_printf("Hello %#010.4b!", 5);
    cr_assert_stdout_eq_str("Hello       0101!");
}

Test(my_printf, str_signed_d, .init=redirect_stdout)
{
    my_printf("Hello %+d!", 10);
    cr_assert_stdout_eq_str("Hello +10!");
}

Test(my_printf, str_signed_i, .init=redirect_stdout)
{
    my_printf("Hello %+i!", 10);
    cr_assert_stdout_eq_str("Hello +10!");
}

Test(my_printf, str_signed_x, .init=redirect_stdout)
{
    my_printf("Hello %+x!", 16);
    cr_assert_stdout_eq_str("Hello 10!");
}

Test(my_printf, str_signed_X, .init=redirect_stdout)
{
    my_printf("Hello %+X!", 16);
    cr_assert_stdout_eq_str("Hello 10!");
}

Test(my_printf, str_signed_o, .init=redirect_stdout)
{
    my_printf("Hello %+o!", 64);
    cr_assert_stdout_eq_str("Hello 100!");
}

Test(my_printf, str_signed_b, .init=redirect_stdout)
{
    my_printf("Hello %+b!", 5);
    cr_assert_stdout_eq_str("Hello 101!");
}

Test(my_printf, str_signed_zero_d, .init=redirect_stdout)
{
    my_printf("Hello %+04d!", 10);
    cr_assert_stdout_eq_str("Hello +0010!");
}

Test(my_printf, str_signed_zero_i, .init=redirect_stdout)
{
    my_printf("Hello %+04i!", 10);
    cr_assert_stdout_eq_str("Hello +0010!");
}