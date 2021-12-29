/*
** EPITECH PROJECT, 2021
** navy
** File description:
** game
*/

#include "navy.h"
#include "my.h"

static void main_loop
(board_t *my, board_t *ennemy_board, board_t *discovered_board, int curr_player)
{
    int quit = 0;
    int turn = 0;

    while (1) {
        if (!board_has_floating_ships(*my) || \
        !board_has_floating_ships(*ennemy_board) || quit)
            break;
        if ((turn % 2) == (curr_player - 1)) {
            quit = player1_turn(my, ennemy_board, discovered_board);
        } else {
            receive_signal(my);
        }
        if (!quit)
            my_printf("\n");
        turn++;
    }
}

void game(board_t board1, board_t board2, int curr_player)
{
    board_t ennemy_board = create_board();
    int turn = 0;
    int quit = 0;

    main_loop(&board1, &board2, &ennemy_board, curr_player);
    if (board_has_floating_ships(board1) && board_has_floating_ships(board2)) {
        board_destroy(ennemy_board);
        return;
    }
    print_boards(&board1, &ennemy_board);
    my_printf("%s won\n", board_has_floating_ships(board1) ? "I" : "Ennemy");
    board_destroy(ennemy_board);
}