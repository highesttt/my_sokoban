/*
** EPITECH PROJECT, 2022
** B-PSU-200-BDX-2-1-mysokoban-killian1.lelong [WSL: Manjaro]
** File description:
** check_args
*/

#include "my_sokoban.h"

int checkargs(int ac, char **av)
{
    if (ac == 2)
        if (av[1][0] == '-' && av[1][1] == 'h')
            write(1, "USAGE\n./my_sokoban map\n\nDESCRIPTION\nmap file \
representing the warehouse map, containing '#' for walls, 'P' for \
the player, 'X' for boxes and 'O' for storage locations.\n", 168);
    if (ac != 2)
        return 84;
    return 0;
}
