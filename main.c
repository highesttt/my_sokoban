/*
** EPITECH PROJECT, 2022
** Base Main
** File description:
** my_sokoban main file
*/

#include "my_sokoban.h"

int main(int ac, char **av)
{
    if (checkargs(ac, av) == 84)
        return 84;
    return my_sokoban(av);
}
