/*
** EPITECH PROJECT, 2021
** libmy
** File description:
** put_ll_str
*/

#include <stdlib.h>
#include "ll.h"
#include "my.h"

void put_ll_str(ll_str_t *str)
{
    while (str->next != NULL) {
        my_putchar(str->c);
        str = str->next;
    }
}