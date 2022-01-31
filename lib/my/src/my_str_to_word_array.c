/*
** EPITECH PROJECT, 2021
** str to word array
** File description:
** str input to word array
*/

#include "my.h"
#include <stdlib.h>
#include <limits.h>

static int *my_str_to_word_len_array\
(const char *str, const char *separators, int word_count)
{
    int i = 0;
    int result_idx = 0;
    int *result = malloc((word_count + 1) * sizeof(int));
    int len = my_strlen(str);

    for (i = 0; i <= word_count; i++)
        result[i] = 0;
    for (i = 0; i < len; i++) {
        if (my_strchr(separators, str[i]) != NULL) {
            result_idx++;
            continue;
        }
        result[result_idx] = result[result_idx] + 1;
    }
    result[word_count] = -1;
    return result;
}

static char **custom_return(int *word_len_array, char **return_value)
{
    if (word_len_array != NULL)
        free(word_len_array);
    return return_value;
}

static void build_word_array(\
int word_count, int *word_len_array, char ***result, const char *str)
{
    int str_idx = 0;

    for (int wrd_idx = 0; wrd_idx < word_count; wrd_idx++) {
        (*result)[wrd_idx] = malloc(sizeof(char) * \
        word_len_array[wrd_idx] + 1);
        for (int j = 0; j < word_len_array[wrd_idx]; j++) {
            (*result)[wrd_idx][j] = str[str_idx + wrd_idx];
            str_idx++;
        }
        (*result)[wrd_idx][word_len_array[wrd_idx]] = '\0';
    }
}

char **my_str_to_word_array(char const *str, const char *separators)
{
    int word_count = get_word_count(str, separators);
    int *word_len_array = NULL;
    char **result = NULL;

    word_len_array = my_str_to_word_len_array(str, separators, word_count);
    if (word_len_array[0] == -1)
        return custom_return(word_len_array, NULL);
    for (word_count = 0; word_len_array[word_count] != -1; word_count++) {
    }
    result = malloc(sizeof(char *) * (word_count + 1));
    if (result == NULL)
        return custom_return(word_len_array, NULL);
    result[word_count] = NULL;
    build_word_array(word_count, word_len_array, &result, str);
    return custom_return(word_len_array, result);
}

int my_word_array_destroy(char ***word_array)
{
    if ((*word_array) == NULL)
        return 0;
    for (int i = 0; (*word_array)[i] != NULL; i++) {
        free((*word_array)[i]);
    }
    free((*word_array));
    return 0;
}
