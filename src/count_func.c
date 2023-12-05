/*
** EPITECH PROJECT, 2021
** count_function
** File description:
** returns the length of a string, counts lines and columns of an array
*/

#include <stddef.h>

int my_strlen(char const *str)
{
    int i = 0;

    if (str == NULL)
        return 0;
    while (str[i] != '\0')
        i++;
    return i;
}

int my_count_lines(char **arr)
{
    int y = 0;

    if (arr == NULL)
        return -1;
    for (y = 0; arr[y] != NULL; y++);
    return y;
}

int my_count_col(char **arr)
{
    int y = 0;

    if (arr == NULL)
        return -1;
    for (y = 0; arr[0][y] != '\0'; y++);
    return y;
}
