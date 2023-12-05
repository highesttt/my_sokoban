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
    #define W 119
    #define A 97
    #define S 115
    #define D 100
    #define H 104
    #define P 112
    #define Q 113
    #define UP 65
    #define DOWN 66
    #define RIGHT 67
    #define LEFT 68
    #define RESIZE 410

typedef struct game {
    int x;
    int y;
    int moves;
    int row;
    int col;
    int boxes;
    int hogwarts;
    int debug;
    int end;
    char **map;
    char **originalmap;
    char *ogmap;
    char previous;
} game_t;

int my_sokoban(char **av);
game_t *getmap(game_t *sokoban, char *map);
int my_strlen(char const *str);
char **convert(char *str);
int my_count_lines(char **arr);
int key_action(game_t *game);
game_t *getmap(game_t *sokoban, char *map);
int my_count_col(char **arr);
int amount_items(game_t *game, char c);
int check_box(game_t *game, int x, int y);
int invalid_map(game_t *game);
int init_structure(game_t *game);
void set_targets(game_t *game, int y);
void free_struct(game_t *game);

#endif /* !MY_SOKOBAN_H_ */