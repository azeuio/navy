/*
** EPITECH PROJECT, 2021
** navy
** File description:
** signals
*/

#include "navy.h"
#include "my.h"

int send_signal(int x, int y)
{
    return 0;
}

int *receive_signal(board_t *board)
{
    my_printf("waiting for enemy’s attack...\n");
    SHOOT_AT(*board, 0, 0);
    my_printf("%c%c: %s\n", 'A', '1', \
    CELL_IS_HIT(*board, 0, 0) ? "hit" : "missed");
    return (int[2]){0, 0};
}