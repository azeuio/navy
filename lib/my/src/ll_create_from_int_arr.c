/*
** EPITECH PROJECT, 2021
** libmy
** File description:
** convert string array to linked list
*/

#include <stdlib.h>
#include "ll.h"
#include "my.h"

ll_t *ll_create_from_int_arr(int const *int_arr, int size)
{
    ll_t *result = NULL;
    ll_t *tmp;

    if (int_arr == NULL || size == 0)
        return (NULL);
    result = ll_create(int_arr[0]);
    tmp = result;
    for (int i = 1; i < size; i++) {
        tmp->next = ll_create(int_arr[i]);
        tmp = tmp->next;
    }
    tmp->next = NULL;
    return (result);
}
