/*
** EPITECH PROJECT, 2021
** find prime sup
** File description:
** Find closest superior prime to n
*/

#include "my.h"

int my_find_prime_sup(int nb)
{
    if (nb < 2)
        return (2);
    while (1) {
        if (my_is_prime(nb) == 1)
            return (nb);
        nb++;
    }
}
