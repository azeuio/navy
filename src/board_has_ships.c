/*
** EPITECH PROJECT, 2021
** navy
** File description:
** board_has_ships
*/

#include "navy.h"
#include "my.h"

int board_has_ships(board_t board)
{
    int board_has_ships = 0;

    for (int y = 0; y < 8; y++) {
        for (int x = 0; x < 8; x++) {
            board_has_ships += CELL_HAS_SHIP(board, x, y);
        }
    }
    return board_has_ships > 0;
}

int board_has_floating_ships(board_t board)
{
    int board_has_ships = 0;

    for (int y = 0; y < 8; y++) {
        for (int x = 0; x < 8; x++) {
            board_has_ships +=
            CELL_HAS_SHIP(board, x, y) * !CELL_IS_HIT(board, x, y);
        }
    }
    return board_has_ships > 0;
}
