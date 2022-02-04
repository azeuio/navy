/*
** EPITECH PROJECT, 2021
** navy
** File description:
** board
*/

#include "navy.h"
#include "my.h"
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>

board_t create_empty_board(void)
{
    board_t board = malloc(sizeof(int *) * 8);

    for (int i = 0; i < 8; i++) {
        board[i] = malloc(sizeof(int) * 8);
        for (int j = 0; j < 8; j++) {
            board[i][j] = 0;
        }
    }
    return board;
}

static int load_line(board_t *board, char *line)
{
    int is_vertical = 0;
    int ship_size = 0;
    int y = 0;
    int x = 0;

    is_vertical = line[3] == line[6];
    ship_size = line[0] - '0';
    for (int i = 0; i < ship_size; i++) {
        x = line[2] - 'A' + i * is_vertical;
        y = line[3] - '1' + i * !is_vertical;
        if ((*board)[y][x] != 0)
            return 1;
        (*board)[y][x] = ship_size;
    }
    return 0;
}

static board_t free_close_and_return(
void *to_free, FILE *to_close, board_t to_return)
{
    if (to_free != NULL)
        free(to_free);
    if (to_close != NULL)
        fclose(to_close);
    return to_return;
}

board_t load_board(const char *filename)
{
    board_t board = create_empty_board();
    FILE *file = fopen(filename, "r");
    size_t bufsize = 1024;
    char *buffer = NULL;
    int read_size = 0;

    if (file == NULL)
        return NULL;
    buffer = malloc(sizeof(char) * bufsize);
    read_size = getline(&buffer, &bufsize, file);
    while (read_size != EOF) {
        if (load_line(&board, buffer))
            return free_close_and_return(buffer, file, NULL);
        read_size = getline(&buffer, &bufsize, file);
    }
    return free_close_and_return(buffer, file, board);
}

void board_destroy(board_t board)
{
    for (int i = 0; i < 8; i++) {
        free(board[i]);
    }
    free(board);
}
