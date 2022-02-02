/*
** EPITECH PROJECT, 2021
** navy
** File description:
** game
*/

#include "navy.h"
#include "my.h"

static int main_loop(board_t *my, board_t *enemy_board, int curr_player)
{
    int quit = 0;
    int turn = 0;

    while (1) {
        if (!board_has_floating_ships(*my) || quit) {
            send_signal(enemy_pid, stop_game);
            break;
        }
        if (turn % 2 == 0)
            print_boards(my, enemy_board);
        if ((turn % 2) == (curr_player - 1))
            quit = my_turn(enemy_board);
        else
            quit = other_player_turn(my);
        if (!quit)
            my_printf("\n");
        turn++;
    }
    return quit;
}

void game(board_t my, int curr_player)
{
    board_t enemy_board = create_empty_board();
    int exit_type = -1;

    my_printf("\n");
    exit_type = main_loop(&my, &enemy_board, curr_player);
    if (exit_type != game_stopped) {
        print_boards(&my, &enemy_board);
        my_printf("%s won\n", (exit_type == game_won) ? "I" : "Enemy");
    }
    board_destroy(enemy_board);
    board_destroy(my);
}
