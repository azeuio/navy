/*
** EPITECH PROJECT, 2021
** navy
** File description:
** print_help
*/

#include "my.h"

int print_help(void)
{
    my_printf("USAGE\n");
    my_printf("\t./navy [first_player_pid] navy_positions\n");
    my_printf("  IN GAME\n");
    my_printf("\tA1 ~ H8\tshoot at this position\v\r");
    my_printf("\tquit\tquit the game\n");
    my_printf("DESCRIPTION\n");
    my_printf("\tfirst_player_pid: only for the 2nd player. ");
    my_printf("pid of the first player.\n");
    my_printf("\tnavy_positions: ");
    my_printf("file representing the positions of the ships.\n");
    my_printf("\t                ");
    my_printf("(In that file, any line that does not match the ");
    my_printf("intended format will be ignored)\n");
    return 0;
}
