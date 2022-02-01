/*
** EPITECH PROJECT, 2021
** navy
** File description:
** my_turn
*/

#include "navy.h"
#include "my.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

static int shoot_enemy_at(board_t *discovered_board, int x, int y)
{
    int shot_landed = 0;
    send_signal(enemy_pid, x);
    send_signal(enemy_pid, y);
    shot_landed = receive_signal();
    if (shot_landed)
        (*discovered_board)[y][x] = cell_hit + 1;
    else
        (*discovered_board)[y][x] = cell_hit;
    my_printf("%c%d: %s\n", 'A' + x, y + 1, shot_landed ? "hit" : "missed");
    return (shot_landed == game_lost);
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
        input[read_size - 1] = '\0';
        if (my_strcmp((*input), "quit\n") == 0) {
            (*input)[0] = -1;
            break;
        }
        if (read_size != 3)
            continue;
        if (!((*input)[0] >= 'A' && (*input)[0] <= 'H') ||
        !((*input)[1] >= '1' && (*input)[1] <= '8'))
            continue;
        break;
    }
}

static int *get_shooting_target(void)
{
    size_t input_size = 2048;
    char *input = malloc(input_size);
    int read_size = -1;
    int *result = NULL;

    get_shooting_target_inner_loop(read_size, &input, &input_size);
    result = malloc(sizeof(int) * 2);
    errno = (input[0] == -1);
    result[0] = input[0] - 'A';
    result[1] = input[1] - '1';
    free(input);
    return result;
}

int my_turn(board_t *enemy_board)
{
    int *xy = NULL;
    int game_has_ended = 0;

    xy = get_shooting_target();
    if (errno == 1) {
        send_signal(enemy_pid, stop_game);
        free(xy);
        return game_stopped;
    }
    game_has_ended = shoot_enemy_at(enemy_board, xy[0], xy[1]);
    free(xy);
    return game_has_ended * (int)game_won;
}

int other_player_turn(board_t *my)
{
    int x = 0;
    int y = 0;
    int shot_landed = 0;

    my_printf("waiting for enemy's attack...\n");
    x = receive_signal();
    if (x == stop_game) {
        return game_stopped;
    }
    y = receive_signal();
    SHOOT_AT(*my, x, y);
    shot_landed = CELL_IS_HIT(*my, x, y);
    my_printf("%c%d: %s\n", 'A' + x, y + 1,
    (shot_landed ? "hit" : "missed"));
    send_signal(enemy_pid, shot_landed +
    !board_has_floating_ships(*my));
    return 0;
}