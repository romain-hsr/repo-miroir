/*
** EPITECH PROJECT, 2025
** print_env.c
** File description:
** display env
*/

#include "../include/mini_shell.h"

void print_env(char **env)
{
    int i = 0;

    while (env[i] != NULL) {
        my_putstr(env[i]);
        my_putchar('\n');
        i++;
    }
}
