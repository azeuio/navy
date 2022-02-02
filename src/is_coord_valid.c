/*
** EPITECH PROJECT, 2022
** BTTF
** File description:
** is_coord_valid
*/

#include <stddef.h>
#include "navy.h"

int is_coord_valid(char x, char y, board_t board)
{
    if (!('A' <= x && x <= 'H'))
        return 0;
    if (!('1' <= y && y <= '8'))
        return 0;
    if (board != NULL) {
        if (board[y - '1'][x - 'A'] != cell_empty)
            return 0;
    }
    return 1;
}