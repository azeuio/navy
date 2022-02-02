/*
** EPITECH PROJECT, 2022
** BTTF
** File description:
** load_board
*/

#include <criterion/criterion.h>
#include "navy.h"

Test(load_board, file_does_not_exist)
{
    cr_assert_null(load_board("do/not/exist"));
}

Test(load_board, file_exist)
{
    cr_assert_not_null(load_board("tests/boards/bad_boat_len2"));
}
