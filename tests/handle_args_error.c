/*
** EPITECH PROJECT, 2022
** BTTF
** File description:
** handle_arg_error
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "navy.h"

const char *good_av_p1[3] = {
    "./navy",
    "tests/boards/board_p1",
    NULL,
};

const char *good_av_p2[3] = {
    "./navy",
    "tests/boards/board_p2",
    NULL,
};

const char *wrong_av_not_enough[2] = {
    "./navy",
    NULL,
};

const char *wrong_av_too_many[6] = {
    "./navy",
    "a",
    "a",
    "a",
    "a",
    NULL,
};

const char *wrong_filepath[3] = {
    "./navy",
    "does/not/exist",
    NULL,
};

const char *wrong_filepath_dir[3] = {
    "./navy",
    "src/",
    NULL,
};

Test(handle_arg_error, not_enough_arguments, .init=cr_redirect_stdout)
{
    cr_assert_eq(handle_args_error(1, wrong_av_not_enough), 1);
}

Test(handle_arg_error, too_many_arguments, .init=cr_redirect_stdout)
{
    cr_assert_eq(handle_args_error(4, wrong_av_too_many), 1);
}

Test(handle_arg_error, good_arguments_p1, .init=cr_redirect_stdout)
{
    cr_assert_eq(handle_args_error(2, good_av_p1), 0);
}

Test(handle_arg_error, good_arguments_p2, .init=cr_redirect_stdout)
{
    cr_assert_eq(handle_args_error(2, good_av_p2), 0);
}

Test(handle_arg_error, wrong_filepath, .init=cr_redirect_stdout)
{
    cr_assert_eq(handle_args_error(3, wrong_filepath), 1);
}

Test(handle_arg_error, wrong_filepath_dir, .init=cr_redirect_stdout)
{
    cr_assert_eq(handle_args_error(3, wrong_filepath_dir), 1);
}
