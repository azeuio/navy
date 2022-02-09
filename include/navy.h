/*
** EPITECH PROJECT, 2021
** navy
** File description:
** navy
*/

#pragma once

extern int enemy_pid;

typedef int **board_t;

enum cell_state {
    cell_empty = 0,
    cell_hit = 16,
};

enum exit_type {
    game_won = 1,
    game_lost = 2,
    game_stopped = 3,
    stop_game = 10,
};

#define SHOOT_AT(board, x, y) ((board)[(y)][(x)] |= cell_hit)
#define CELL_IS_HIT(board, x, y) ((board)[(y)][(x)] > cell_hit)
#define CELL_IS_MISSED(board, x, y) ((board)[(y)][(x)] == cell_hit)
#define CELL_HAS_SHIP(board, x, y) \
((board)[(y)][(x)] < cell_hit && (board)[(y)][(x)] > cell_empty)

int print_help(void);
int av_contains(const char **av, const char *str);
int handle_args_error(const int ac, const char **av);
int file_is_valid(const char *filename);
int is_coord_valid(char x, char y, board_t board);

int game(board_t my, int curr_player);

int my_turn(board_t *enemy_board);
int other_player_turn(board_t *my);

int counter(int sig);

board_t create_empty_board(void);
board_t load_board(const char *filename);
void board_destroy(board_t board);
void board_draw(board_t board);
void print_boards(board_t *my, board_t *enemy_board);
int board_has_ships(board_t board);
int board_has_floating_ships(board_t board);

void send_signal(int destination, int n);
int receive_signal(void);
int wait_for_connection(void);
int connect_to(int destination);
int send_position(int x, int y);
int *receive_position(board_t *board);
