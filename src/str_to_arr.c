/*
** EPITECH PROJECT, 2022
** B-PSU-200-BDX-2-1-mysokoban-killian1.lelong [WSL: Manjaro]
** File description:
** str_to_arr
*/

#include "my_sokoban.h"

static int line_count(char *str)
{
    int i = 0;
    int i2 = 0;

    while (str[i] != '\0') {
        if (str[i] == '\n') {
            i2++;
        }
        i++;
    }
    i2++;
    return i2;
}

static int col_count(char *str)
{
    int i = 0;

    while (str[i] != '\n') {
        i++;
    }
    return i;
}

static char **fill_array(char *src, char **dest)
{
    int i = 0;
    int x = 0;
    int y = 0;

    while (src[i] != '\0') {
        if ((src[i] == '\n')) {
            dest[x][y] = '\0';
            y = 0;
            x++;
        } else {
            dest[x][y] = src[i];
            y++;
        }
        i++;
    }
    if ((src[i] == '\0') && (src[i - 1] != '\n'))
        dest[x][y] = '\0';
    return dest;
}

char **convert(char *str)
{
    int columns = col_count(str);
    int lines = line_count(str);
    char **arr = malloc(sizeof(char *) * (lines + 1));

    for (int i2 = 0; i2 <= lines; i2++)
        arr[i2] = malloc((columns + 1) * sizeof(char));
    arr[lines + 1] = NULL;
    for (int i = 0; arr[i] != NULL; i++)
        for (int j = 0; j <= columns; j++)
            arr[i][j] = '\0';
    fill_array(str, arr);
    return arr;
}
