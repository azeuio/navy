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

static void load_line(board_t *board, char *line)
{
    int is_vertical = 0;
    int ship_size = 0;
    int i = 0;

    for (i = 0; line[i] != ':'; i++) {
    }
    is_vertical = line[i + 2] == line[i + 5];
    ship_size = my_getnbr(line);
    for (int j = 0; j < ship_size; j++) {
        (*board)[line[i + 2] - '1' + j * !is_vertical]\
        [line[i + 1] - 'A' + j * is_vertical] = ship_size;
    }
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
    while (read_size > 0) {
        read_size = getline(&buffer, &bufsize, file);
        load_line(&board, buffer);
        read_size = getline(&buffer, &bufsize, file);
    }
    free(buffer);
    fclose(file);
    return board;
}

void board_destroy(board_t board)
{
    for (int i = 0; i < 8; i++) {
        free(board[i]);
    }
    free(board);
}