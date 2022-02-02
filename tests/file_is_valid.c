/*
** EPITECH PROJECT, 2022
** BTTF
** File description:
** file_is_valid
*/

#include <criterion/criterion.h>
#include <criterion/logging.h>
#include "navy.h"

Test(file_is_valid, valid_file)
{
    int got = file_is_valid("tests/boards/board_p1");

    cr_assert_eq(got, 1, "expected 1 got %d\0", got);
}

Test(file_is_valid, not_valid_file)
{
    int got = file_is_valid("Makefile");

    cr_assert_eq(got, 0, "expected 0 got %d\0", got);
}

Test(file_is_valid, empty_file)
{
    int got = file_is_valid("tests/boards/empty");

    cr_assert_eq(got, 0, "expected 0 got %d\0", got);
}

Test(file_is_valid, zero_len)
{
    int got = file_is_valid("tests/boards/bad_boat_len1");

    cr_assert_eq(got, 0, "expected 0 got %d\0", got);
}

Test(file_is_valid, negative_len)
{
    int got = file_is_valid("tests/boards/bad_boat_len2");

    cr_assert_eq(got, 0, "expected 0 got %d\0", got);
}

Test(file_is_valid, len_smaller_than_range)
{
    int got = file_is_valid("tests/boards/bad_boat_len3");

    cr_assert_eq(got, 0, "expected 0 got %d\0", got);
}

Test(file_is_valid, len_bigger_than_range)
{
    int got = file_is_valid("tests/boards/bad_boat_len4");

    cr_assert_eq(got, 0, "expected 0 got %d\0", got);
}

Test(file_is_valid, len_bigger_than_board)
{
    int got = file_is_valid("tests/boards/bad_boat_len5");

    cr_assert_eq(got, 0, "expected 0 got %d\0", got);
}

Test(file_is_valid, missing_value)
{
    int got = file_is_valid("tests/boards/bad_format1");

    cr_assert_eq(got, 0, "expected 0 got %d\0", got);
}

Test(file_is_valid, missing_separator)
{
    int got = file_is_valid("tests/boards/bad_format2");

    cr_assert_eq(got, 0, "expected 0 got %d\0", got);
}

Test(file_is_valid, wrong_separator)
{
    int got = file_is_valid("tests/boards/bad_format3");

    cr_assert_eq(got, 0, "expected 0 got %d\0", got);
}
