/*
** EPITECH PROJECT, 2021
** pushswap
** File description:
** ll_destroy
*/

#include "ll.h"
#include <stddef.h>
#include <stdlib.h>

int ll_destroy(ll_t *ll)
{
    ll_t *tmp;

    while (ll != NULL) {
        tmp = ll;
        ll = ll->next;
        free(tmp);
    }
    return 0;
}