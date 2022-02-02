/*
** EPITECH PROJECT, 2022
** BTTF
** File description:
** load_board
*/

#include <criterion/criterion.h>
#include "navy.h"

Test(bad_boat_len, don_t_crash)
{
    load_board("tests/boards/bad_boat_len1");
    load_board("tests/boards/bad_boat_len2");
    load_board("tests/boards/bad_boat_len3");
    load_board("tests/boards/bad_boat_len4");
    load_board("tests/boards/bad_boat_len5");
}

Test(bad_boat_len, zero_len)
{
    cr_assert_null(load_board("tests/boards/bad_boat_len1"));
}

Test(bad_boat_len, negative_len)
{
    cr_assert_null(load_board("tests/boards/bad_boat_len2"));
}

Test(bad_boat_len, len_smaller_than_range)
{
    cr_assert_null(load_board("tests/boards/bad_boat_len3"));
}

Test(bad_boat_len, len_bigger_than_range)
{
    cr_assert_null(load_board("tests/boards/bad_boat_len4"));
}

Test(bad_boat_len, len_bigger_than_board)
{
    cr_assert_null(load_board("tests/boards/bad_boat_len5"));
}

Test(format, missing_value)
{
    cr_assert_null(load_board("tests/boards/bad_format1"));
}

Test(format, missing_separator)
{
    cr_assert_null(load_board("tests/boards/bad_format2"));
}

Test(format, wrong_separator)
{
    cr_assert_null(load_board("tests/boards/bad_format3"));
}

Test(format, empty)
{
    cr_assert_null(load_board("tests/boards/empty"));
}
