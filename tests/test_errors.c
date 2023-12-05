#include <stdlib.h>
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my_sokoban.h"

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}


Test (error_management, basic)
{
    char *av[] = {
        "./my_sokoban",
        NULL
    };
    cr_assert_eq(checkargs(1, av), 84);
}

Test (error_management, help)
{
    char *av[] = {
        "./my_sokoban",
        "-h",
        NULL
    };
    cr_assert_eq(checkargs(2, av), 0);
}

Test (error_management, wtf)
{
    char *av[] = {
        "./my_sokoban",
        "-q",
        NULL
    };
    cr_assert_eq(checkargs(2, av), 0);
}

Test (error_management, wtftwo)
{
    char *av[] = {
        "./my_sokoban",
        "ah",
        NULL
    };
    cr_assert_eq(checkargs(2, av), 0);
}

Test (invalidmap, invalidmap)
{
    game_t game;

    game.ogmap = "######\n# PXO#\n#XP  #\n#O   #\n######\n\0";
    game.map = convert(game.ogmap);
    init_structure(&game);
    cr_assert_eq(invalid_map(&game), 84);
}

Test (invalidmap, invalidmaptwo)
{
    game_t game;

    game.ogmap = "######\n# PXO#\n#X.X #\n#O   #\n######\n\0";
    game.map = convert(game.ogmap);
    init_structure(&game);
    cr_assert_eq(invalid_map(&game), 84);
}

Test (invalidmap, validmap)
{
    game_t game;

    game.ogmap = "######\n# PXO#\n#X   #\n#O   #\n######\n\0";
    game.map = convert(game.ogmap);
    init_structure(&game);
    cr_assert_eq(invalid_map(&game), 0);
}


Test (mysokoban, noplayers)
{
    char *av[] = {
        "./my_sokoban",
        "tests/map",
        NULL
    };
    cr_assert_eq(my_sokoban(av), 84);
}


Test (mysokoban, moretargets)
{
    char *av[] = {
        "./my_sokoban",
        "tests/map2",
        NULL
    };
    cr_assert_eq(my_sokoban(av), 84);
}


Test (mysokoban, invalidchars)
{
    char *av[] = {
        "./my_sokoban",
        "tests/map3",
        NULL
    };
    cr_assert_eq(my_sokoban(av), 84);
}


Test (mysokoban, invalidmap)
{
    char *av[] = {
        "./my_sokoban",
        "tests/map5",
        NULL
    };
    cr_assert_eq(my_sokoban(av), 84);
}

