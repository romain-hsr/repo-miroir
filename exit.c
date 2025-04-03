/*
** EPITECH PROJECT, 2025
** exit.c
** File description:
** free all function
*/

#include "include/mini_shell.h"

void free_tab(char **tab)
{
    for (int i = 0; tab[i] != NULL; i++) {
        free(tab[i]);
    }
    free(tab);
}
