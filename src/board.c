/*
** EPITECH PROJECT, 2021
** navy
** File description:
** load a board with load_board(const char *filename)
** destroy a board with board_destroy(board_t board)
*/

#include "navy.h"
#include "my.h"
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>

static board_t create_board(void)
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

static int is_line_valid(char *line)
{
    if (my_strlen(line) < 6)
        return 0;
    if (!(my_isalpha(line[1]) && line[1] < ('A' + 8) && \
    my_isnum(line[2]) && (line[3]) == ':' && \
    my_isalpha(line[4]) && (line[4]) < ('A' + 8) && \
    my_isnum(line[5]) && \
    (line[6] == '\n' || line[6] == '\0')))
        return 0;
    return 1;
}

static int is_file_valid(FILE *file)
{
    size_t bufsize = 1024;
    char *buffer = malloc(sizeof(char) * bufsize);
    int read_size = 0;
    int i = 0;
    int verdict = 1;

    if (file == NULL) {
        free(buffer);
        return 0;
    }
    read_size = getline(&buffer, &bufsize, file);
    buffer[read_size] = '\0';
    while (read_size != -1 && verdict == 1) {
        for (i = 0; buffer[i] != ':'; i++) {
            if (!my_isnum(buffer[i]))
                verdict = 0;
        }
        if (my_strlen(buffer + i) >= 7 && buffer[read_size - 1] != '\n')
            return 0;
        if (!is_line_valid(buffer + i))
            verdict = 0;
        read_size = getline(&buffer, &bufsize, file);
        buffer[read_size] = '\0';
    }
    fclose(file);
    return verdict;
}

board_t load_board(const char *filename)
{
    board_t board = create_board();
    FILE *file = fopen(filename, "r");
    size_t bufsize = 1024;
    char *buffer = malloc(sizeof(char) * bufsize);
    int read_size = 0;
    int i = 0;
    int is_vertical = 0;
    int ship_size = 0;

    if (!is_file_valid(fopen(filename, "r")))
        return NULL;
    read_size = getline(&buffer, &bufsize, file);
    while (read_size > 0) {
        for (i = 0; buffer[i] != ':'; i++) {
        }
        is_vertical = buffer[i + 2] == buffer[i + 5];
        ship_size = my_getnbr(buffer);
        for (int j = 0; j < ship_size; j++) {
            board[buffer[i + 2] - '1' + j * !is_vertical]\
            [buffer[i + 1] - 'A' + j * is_vertical] = ship_size;
        }
        read_size = getline(&buffer, &bufsize, file);
    }
    return board;
}


void board_destroy(board_t board)
{
    for (int i = 0; i < 8; i++) {
        free(board[i]);
    }
    free(board);
}