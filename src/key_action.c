/*
** EPITECH PROJECT, 2022
** B-PSU-200-BDX-2-1-mysokoban-killian1.lelong [WSL: Manjaro]
** File description:
** key_action
*/

#include "my_sokoban.h"

static void check_lose(game_t *game)
{
    int lost = 0;

    for (int y = 0; game->map[y] != NULL; y++)
        for (int x = 0; game->map[y][x] != '\0'; x++)
            game->map[y][x] == 'X' ? (lost = lost + check_box(game, x, y)) :
            (lost = lost);
    if (amount_items(game, 'X') == lost)
        game->end = 1;
    return;
}

static void check_win(game_t *game)
{
    int targets = 0;

    check_lose(game);
    for (int y = 0; game->map[y] != NULL; y++)
        for (int x = 0; game->map[y][x] != '\0'; x++)
            game->map[y][x] == 'O' ? (targets++) : (targets = targets);
    if (targets == 0 && game->previous != 'O')
        game->end = 0;
}

static void move_player(game_t *game, int locy, int locx)
{
    if ((locy == -1 && game->y - 1 <= 1
    && game->map[game->y + locy][game->x + locx] == 'X')
    || (game->map[game->y + locy * 2][game->x + locx * 2] == '#' &&
    game->map[game->y + locy][game->x + locx] == 'X') ||
    (game->map[game->y + locy * 2][game->x + locx * 2] == '\0' &&
    game->map[game->y + locy][game->x + locx] == 'X') ||
    (game->map[game->y + locy * 2][game->x + locx * 2] == 'X' &&
    game->map[game->y + locy][game->x + locx] == 'X'))
        return;
    game->map[game->y][game->x] = game->previous;
    game->previous = game->map[game->y + locy][game->x + locx];
    game->map[game->y + locy][game->x + locx] = 'P';
    game->x = game->x + locx;
    game->y = game->y + locy;
    if (game->previous == 'X') {
        game->previous = ' ';
        game->map[game->y + locy][game->x + locx] = 'X';
    }
}

static void check_movement(game_t *game, int key)
{
    if ((key == UP) && game->map[game->y - 1][game->x] != '#'
    && game->y - 1 >= 1)
        move_player(game, -1, 0);
    if ((key == DOWN) && game->map[game->y + 1][game->x] != '#'
    && game->map[game->y + 2] != NULL)
        move_player(game, 1, 0);
    if ((key == RIGHT) && game->map[game->y][game->x + 1] != '#'
    && game->map[game->y][game->x + 1] != '\0')
        move_player(game, 0, 1);
    if ((key == LEFT) && game->map[game->y][game->x - 1] != '#'
    && game->x - 1 != -1)
        move_player(game, 0, -1);
    check_win(game);
    return;
}

int key_action(game_t *game, int key)
{
    if (key == -1)
        return 84;
    check_movement(game, key);
    if (key == SPACE) {
        game->map = convert(game->ogmap);
        init_structure(game);
        wclear(stdscr);
        getmaxyx(stdscr, game->row, game->col);
    }
    if (key == RESIZE) {
        wclear(stdscr);
        getmaxyx(stdscr, game->row, game->col);
    }
    return 0;
}
