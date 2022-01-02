/*
** EPITECH PROJECT, 2021
** libmy
** File description:
** ll_str_to_str
*/

#include <stdlib.h>
#include "my.h"
#include "ll.h"

char *ll_str_to_str(ll_str_t *ll)
{
    char temp_str[2] = {0, 0};
    char *result = malloc(sizeof(char *));

    if (ll == NULL) {
        result[0] = '\0';
        return (result);
    }
    while (ll->next != NULL) {
        temp_str[0] = ll->c;
        my_strcat(result, temp_str);
        ll = ll->next;
    }
    return (result);
}