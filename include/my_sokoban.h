/*
** EPITECH PROJECT, 2022
** Base Include
** File description:
** my_sokoban
*/

#ifndef MY_SOKOBAN_H_
    #define MY_SOKOBAN_H_

    #include <ncurses.h>
    #include <string.h>
    #include <stddef.h>
    #include <unistd.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <fcntl.h>

    #define SPACE 32
    #define UP 65
    #define DOWN 66
    #define RIGHT 67
    #define LEFT 68
    #define RESIZE 410

typedef struct game {
    int x;
    int y;
    int row;
    int col;
    int boxes;
    int end;
    char **map;
    char *ogmap;
    char **originalmap;
    char previous;
} game_t;

int my_sokoban(char **av);
game_t *getmap(game_t *sokoban, char *map);
int my_strlen(char const *str);
char **convert(char *str);
int my_count_lines(char **arr);
int key_action(game_t *game, int key);
void set_targets(game_t *game, int y);
game_t *getmap(game_t *sokoban, char *map);
int my_count_col(char **arr);
int amount_items(game_t *game, char c);
int check_box(game_t *game, int x, int y);
int invalid_map(game_t *game);
int init_structure(game_t *game);
int free_struct(game_t *game);
int checkargs(int ac, char **av);
int print_map(game_t *game);

#endif /* !MY_SOKOBAN_H_ */