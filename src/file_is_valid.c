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

static int line_is_valid(char *line, int len)
{
    if (!(len == 7 || len == 8))
        return 0;
    if (!(my_isnum(line[0]) && line[1] == ':'))
        return 0;
    if (!(my_isalpha(line[2]) && my_isnum(line[3]) && line[4] == ':'))
        return 0;
    if (!(my_isalpha(line[5]) && my_isnum(line[6])))
        return 0;
    if (!(line[7] == '\n' || line[7] == '\0'))
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