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

    cr_assert_eq(got, 0, "expected 1 got %d\0", got);
}
