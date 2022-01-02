/*
** EPITECH PROJECT, 2021
** pushswap
** File description:
** ll_create
*/

#include "ll.h"
#include <stdlib.h>
#include <stddef.h>

ll_t *ll_create(int element)
{
    ll_t *ll = malloc(sizeof(ll_t));

    ll->next = NULL;
    ll->element = element;
    return ll;
}