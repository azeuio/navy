/*
** EPITECH PROJECT, 2021
** navy
** File description:
** game
*/

#include "navy.h"
#include "my.h"

static int main_loop(board_t *my, board_t *ennemy_board, int curr_player)
{
    int quit = 0;
    int turn = 0;

    while (1) {
        if (!board_has_floating_ships(*my) || quit) {
            send_signal(ennemy_pid, stop_game);
            break;
        }
        if (turn % 2 == 0)
            print_boards(my, ennemy_board);
        if ((turn % 2) == (curr_player - 1))
            quit = player1_turn(ennemy_board);
        else
            quit = player2_turn(my);
        if (!quit)
            my_printf("\n");
        turn++;
    }
    return quit;
}

void game(board_t my, int curr_player)
{
    board_t ennemy_board = create_empty_board();
    int exit_type = -1;

    my_printf("\n");
    exit_type = main_loop(&my, &ennemy_board, curr_player);
    if (exit_type != game_stopped) {
        print_boards(&my, &ennemy_board);
        my_printf("%s won\n", board_has_floating_ships(my) ? "I" : "Ennemy");
    }
    board_destroy(ennemy_board);
    board_destroy(my);
}