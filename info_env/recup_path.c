/*
** EPITECH PROJECT, 2025
** recup_path.c
** File description:
** recup all path in env for execute command
*/

#include "../include/mini_shell.h"

char *recup_path(char **env)
{
    for (int i = 0; env[i] != NULL; i++) {
        if (my_strncmp(env[i], "PATH=", 5) == 0) {
            return my_strdup(env[i] + 5);
        }
    }
    return NULL;
}
