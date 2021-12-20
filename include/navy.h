/*
** EPITECH PROJECT, 2021
** navy
** File description:
** navy
*/

#ifndef NAVY_H_
#define NAVY_H_

typedef int** board_t;

int print_help(void);
board_t load_board(const char *filename);
void board_destroy(board_t board);
void board_draw(board_t board);

#endif /* !NAVY_H_ */
