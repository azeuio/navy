/*
** EPITECH PROJECT, 2021
** navy
** File description:
** navy
*/

#ifndef NAVY_H_
#define NAVY_H_

extern int ennemy_pid;

typedef int** board_t;

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

// void game(board_t board1, board_t board2, int curr_player);
void game(board_t my, int curr_player);

// int player1_turn(board_t *board1, board_t *board2, board_t *ennemy_board);
int player1_turn(board_t *board1, board_t *ennemy_board);

void signal_handler(int sig);

board_t create_board(void);
board_t load_board(const char *filename);
void board_destroy(board_t board);
void board_draw(board_t board);
void print_boards(board_t *my, board_t *ennemy_board);
int board_has_ships(board_t board);
int board_has_floating_ships(board_t board);

void send_signal(int destination, int n);
int receive_signal(void);
int get_connection(void);
int connect_to(int destination, int pid);
int send_position(int x, int y);
int *receive_position(board_t *board);

#endif /* !NAVY_H_ */
