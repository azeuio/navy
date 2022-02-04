/*
** EPITECH PROJECT, 2022
** BTTF
** File description:
** file_is_valid
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <stdlib.h>
#include "navy.h"
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

static int line_is_valid(char *line, int len)
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
    return 1;
}

static int close_and_return(int return_value,
FILE *file_to_close, void *to_free)
{
    if (file_to_close != NULL)
        fclose(file_to_close);
    if (to_free != NULL)
        free(to_free);
    return return_value;
}

int file_is_valid(const char *filename)
{
    size_t zero = 0;
    FILE *file = fopen(filename, "r");
    char *buffer = NULL;
    ssize_t read_size;

    if (file == NULL) {
        return close_and_return(0, file, buffer);
    }
    read_size = getline(&buffer, &zero, file);
    if (my_strlen(buffer) == 0)
        return close_and_return(0, file, buffer);
    while (read_size != -1 && buffer != NULL) {
        if (!line_is_valid(buffer, read_size)) {
            return close_and_return(0, file, buffer);
        }
        free(buffer);
        buffer = NULL;
        zero = 0;
        read_size = getline(&buffer, &zero, file);
    }
    return close_and_return(1, file, buffer);
}
