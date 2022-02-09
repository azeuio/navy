/*
** EPITECH PROJECT, 2022
** navy
** File description:
** line_is_valid
*/

#include "my.h"

static int len_is_valid(char val)
{
    if (!my_isnum(val))
        return 0;
    if (!('1' <= val && val <= '8'))
        return 0;
    return 1;
}

static int pos_is_valid(char *pos)
{
    if (!(my_isalpha(pos[0]) && my_isnum(pos[1])))
        return 0;
    if (!('A' <= pos[0] && pos[0] <= 'H'))
        return 0;
    if (!('1' <= pos[1] && pos[1] <= '8'))
        return 0;
    return 1;
}

static int boat_of_len_can_be_added(int len, unsigned char *boats_in_board)
{
    if (!(2 <= len && len <= 5))
        return 0;
    if ((*boats_in_board) & (1 << (len - 2)))
        return 0;
    (*boats_in_board) |= (1 << (len - 2));
    return 1;
}

int line_is_valid(char *line, int len, unsigned char *boats_in_board)
{
    if (!(len == 7 || len == 8))
        return 0;
    if (!(len_is_valid(line[0]) && line[1] == ':'))
        return 0;
    if (!(pos_is_valid(line + 2) && line[4] == ':'))
        return 0;
    if (!(pos_is_valid(line + 5)))
        return 0;
    if (!(line[7] == '\n' || line[7] == '\0'))
        return 0;
    if ((line[0] - '0') != (ABS(line[3] - line[6]) + 1)) {
        if ((line[0] - '0') != (ABS(line[2] - line[5]) + 1))
            return 0;
    }
    if (!(line[2] == line[5] || line[3] == line[6]))
        return 0;
    if (!boat_of_len_can_be_added(line[0] - '0', boats_in_board)) {
        my_printf("hi");
        return 0;
    }
    return 1;
}