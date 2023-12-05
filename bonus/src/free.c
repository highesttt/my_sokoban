/*
** EPITECH PROJECT, 2022
** B-PSU-200-BDX-2-1-mysokoban-killian1.lelong [WSL: Manjaro]
** File description:
** free
*/

#include "my_sokoban.h"

void free_struct(game_t *game)
{
    int i = 0;

    for (; game->map[i] != NULL; i++)
        free(game->map[i]);
    free(game->map);
    free(game->ogmap);
}
