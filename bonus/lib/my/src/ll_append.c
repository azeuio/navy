/*
** EPITECH PROJECT, 2021
** pushswap
** File description:
** ll_append
*/

#include "ll.h"
#include <stddef.h>

ll_t *ll_append(ll_t *ll, int element)
{
    ll_t *tmp;

    if (ll == NULL) {
        return ll_create(element);
    }
    tmp = ll;
    while (tmp->next != NULL) {
        tmp = tmp->next;
    }
    tmp->next = ll_create(element);
    return ll;
}