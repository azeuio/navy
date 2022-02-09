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
    unsigned char boats_in_board = 0;

    if (file == NULL) {
        return close_and_return(0, file, buffer);
    }
    read_size = getline(&buffer, &zero, file);
    if (my_strlen(buffer) == 0)
        return close_and_return(0, file, buffer);
    while (read_size != -1 && buffer != NULL) {
        if (!line_is_valid(buffer, read_size, &boats_in_board))
            return close_and_return(0, file, buffer);
        free(buffer);
        buffer = NULL;
        zero = 0;
        read_size = getline(&buffer, &zero, file);
    }
    return close_and_return(boats_in_board == 0b1111, file, buffer);
}
