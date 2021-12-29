/*
** EPITECH PROJECT, 2021
** navy
** File description:
** game
*/

#include "navy.h"
#include "my.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

static void shoot_ennemy_at\
(board_t *ennemy_board, board_t *discovered_board, int x, int y)
{
    SHOOT_AT(*ennemy_board, x, y);
    if (CELL_IS_HIT(*ennemy_board, x, y))
        (*discovered_board)[y][x] = cell_hit + 1;
    else
        (*discovered_board)[y][x] = cell_hit;
}

static void get_shooting_target_inner_loop\
(int read_size, char **input, size_t *input_size)
{
    int first_loop = 1;

    while (1) {
        if (!first_loop)
            my_printf("wrong positions\n");
        first_loop = 0;
        my_printf("attack: ");
        read_size = getline(input, input_size, stdin);
        input[read_size] = '\0';
        if (my_strcmp((*input), "quit\n") == 0) {
            (*input)[0] = -1;
            break;
        }
        if (read_size != 3)
            continue;
        if (!((*input)[0] >= 'A' && (*input)[0] <= 'H') || \
        !((*input)[1] >= '1' && (*input)[1] <= '8'))
            continue;
        break;
    }
}

static int *get_shooting_target(void)
{
    size_t input_size = 6;
    char *input = malloc(input_size);
    int read_size = -1;
    int *result = malloc(sizeof(int) * 2);

    get_shooting_target_inner_loop(read_size, &input, &input_size);
    errno = (input[0] == -1);
    result[0] = input[0] - ((input[0] == -1) ? 0 : 'A');
    result[1] = ((input[0] == -1) ? -1 : (input[1] - '1'));
    free(input);
    return result;
}

static int player1_turn(board_t *board1, board_t *board2, board_t *ennemy_board)
{
    int *xy = NULL;

    print_boards(board1, ennemy_board);
    xy = get_shooting_target();
    if (errno == 1) {
        free(xy);
        return 1;
    }
    shoot_ennemy_at(board2, ennemy_board, xy[0], xy[1]);
    send_signal(xy[0], xy[1]);
    free(xy);
    return 0;
}

void game(board_t board1, board_t board2, int curr_player)
{
    board_t ennemy_board = create_board();
    int turn = 0;
    int quit = 0;

    while (1) {
        if (!board_has_floating_ships(board1) || \
        !board_has_floating_ships(board2) || quit)
            break;
        if ((turn % 2) == (curr_player - 1)) {
            quit = player1_turn(&board1, &board2, &ennemy_board);
        } else {
            receive_signal(&board1);
        }
        if (!quit)
            my_printf("\n");
        turn++;
    }
    if (board_has_floating_ships(board1) && board_has_floating_ships(board2))
        return;
    print_boards(&board1, &ennemy_board);
    my_printf("%s won\n", board_has_floating_ships(board1) ? "I" : "Ennemy");
}