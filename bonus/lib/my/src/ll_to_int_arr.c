/*
** EPITECH PROJECT, 2021
** libmy
** File description:
** ll_create_from_in_arr
*/

#include <stdlib.h>
#include "my.h"
#include "ll.h"

int *ll_to_int_arr(ll_t *ll)
{
    int *result = malloc(sizeof(int) * (get_ll_len(ll) + 1));
    int i = 0;

    if (ll == NULL) {
        return (result);
    }
    while (ll->next != NULL) {
        result[i] = ll->element;
        ll = ll->next;
    }
    return (result);
}