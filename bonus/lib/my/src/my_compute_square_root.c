/*
** EPITECH PROJECT, 2021
** sqrt
** File description:
** math
*/

int my_compute_square_root(int n)
{
    int root = 0;
    int squarred = 0;

    while (squarred < n) {
        root++;
        squarred = root * root;
        if (squarred == n)
            return (root);
    }
    return (0);
}
