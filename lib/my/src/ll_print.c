/*
** EPITECH PROJECT, 2021
** pushswap
** File description:
** ll_print
*/

#include "ll.h"
#include "my.h"
#include <stddef.h>

void ll_print(ll_t *ll)
{
    ll_t *tmp = ll;

    my_printf("(");
    while (tmp != NULL) {
        my_printf("%d, ", tmp->element);
        tmp = tmp->next;
    }
    my_printf(")\n");
}