/*
** EPITECH PROJECT, 2022
** B-PSU-200-BDX-2-1-mysokoban-killian1.lelong [WSL: Manjaro]
** File description:
** free
*/

#include "my_sokoban.h"

int free_struct(game_t *game)
{
    int i = 0;

    if (game->originalmap) {
        for (; game->originalmap[i] != NULL; i++)
            free(game->originalmap[i]);
        free(game->originalmap);
    }
    if (game->map) {
        for (; game->map[i] != NULL; i++)
            free(game->map[i]);
        free(game->map);
    }
    return 0;
}
