/*
** EPITECH PROJECT, 2021
** my_is_prime
** File description:
** Is n a prime number ?
*/

int my_is_prime(int nb)
{
    int testn = 0;

    if (nb < 2)
        return (0);
    for (int i = 2; i < nb / 2 + 1; i++) {
        testn = nb / i;
        if (testn * i == nb) {
            return (0);
        }
    }
    return (1);
}
