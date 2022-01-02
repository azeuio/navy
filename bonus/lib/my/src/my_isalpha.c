/*
** EPITECH PROJECT, 2021
** libmy
** File description:
** my_isalpha
*/

int my_isalpha(char c)
{
    return (('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z'));
}