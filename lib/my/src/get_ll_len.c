/*
** EPITECH PROJECT, 2021
** libmy
** File description:
** get_ll_str_len
*/

#include <stdlib.h>
#include "ll.h"

int get_ll_len(ll_t const *ll)
{
    int len = 0;

    if (ll == NULL)
        return (0);
    while (ll != NULL) {
        len++;
        ll = ll->next;
    }
    return (len);
}