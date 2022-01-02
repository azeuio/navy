/*
** EPITECH PROJECT, 2021
** navy
** File description:
** board_draw
*/

#include "navy.h"
#include "my.h"

static char print_ship(int x, int y, board_t board)
{
    if (board[y][x] == cell_empty) {
        my_printf("\33[34m");
        return '.';
    }
    if (CELL_IS_MISSED(board, x, y)) {
        my_printf("\33[33m");
        return 'o';
    }
    if (CELL_IS_HIT(board, x, y)) {
        my_printf("\33[1;31m");
        return 'x';
    }
    my_printf("\33[1;37m");
    return '0' + board[y][x];
}

static void print_grid(int x, int y, board_t board)
{
    char lookup[256] = "01234-6789AB- EF H-bcdef|hI|K+MNOP";
    enum idx {nothing, y0 = 3, y1 = 5, x0 = 7, x1 = 11, xmod2 = 13};
    char to_print;

    to_print = lookup[((y == 0) * y0 + (x == 0) * x0 + (y == 1) * y1 + \
    (x == 1) * x1 + (x % 2) * xmod2) % my_strlen(lookup)];
    if (to_print == '|' || to_print == '-' || to_print == '+')
        my_printf("\33[2;32m");
    if (to_print == '7' || to_print == '3')
        my_printf("\33[1;32m");
    if (to_print == '7')
        to_print = '0' + (y - 1);
    if (to_print == '3')
        to_print = 'A' + x / 2 - 1;
    if (to_print == '@')
        to_print = '3';
    if (x == 0 && y == 0)
        to_print = ' ';
    if (to_print == '0')
        to_print = print_ship((x - 2) / 2, y - 2, board);
    my_printf("%c\33[0m", to_print);
}

void board_draw(board_t board)
{
    for (int y = 0; y < (8 + 2); y++) {
        for (int x = 0; x < (8 * 2 + 2); x++) {
            print_grid(x, y, board);
        }
        my_printf("\n");
    }
}

void print_boards(board_t *my, board_t *ennemy_board)
{
    my_printf("my positions:\n");
    board_draw(*my);
    my_printf("\nennemy's positions:\n");
    board_draw(*ennemy_board);
    my_printf("\n");
}