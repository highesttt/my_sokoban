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
    if (game->debug == 1)
        mvprintw(16, 2, "LOST BOXES: %d ", lost);
    if (amount_items(game, 'X') - lost < amount_items(game, 'O'))
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
    if (game->previous == 'O')
        targets++;
    if (game->debug == 1)
        mvprintw(18, 2, "TARGETS LEFT: %d  ", targets);
    if (targets == 0)
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
    game->moves++;
}

static void check_movement(game_t *game, int key)
{
    if ((key == UP || key == W) &&
    ((game->hogwarts == 0 && game->map[game->y - 1][game->x] != '#')
    || (game->hogwarts == 1)) && game->y - 1 >= 1)
        move_player(game, -1, 0);
    if ((key == DOWN || key == S) &&
    ((game->hogwarts == 0 && game->map[game->y + 1][game->x] != '#')
    || (game->hogwarts == 1)) && game->map[game->y + 2] != NULL)
        move_player(game, 1, 0);
    if ((key == RIGHT || key == D) &&
    ((game->hogwarts == 0 && game->map[game->y][game->x + 1] != '#')
    || (game->hogwarts == 1)) && game->map[game->y][game->x + 1] != '\0')
        move_player(game, 0, 1);
    if ((key == LEFT || key == A) &&
    ((game->hogwarts == 0 && game->map[game->y][game->x - 1] != '#')
    || (game->hogwarts == 1)) && game->x - 1 != -1)
        move_player(game, 0, -1);
    check_win(game);
    return;
}

static void debug_menu(game_t *game, int key)
{
    if (key == P && game->debug == 1) {
        game->debug = 0;
        mvprintw(10, 2, "                            ");
        mvprintw(12, 2, "                      ");
        mvprintw(14, 2, "                 ");
        mvprintw(16, 2, "                 ");
        mvprintw(18, 2, "                 ");
    } else if (key == P && game->debug == 0) {
        game->debug = 1;
        mvprintw(10, 2, "Move to show debug menu");
        return;
    }
    if (game->debug == 1) {
        mvprintw(10, 2, "PREVIOUS BLOCK (ASCII): %d  ", game->previous);
        mvprintw(12, 2, "HOGWARTS MODE: %s ", game->hogwarts == 1 ?
        "True" : "False");
        mvprintw(14, 2, "KEY PRESSED: %d  ", key);
    }
}

int key_action(game_t *game)
{
    int key = getch();

    if (key == -1)
        exit(84);
    check_movement(game, key);
    if (key == SPACE) {
        game->map = convert(game->ogmap);
        init_structure(game);
        wclear(stdscr);
        game->moves = 0;
        getmaxyx(stdscr, game->row, game->col);
    }
    if (key == RESIZE) {
        wclear(stdscr);
        getmaxyx(stdscr, game->row, game->col);
    }
    if (key == Q)
        game->end = 2;
    if (key == H && game->hogwarts == 1)
        game->hogwarts = 0;
    else if (key == H && game->hogwarts == 0)
        game->hogwarts = 1;
    debug_menu(game, key);
    return 0;
}
