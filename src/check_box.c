/*
** EPITECH PROJECT, 2022
** B-PSU-200-BDX-2-1-mysokoban-killian1.lelong [WSL: Manjaro]
** File description:
** check_box
*/

#include "my_sokoban.h"

int amount_items(game_t *game, char c)
{
    int targets = 0;

    for (int y = 0; game->map[y] != NULL; y++)
        for (int x = 0; game->map[y][x] != '\0'; x++)
            game->map[y][x] == c ? (targets++) : (targets = targets);
    return targets;
}

int check_box(game_t *game, int x, int y)
{
    int walls = 0;

    if (game->map[y + 1][x] == '#')
        walls = walls + 1000;
    if (game->map[y][x + 1] == '#')
        walls = walls + 100;
    if (game->map[y - 1][x] == '#')
        walls = walls + 10;
    if (game->map[y][x - 1] == '#')
        walls++;
    if (walls == 11 || walls == 110 || walls == 111 || walls == 1100 ||
    walls == 1001 || walls == 1110 || walls == 1011 || walls == 1101)
        return 1;
    return 0;
}

int invalid_map(game_t *game)
{
    int invalid = 0;
    int players = 0;

    for (int y = 0; game->map[y] != NULL; y++)
        for (int x = 0; game->map[y][x] != '\0'; x++)
            (game->map[y][x] != '#' && game->map[y][x] != 'O' &&
            game->map[y][x] != 'X' && game->map[y][x] != ' ' &&
            game->map[y][x] != 'P') ? (invalid++) : (invalid = invalid);
    for (int y = 0; game->map[y] != NULL; y++)
        for (int x = 0; game->map[y][x] != '\0'; x++)
            (game->map[y][x] == 'P') ? (players++) : (players = players);
    if (invalid > 0 || players != 1)
        return 84;
    return 0;
}

void set_targets(game_t *game, int y)
{
    for (int x = 0; game->map[y][x] != '\0'; x++) {
        if (game->map[y][x] == ' ' && game->originalmap[y][x] == 'O')
            game->map[y][x] = 'O';
        if (game->map[y][x] == 'P' && game->originalmap[y][x] == 'O')
            game->previous = 'O';
    }
}
