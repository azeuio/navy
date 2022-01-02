/*
** EPITECH PROJECT, 2021
** libmy
** File description:
** my_isalnum
*/

#include "my.h"

int my_isalnum(char c)
{
    return (my_isalpha(c) || my_islower(c));
}