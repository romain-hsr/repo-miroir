/*
** EPITECH PROJECT, 2025
** len_tab.c
** File description:
** return the size of char **
*/

#include "../include/mini_shell.h"

int len_tab(char **tab)
{
    int i = 0;

    for (; tab[i] != NULL; i++)
        continue;
    return i;
}
