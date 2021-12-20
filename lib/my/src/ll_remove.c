/*
** EPITECH PROJECT, 2021
** pushswap
** File description:
** ll_remove
*/

#include "ll.h"
#include <stddef.h>

int ll_remove(ll_t *ll, int index)
{
    int i = 0;

    if (ll == NULL)
        return 1;
    while (ll->next != NULL && i < index) {
        ll = ll->next;
        i++;
    }
    if (i != index || ll->next == NULL)
        return 1;
    ll->next = ll->next->next;
    return 0;
}