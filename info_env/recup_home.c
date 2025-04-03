/*
** EPITECH PROJECT, 2025
** recup_home.c
** File description:
** recup the path of home
*/

#include "../include/mini_shell.h"

char *recup_home(char **env)
{
    for (int i = 0; env[i] != NULL; i++) {
        if (my_strncmp(env[i], "HOME=", 5) == 0) {
            return my_strdup(env[i] + 5);
        }
    }
    return NULL;
}
