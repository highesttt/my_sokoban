/*
** EPITECH PROJECT, 2022
** Base Project file
** File description:
** my_sokoban project file
*/

#include "my_sokoban.h"

int check_player_location(game_t *game, int y)
{
    for (int x = 0; game->map[y][x] != '\0'; x++)
        if (game->map[y][x] == 'P') {
            game->y = y;
            game->x = x;
            return 1;
        }
    return 0;
}

int init_structure(game_t *game)
{
    game->row = -1;
    game->col = -1;
    game->end = -1;
    game->previous = ' ';
    for (int y = 0; game->map[y] != NULL; y++)
        if (check_player_location(game, y) == 1)
            return 1;
    return 0;
}

game_t *getmap(game_t *game, char *map)
{
    int fd = open(map, O_RDONLY);
    char *buffer = NULL;
    struct stat stats;

    if (fd < 0 || stat(map, &stats) == -1 || read(fd,
    buffer = malloc(sizeof(char) * (stats.st_size + 1)), stats.st_size) < 1) {
        game->map = NULL;
        return game;
    }
    buffer[stats.st_size] = '\0';
    close(fd);
    game->ogmap = buffer;
    game->originalmap = convert(buffer);
    game->map = convert(buffer);
    if (init_structure(game) < 1) {
        write(1, "Invalid Player Location or Boxes\n", 25);
        game->map = NULL;
        return game;
    }
    return game;
}

int print_map(game_t *game)
{
    char *too_short = "Your window is too short, resize it to play.";
    char *too_narrow = "Your window is too narrow, resize it to play.";

    for (int i = 0; game->map[i] != NULL; i++) {
        if (game->row >= my_count_lines(game->map) &&
        (game->col >= my_count_col(game->map))) {
            set_targets(game, i);
            mvprintw(((game->row) + i * 2) / 2 - my_count_lines(game->map) / 2,
            (game->col) / 2 - my_strlen(game->map[i]) / 2, "%s", game->map[i]);
        }
        if (game->row < my_count_lines(game->map))
            mvprintw(game->row / 2,  game->col / 2 - my_strlen(too_short) / 2,
            "%s", too_short);
        if (game->col < my_count_col(game->map))
            mvprintw(game->row / 2, game->col / 2 - my_strlen(too_narrow) / 2,
            "%s", too_narrow);
    }
    return 0;
}

int my_sokoban(char **av)
{
    game_t *game = malloc(sizeof(game_t));

    if (((game = getmap(game, av[1]))->map) == NULL ||
    (amount_items(game, 'X') < amount_items(game, 'O')) ||
    invalid_map(game) == 84) {
        write(1, "Invalid map\n", 12);
        return 84;
    }
    initscr();
    getmaxyx(stdscr, game->row, game->col);
    while (game->end == -1) {
        curs_set(0);
        print_map(game);
        noecho();
        key_action(game, getch());
    }
    usleep(5);
    endwin();
    free_struct(game);
    return game->end;
}
