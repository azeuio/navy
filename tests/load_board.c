/*
** EPITECH PROJECT, 2022
** BTTF
** File description:
** load_board
*/

#include <criterion/criterion.h>
#include "navy.h"

int board_eq(board_t a, board_t b)
{
    int n_differences = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            n_differences += a[i][j] != b[i][j];
        }
    }
    return n_differences;
}

Test(load_board, file_does_not_exist)
{
    cr_assert_null(load_board("do/not/exist"));
}

Test(load_board, file_exist)
{
    cr_assert_not_null(load_board("tests/boards/bad_boat_len2"));
}

Test(load_board, good_board)
{
    board_t board = load_board("tests/boards/board_p1");
    board_t expected = create_empty_board();

    expected[0][2] = 2;
    expected[1][2] = 2;
    expected[3][3] = 3;
    expected[3][4] = 3;
    expected[3][5] = 3;
    expected[4][1] = 4;
    expected[5][1] = 4;
    expected[6][1] = 4;
    expected[7][1] = 4;
    expected[6][3] = 5;
    expected[6][4] = 5;
    expected[6][5] = 5;
    expected[6][6] = 5;
    expected[6][7] = 5;
    if (board_eq(board, expected)) {
        print_boards(&board, &expected);
        cr_assert_fail();
    }
    board_destroy(board);
}

Test(load_board, intersecting_boat)
{
    cr_assert_null(load_board("tests/boards/intersecting_boat"));
}
