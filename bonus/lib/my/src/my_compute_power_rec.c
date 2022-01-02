/*
** EPITECH PROJECT, 2021
** power rec
** File description:
** n to the power of p recursivly
*/

int my_compute_power_rec(int n, int p)
{
    if (p == 0)
        return (1);
    if (p < 0)
        return (0);
    return (n * my_compute_power_rec(n, p - 1));
}
