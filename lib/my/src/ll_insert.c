/*
** EPITECH PROJECT, 2021
** pushswap
** File description:
** ll_insert
*/

#include "ll.h"
#include <stddef.h>

ll_t *ll_insert(ll_t *ll, int element, int index)
{
    int i = 0;
    ll_t *tmp = ll;
    ll_t *new = NULL;

    if (ll == NULL && index != 0)
        return (NULL);
    else if (ll == NULL) {
        ll = ll_create(element);
        return ll;
    }
    while (tmp->next != NULL && i < (index - 1)) {
        tmp = tmp->next;
        i++;
    }
    new = ll_create(element);
    new->next = tmp->next;
    tmp->next = new;
    return ll;
}