#include <stdlib.h>
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my_sokoban.h"
void redirect_all_std(void);

Test (freee, freee)
{
    game_t *game = malloc(sizeof(game_t));

    game->ogmap = "###\n#P#\n#X#\n#O#\n###\n\0";
    game->map = convert(game->ogmap);
    game->originalmap = convert(game->ogmap);
    init_structure(game);

    cr_assert_eq(free_struct(game), 0);
}

Test (freee, freetwo)
{
    game_t *game = malloc(sizeof(game_t));

    game->ogmap = "###\n#P#\n#X#\n#O#\n###\n\0";
    game->map = convert(game->ogmap);

    cr_assert_eq(free_struct(game), 0);
}