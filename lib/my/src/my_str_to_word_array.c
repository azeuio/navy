/*
** EPITECH PROJECT, 2021
** str to word array
** File description:
** str input to word array
*/

#include <stdlib.h>
#include "my.h"

static int is_char_at_idx_start_of_word(char const *str, int idx)
{
    if (idx == 0 && my_isalnum(str[idx]))
        return (1);
    if (my_isalnum(str[idx]) && !my_isalnum(str[idx - 1]))
        return (1);
    return (0);
}

static void add_word_to_word_array(char **array, char const *str, int *word_len)
{
    static int word_idx;

    array[word_idx] = malloc(sizeof(char) * *word_len);
    my_strncpy(array[word_idx], str, *word_len);
    *word_len = 0;
    word_idx++;
}

static void enter_number(char c, int *in_word)
{
    if (my_isalnum(c) && !*in_word)
        *in_word = 1;
}

static void add_last_word(char **array, char const *str, int *word_len, int wc)
{
    (*word_len)--;
    if ((*word_len) > 0)
        add_word_to_word_array(array, str, word_len);
    array[wc] = malloc(sizeof(NULL));
    array[wc] = NULL;
}

char **my_str_to_word_array(char const *str)
{
    int i = -1;
    int in_word = 0;
    int word_len = 0;
    int word_count = get_word_count(str);
    char **result = malloc(sizeof(char *) * (word_count + 2));

    do {
        i++;
        if (!is_char_at_idx_start_of_word(str, i) && !in_word)
            continue;
        if (!my_isalnum(str[i]) && in_word) {
            add_word_to_word_array(result, str + i - word_len, &word_len);
            in_word = 0;
        }
        enter_number(str[i], &in_word);
        if (!in_word)
            continue;
        word_len++;
    } while (str[i] != '\0');
    add_last_word(result, str + i - word_len + 1, &word_len, word_count);
    return (result);
}
