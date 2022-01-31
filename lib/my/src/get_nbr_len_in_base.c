/*
** EPITECH PROJECT, 2021
** get_nbr_len_in_base
** File description:
** returns len of nbr using base
** ex : 12 base 10 = 2
** 12 base 16 (C) = 1
*/

#include "my.h"

int get_nbr_len_in_base(int nbr, int const base)
{
    int i = 0;
    int len = 1;

    if (nbr == 0)
        return (1);
    while (1) {
        nbr = nbr / base;
        if (nbr != 0) {
            len++;
            i++;
        } else {
            return (len);
        }
    }
}

int get_nbr_len_in_base_unsigned(unsigned long long nbr, int const base)
{
    int i = 0;
    int len = 1;

    if (nbr == 0)
        return (1);
    while (1) {
        nbr = nbr / base;
        if (nbr != 0) {
            len++;
            i++;
        } else {
            return (len);
        }
    }
}
