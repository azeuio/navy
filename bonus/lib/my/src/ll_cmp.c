/*
** EPITECH PROJECT, 2021
** pushswap
** File description:
** ll_cmp
** returns the index at which the two linked list differ
** returns -1 if they are equal
*/

#include "ll.h"
#include "my.h"
#include <stddef.h>

int ll_cmp(ll_t *ll1, ll_t *ll2)
{
    int i = 0;

    if (ll1 == NULL && ll2 == NULL)
        return -1;
    if (ll1 == NULL || ll2 == NULL)
        return 0;
    while (ll1 != NULL && ll2 != NULL) {
        if (ll1->element != ll2->element) {
            return i;
        }
        ll1 = ll1->next;
        ll2 = ll2->next;
        i++;
    }
    if (ll1 == ll2)
        return -1;
    return i;
}