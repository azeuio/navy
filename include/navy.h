/*
** EPITECH PROJECT, 2021
** navy
** File description:
** navy
*/

#ifndef NAVY_H_
#define NAVY_H_

typedef int** board_t;
#include <limits.h>

enum cell_state {
    cell_empty = 0,
    cell_hit = 16,
};

#define SHOOT_AT(board, x, y) ((board)[(y)][(x)] |= cell_hit)
#define CELL_IS_HIT(board, x, y) ((board)[(y)][(x)] > cell_hit)
#define CELL_IS_MISSED(board, x, y) ((board)[(y)][(x)] == cell_hit)

int print_help(void);
board_t load_board(const char *filename);
void board_destroy(board_t board);
void board_draw(board_t board);

#endif /* !NAVY_H_ */
