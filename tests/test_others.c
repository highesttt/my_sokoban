/*
** EPITECH PROJECT, 2022
** B-CPE-110-BDX-1-1-antman-killian1.lelong [WSL: Ubuntu]
** File description:
** test_antman
*/

#include <stdlib.h>
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my_sokoban.h"
void redirect_all_std(void);

Test (my_strlen, my_strlen)
{
    cr_assert_eq(my_strlen("Never Gonna Give You Up"), 23);
}

Test (printmap, printmap)
{
    game_t game;

    game.ogmap = "###\n#P#\n#X#\n#O#\n###\n\0";
    game.map = convert(game.ogmap);
    init_structure(&game);

    cr_assert_eq(print_map(&game), 0);
}

Test (playerlocation, playerloc)
{
    game_t game;

    game.ogmap = "######\n# PXO#\n#X   #\n#O   #\n######\n\0";
    game.map = convert(game.ogmap);
    init_structure(&game);
    cr_assert_eq (game.x , 2);
    cr_assert_eq(game.y , 1);
}

Test (settargets, player)
{
    game_t game;

    game.ogmap = "######\n# PXO#\n#X   #\n#P   #\n######\n\0";
    game.map = convert(game.ogmap);
    game.originalmap = convert(game.ogmap);
    init_structure(&game);
    game.ogmap = "######\n#  XO#\n#X   #\n#O   #\n######\n\0";
    game.originalmap = convert(game.ogmap);
    set_targets(&game, 3);
    cr_assert_eq(game.previous, 'O');
}

Test (settargets, settargets)
{
    game_t game;

    game.ogmap = "######\n# PXO#\n#X   #\n#    #\n######\n\0";
    game.map = convert(game.ogmap);
    game.originalmap = convert(game.ogmap);
    init_structure(&game);
    game.ogmap = "######\n#  XO#\n#X   #\n#O   #\n######\n\0";
    game.originalmap = convert(game.ogmap);
    set_targets(&game, 3);
    cr_assert_eq(game.map[3][1], 'O');
}
