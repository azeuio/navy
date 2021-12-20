/*
** EPITECH PROJECT, 2021
** my_swap
** File description:
** Swap the content of two integer given their addresses
*/

void my_swap(int *a, int *b)
{
    int temp = *a;

    *a = *b;
    *b = temp;
}
