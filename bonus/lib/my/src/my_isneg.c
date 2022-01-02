/*
** EPITECH PROJECT, 2021
** my_isneg
** File description:
** Displays 'N' if input is negative, 'P' if it is positive
*/

#include "my.h"

int my_isneg(int n)
{
    my_putchar((n < 0) ? 'N' : 'P');
    return (n < 0);
}
