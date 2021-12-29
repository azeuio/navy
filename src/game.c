/*
** EPITECH PROJECT, 2021
** navy
** File description:
** game
*/

#include "navy.h"
#include "my.h"

static void main_loop(board_t *my, board_t *ennemy_board, int curr_player)
{
    int quit = 0;
    int turn = 0;
    int x = 0;
    int y = 0;
    int shot_landed = 0;

    while (1) {
        if (!board_has_floating_ships(*my) || quit) {
            send_signal(ennemy_pid, 10);
            break;
        }
        if ((turn % 2) == (curr_player - 1)) {
            quit = player1_turn(my, ennemy_board);
            if (quit)
                continue;
        } else {
            my_printf("waiting for enemy’s attack...\n");
            x = receive_signal();
            if (x == 10) {
                quit = 1;
                continue;
            }
            y = receive_signal();
            SHOOT_AT(*my, x, y);
            shot_landed = CELL_IS_HIT(*my, x, y);
            my_printf("%c%d: %s\n", 'A' + x, y + 1, \
            (shot_landed ? "hit" : "missed"));
            send_signal(ennemy_pid, shot_landed + \
            !board_has_floating_ships(*my));
        }
        if (!quit)
            my_printf("\n");
        turn++;
    }
}

void game(board_t my, int curr_player)
{
    board_t ennemy_board = create_board();

    my_printf("\n");
    if (curr_player == 2)
        print_boards(&my, &ennemy_board);
    main_loop(&my, &ennemy_board, curr_player);
    print_boards(&my, &ennemy_board);
    my_printf("%s won\n", board_has_floating_ships(my) ? "I" : "Ennemy");
    board_destroy(ennemy_board);
}