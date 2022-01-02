/*
** EPITECH PROJECT, 2021
** my_strlen
** File description:
** Returns the lenght of a string
*/

int my_strlen(char const *str)
{
    int len = 0;

    if (str[0] == '\0')
        return (0);
    while (str[len] != '\0') {
        len++;
    }
    return (len);
}
