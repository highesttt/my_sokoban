#include <stdlib.h>
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my_sokoban.h"
void redirect_all_std(void);

Test (key_action, error)
{
    int key = -1;
    game_t game;

    game.ogmap = "###\n#X#\n#P#\n# #\n###\n\0";
    game.map = convert(game.ogmap);
    init_structure(&game);
    game.previous = 'O';

    cr_assert_eq(key_action(&game, key), 84);
}

Test (key_action, up)
{
    int key = UP;
    game_t game;

    game.ogmap = "###\n#X#\n#P#\n# #\n###\n\0";
    game.map = convert(game.ogmap);
    init_structure(&game);
    game.previous = 'O';

    cr_assert_eq(key_action(&game, key), 0);
}

Test (key_action, down)
{
    int key = DOWN;
    game_t game;

    game.ogmap = "###\n#P#\n#X#\n#O#\n###\n\0";
    game.map = convert(game.ogmap);
    init_structure(&game);

    cr_assert_eq(key_action(&game, key), 0);
}

Test (key_action, right)
{
    int key = RIGHT;
    game_t game;

    game.ogmap = "######\n#P XO#\n#X   #\n#O   #\n######\n\0";
    game.map = convert(game.ogmap);
    init_structure(&game);

    cr_assert_eq(key_action(&game, key), 0);
}

Test (key_action, left)
{
    int key = LEFT;
    game_t game;

    game.ogmap = "######\n# PXO#\n#X   #\n#O   #\n######\n\0";
    game.map = convert(game.ogmap);
    init_structure(&game);

    cr_assert_eq(key_action(&game, key), 0);
}

Test (key_action, space)
{
    int key = SPACE;
    game_t game;

    game.ogmap = "######\n# PXO#\n#X   #\n#O   #\n######\n\0";
    game.map = convert(game.ogmap);
    init_structure(&game);

    cr_assert_eq(key_action(&game, key), 0);
}

Test (key_action, resize)
{
    int key = RESIZE;
    game_t game;

    game.ogmap = "######\n# PXO#\n#X   #\n#O   #\n######\n\0";
    game.map = convert(game.ogmap);
    init_structure(&game);
    game.row = 2;
    game.col = 3;

    cr_assert_eq(key_action(&game, key), 0);
}
