/*
** EPITECH PROJECT, 2021
** libmy
** File description:
** convert string array to linked list
*/

#include <stdlib.h>
#include "ll.h"
#include "my.h"

ll_str_t *str_to_ll(char const *str)
{
    int i = 0;
    ll_str_t *result = malloc(sizeof(ll_str_t *));
    ll_str_t *temp = malloc(sizeof(ll_str_t *));

    if (str[0] == '\0') {
        return (NULL);
    }
    result->c = '\0';
    result->next = temp;
    temp->next = NULL;
    while (str[i] != '\0') {
        temp->c = str[i];
        temp->next = malloc(sizeof(ll_str_t *));
        temp = temp->next;
        temp->next = NULL;
        i++;
    }
    return (result->next);
}